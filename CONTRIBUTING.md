# Contributing

## Developer responsibilities

GitHub does not check these, so authors and reviewers must. Listed in workflow order:

1. **Issue first:** every change starts from an issue with exactly one type label (see [Labels](#labels))
2. **Branch from the issue:** created through the issue's Development panel, so it is named `<issue-number>-<issue-title>`
3. **Local tests:** unit tests pass locally before asking for review
4. **Pull request:** one per issue, titled like the issue since the title becomes the squash commit message, and described with `.github/pull_request_template.md`

## Enforced by GitHub

Set in Settings -> General -> Pull Requests, or in a ruleset on `main` (Settings -> Rules -> Rulesets):

- **Pull request required:** no direct pushes to `main` (ruleset)
- **Required status check:** the unit test CI job must pass before merging (ruleset). It can only be turned on once a CI workflow exists in `.github/workflows/`
- **Squash merging only:** merge commits and rebase merging are disabled (settings)
- **Squash commit message:** defaults to the PR title, and GitHub appends `(#<PR number>)` (settings)
- **Automatically delete head branches:** the branch is deleted after merge (settings)

## Labels

- **feature:** Addition or improvement of a feature
- **bug:** Something isn't working
- **doc:** Improvements or additions to documentation
- **task:** No codebase change, task on project management
- **question:** Further information is requested
