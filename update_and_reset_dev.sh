#!/bin/bash
set -e  # Stop if any command fails

BRANCH="dev"
COMMIT_MSG="Reset branch to clean state"

# 1. Switch to dev branch
git checkout $BRANCH

# 2. Find and update all requirements.txt files
echo "Updating requirements files..."
find . -name "requirements.txt" | while read file; do
    echo "Updating $file..."
    sed -i.bak -E \
        -e 's/(certifi[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\12022.12.07/' \
        -e 's/(requests[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\12.31.0/' \
        -e 's/(Pygments[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\12.15.0/' \
        -e 's/(urllib3[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\11.26.17/' \
        -e 's/([jJ]inja2[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\13.1.4/' \
        -e 's/(MarkupSafe[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\12.1.5/' \
        -e 's/(idna[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\13.7/' \
        -e 's/(zipp[[:space:]]*==?[[:space:]]*)([0-9]+\.[0-9]+\.[0-9]+)/\13.19.1/' \
        "$file"
    rm -f "$file.bak"
done       

# 3. Install updated dependencies
echo "Installing updated dependencies..."
find . -name "requirements.txt" | while read file; do
    pip install --upgrade -r "$file"
done

# 4. Commit changes
git add .
git commit -m "$COMMIT_MSG"

# 5. Remove all history and keep only this commit
echo "Resetting branch history..."
git checkout --orphan temp_branch
git commit -m "$COMMIT_MSG"
git branch -M $BRANCH
git push origin $BRANCH --force

echo "✅ Branch '$BRANCH' reset and pushed with security updates."
