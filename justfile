default:
    @just --list

update message:
    git add .
    git commit -m "{{message}}"
    git cliff -o CHANGELOG.md
    git add .
    git commit --amend --no-edit
