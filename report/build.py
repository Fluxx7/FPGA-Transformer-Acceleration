#!/usr/bin/env python3
"""
Build script for the MQP report.

Concatenates report/[0-9]*.md sections in order, pre-renders any Mermaid
diagram code blocks to PNG using mmdc, then converts the result to a Word
document via pandoc.

Usage:
    python report/build.py [options]

Run from the project root directory.
"""

import argparse
import glob
import hashlib
import os
import re
import shutil
import subprocess
import sys
import tempfile


SECTION_GLOB = "report/[0-9]*.md"
FIGURES_DIR = "report/figures/generated"
REFERENCE_DOC = "context/Armstrong (MQP report).docx"
DEFAULT_OUTPUT = "report/output/Nicholas_Armstrong_MQP.docx"

MERMAID_BLOCK_RE = re.compile(
    r"```mermaid\n(.*?)```",
    re.DOTALL,
)


def die(msg):
    print(f"ERROR: {msg}", file=sys.stderr)
    sys.exit(1)


def check_dependency(cmd, install_hint):
    if shutil.which(cmd) is None:
        die(f"'{cmd}' not found. {install_hint}")


def render_mermaid(diagram_src, out_path):
    """Render a Mermaid diagram string to a PNG file using mmdc."""
    with tempfile.NamedTemporaryFile(suffix=".mmd", mode="w", delete=False) as f:
        f.write(diagram_src)
        tmp = f.name
    try:
        result = subprocess.run(
            ["mmdc", "-i", tmp, "-o", out_path, "--backgroundColor", "white"],
            capture_output=True,
            text=True,
        )
        if result.returncode != 0:
            die(f"mmdc failed rendering diagram to {out_path}:\n{result.stderr}")
    finally:
        os.unlink(tmp)


IMAGE_RE = re.compile(r"!\[(.*?)\]\((.+?)\)")


def resolve_image_paths(content, section_path):
    """Rewrite relative image paths to be relative to the project root.

    Section files live in report/ and use paths like ../schematic.svg.
    After concatenation, pandoc resolves paths from the temp file location,
    so we normalise everything to project-root-relative paths here.
    """
    section_dir = os.path.dirname(os.path.abspath(section_path))

    def fix(match):
        alt, src = match.group(1), match.group(2)
        if src.startswith("http://") or src.startswith("https://"):
            return match.group(0)
        abs_path = os.path.normpath(os.path.join(section_dir, src))
        rel_path = os.path.relpath(abs_path)
        return f"![{alt}]({rel_path})"

    return IMAGE_RE.sub(fix, content)


def process_section(path, figures_dir, render_mermaid_blocks):
    """Read a section file, replace Mermaid blocks with image references."""
    with open(path) as f:
        content = f.read()

    content = resolve_image_paths(content, path)

    if not render_mermaid_blocks:
        return content

    def replace_block(match):
        src = match.group(1)
        # Use a hash of the diagram source as a stable filename.
        digest = hashlib.sha1(src.encode()).hexdigest()[:10]
        section_name = os.path.splitext(os.path.basename(path))[0]
        png_name = f"{section_name}_{digest}.png"
        png_path = os.path.join(figures_dir, png_name)

        print(f"  Rendering Mermaid diagram -> {png_path}")
        render_mermaid(src, png_path)

        # Use absolute path so pandoc can find the image regardless of
        # where the temp markdown file is written.
        abs_path = os.path.abspath(png_path).replace("\\", "/")
        return f"![]({abs_path})"

    return MERMAID_BLOCK_RE.sub(replace_block, content)


def warn_missing_figures(combined):
    """Print warnings for image references whose files don't exist yet."""
    for match in re.finditer(r"!\[.*?\]\((.+?)\)", combined):
        path = match.group(1)
        if not os.path.exists(path):
            print(f"  WARNING: referenced figure not found: {path}")


def build(args):
    # --- Dependency checks ---
    check_dependency("pandoc", "Install with: brew install pandoc")
    has_mmdc = shutil.which("mmdc") is not None

    # --- Collect sections ---
    sections = sorted(glob.glob(SECTION_GLOB))
    if not sections:
        die(f"No section files matched '{SECTION_GLOB}'. Run from project root.")
    print(f"Found {len(sections)} sections:")
    for s in sections:
        print(f"  {s}")

    # --- Mermaid pre-render ---
    any_mermaid = any(
        "```mermaid" in open(s).read() for s in sections
    )
    render = any_mermaid and not args.no_mermaid
    if any_mermaid and not has_mmdc and not args.no_mermaid:
        die(
            "'mmdc' not found but Mermaid diagrams are present.\n"
            "Install with: npm install -g @mermaid-js/mermaid-cli\n"
            "Or skip rendering with: --no-mermaid"
        )
    if render:
        os.makedirs(FIGURES_DIR, exist_ok=True)
        print(f"\nRendering Mermaid diagrams to {FIGURES_DIR}/")

    # --- Process and concatenate ---
    print("\nProcessing sections...")
    parts = []
    for section in sections:
        processed = process_section(section, FIGURES_DIR, render)
        parts.append(processed)

    combined = "\n\n".join(parts)

    # --- Warn about missing figures ---
    print("\nChecking figure references...")
    warn_missing_figures(combined)

    # --- Write combined markdown to temp file ---
    with tempfile.NamedTemporaryFile(
        suffix=".md", mode="w", delete=False, encoding="utf-8"
    ) as f:
        f.write(combined)
        tmp_md = f.name

    # --- Run pandoc ---
    output = args.output
    os.makedirs(os.path.dirname(output), exist_ok=True)

    pandoc_cmd = ["pandoc", tmp_md, "-o", output]

    if args.reference_doc:
        if os.path.exists(REFERENCE_DOC):
            pandoc_cmd += [f"--reference-doc={REFERENCE_DOC}"]
            print(f"\nUsing reference doc: {REFERENCE_DOC}")
        else:
            print(f"\nWARNING: Reference doc not found: {REFERENCE_DOC}")
            print("  Output will use pandoc default styles.")

    # Standard metadata and formatting options
    pandoc_cmd += [
        "--standalone",
        "--toc",
        "--toc-depth=3",
        "-V", "toc-title=Table of Contents",
    ]

    print(f"\nRunning pandoc...")
    result = subprocess.run(pandoc_cmd, capture_output=True, text=True)
    os.unlink(tmp_md)

    if result.returncode != 0:
        die(f"pandoc failed:\n{result.stderr}")

    if result.stderr:
        print(result.stderr, file=sys.stderr)

    print(f"\nDone: {output}")


def main():
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "-o", "--output",
        default=DEFAULT_OUTPUT,
        metavar="FILE",
        help=f"Output file path (default: {DEFAULT_OUTPUT})",
    )
    parser.add_argument(
        "--no-mermaid",
        action="store_true",
        help="Skip Mermaid diagram rendering (use if mmdc is not installed)",
    )
    parser.add_argument(
        "--reference-doc",
        action="store_true",
        help=f"Apply {REFERENCE_DOC} as the pandoc style template (off by default)",
    )
    args = parser.parse_args()
    build(args)


if __name__ == "__main__":
    main()
