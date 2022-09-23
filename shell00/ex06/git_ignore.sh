# find . -type f | git check-ignore --stdin
git ls-files --ignored --exclude-standard -o
