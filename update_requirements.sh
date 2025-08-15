#!/bin/bash

# Secure versions
declare -A packages=(
  ["certifi"]="2022.12.7"
  ["requests"]="2.31.0"
  ["Pygments"]="2.15.0"
  ["urllib3"]="1.26.17"
  ["jinja2"]="3.1.3"
  ["idna"]="3.7"
  ["Jinja2"]="3.1.4"
  ["zipp"]="3.19.1"
)

# Find all requirements.txt files
files=$(find . -name "requirements.txt")

for file in $files; do
  echo "Updating $file..."
  for pkg in "${!packages[@]}"; do
    # Use '' after -i for macOS (BSD sed)
    sed -E -i '' "s/^(${pkg}==)[0-9.]+/\1${packages[$pkg]}/I" "$file"
  done
done

echo "✅ All versions updated."
echo "Now run:"
echo "pip install --upgrade -r requirements.txt"
