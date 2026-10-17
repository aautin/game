---
name: general
description: >
  General repository-operation and Git safety rules for the agent.
  Use this skill for every task that inspects or modifies a repository, regardless of language.
---

# General agent workflow

Apply these rules to every repository task. They protect the user's current work and make the
starting repository state recoverable.

## Repository startup

1. **G.1 — Inspect before acting.** At the beginning of a repository task, run `git status`,
   `git diff`, `git diff --cached`, and relevant `git show` commands before editing files.
2. **G.2 — Stage the complete baseline before editing.** Before the first modification, run
   `git add -A` from the repository root so tracked changes, new files, and deletions are all
   included in the saved baseline.
3. **G.3 — Verify the baseline.** After staging, run `git status` and inspect the staged summary
   with `git diff --cached --stat` and `git diff --cached --name-status`. Do not start editing
   until the complete current state is accounted for.
4. **G.4 — Preserve the staged baseline.** Treat the index as the snapshot of the repository
   state that existed immediately before the agent's edits. Do not reset, unstage, overwrite, or
   discard it during the task.
5. **G.5 — Do not restore pre-existing work.** Once the baseline is staged, do not remove, revert,
   clean, or rewrite files merely to return them to `HEAD`. Existing user changes are intentional
   unless the user explicitly asks otherwise.

## Editing and validation

1. **G.6 — Edit after staging.** Modify files only after the complete baseline has been staged and
   verified.
2. **G.7 — Keep agent changes distinguishable.** Leave the baseline in the index and let new
   modifications appear as the working-tree diff. Do not use broad staging commands again unless
   the user explicitly requests a new snapshot.
3. **G.8 — Review both states.** Use `git diff` for agent working-tree changes and
   `git diff --cached` for the saved baseline. Use `git show` to inspect committed history when
   historical context is needed.
4. **G.9 — Validate the requested result.** Run the smallest relevant formatter, linter, build, or
   test after editing, and report failures plainly.
5. **G.10 — Avoid unrelated cleanup.** Do not reformat, delete, rename, or otherwise alter files
   outside the requested scope.

## Git permissions

1. **G.11 — No commits by default.** The agent is not authorized to create, amend, or rewrite
   commits unless the user explicitly requests that exact action.
2. **G.12 — No remote operations by default.** The agent is not authorized to push, pull, fetch,
   merge, rebase, cherry-pick, or otherwise change local or remote history unless the user
   explicitly requests the exact operation.
3. **G.13 — Do not treat staging as commit authorization.** Staging the baseline is a safety
   requirement only; it never authorizes a commit, push, pull, or history rewrite.
4. **G.14 — Ask before irreversible operations.** If a task appears to require destructive deletion,
   reset, clean, checkout, history rewriting, or remote synchronization, stop and request explicit
   authorization.
5. **G.15 — Read-only Git inspection is allowed.** `git status`, `git diff`, `git diff --cached`,
   `git show`, `git log`, and similar read-only commands may be used freely for inspection.

## Completion

1. **G.16 — Do not silently commit or stage final edits.** Leave the agent's final changes visible
   in the working tree unless the user explicitly asks for staging or committing them.
2. **G.17 — Report repository state accurately.** State whether changes are unstaged, staged,
   committed, or blocked, and never claim persistence beyond what Git actually shows.
