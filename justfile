default:
    @just --list

update message:
    git add .
    git commit -m "{{message}}"
    git cliff -o CHANGELOG.md
    git add .
    git commit --amend --no-edit

tag message version:
    git add .
    git commit -m "{{message}}"
    git cliff -o CHANGELOG.md
    git add .
    git commit --amend --no-edit
    git tag -a {{version}} -m "{{message}}"

push:
    git push origin main --follow-tags