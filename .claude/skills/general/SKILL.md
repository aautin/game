---
name: general
description: >
  General repository-operation and Git safety rules for the agent.
  Use this skill for every task that inspects or modifies a repository, regardless of language.
---

# General agent workflow

Apply these rules to every repository task. They protect the user's current work and keep the
agent's changes easy to review.

## Repository startup

1. **G.1 — Inspect before acting.** At the beginning of a repository task, run `git status`,
   `git diff`, `git diff --cached`, and relevant `git show` commands before editing files.
2. **G.2 — Do not restore pre-existing work.** Do not remove, revert, clean, or rewrite files
   merely to return them to `HEAD`. Existing user changes are intentional unless the user
   explicitly asks otherwise.

## Editing and validation

1. **G.3 — Leave the index to the user.** Never run `git add`, `git restore --staged`, `git reset`,
   or any other command that changes the index unless the user explicitly asks for it. What the
   user staged stays staged; what they did not stage stays unstaged.
2. **G.4 — Review agent changes in the working tree.** The agent's edits appear in `git diff`
   (against the index) on top of whatever the user staged, which `git diff --cached` shows. Use
   `git show` to inspect committed history when historical context is needed.
3. **G.5 — Validate the requested result.** Run the smallest relevant formatter, linter, build, or
   test after editing, and report failures plainly.
4. **G.6 — Avoid unrelated cleanup.** Do not reformat, delete, rename, or otherwise alter files
   outside the requested scope.

## Git permissions

1. **G.7 — No commits by default.** The agent is not authorized to create, amend, or rewrite
   commits unless the user explicitly requests that exact action.
2. **G.8 — No remote operations by default.** The agent is not authorized to push, pull, fetch,
   merge, rebase, cherry-pick, or otherwise change local or remote history unless the user
   explicitly requests the exact operation.
3. **G.9 — Ask before irreversible operations.** If a task appears to require destructive deletion,
   reset, clean, checkout, history rewriting, or remote synchronization, stop and request explicit
   authorization.
4. **G.10 — Read-only Git inspection is allowed.** `git status`, `git diff`, `git diff --cached`,
   `git show`, `git log`, and similar read-only commands may be used freely for inspection.

## Completion

1. **G.11 — Report repository state accurately.** State whether changes are unstaged, staged,
   committed, or blocked, and never claim persistence beyond what Git actually shows.
