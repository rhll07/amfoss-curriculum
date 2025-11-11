# 🧠 Learning Git: My Journey Through the amFOSS Anveshan 2025!

## 🪴 Introduction

As part of the amFOSS-Curriculum for freshers, I completed the official set of Git exercises from gitexercises.fracz.com.

Each exercise focuses on a key Git concept — from basic commits and branching to advanced rebasing, cherry-picking, squashing, and debugging history with bisect.

This blog documents all 23 exercises, the exact commands I used, and what I learned along the way.
Each section includes the terminal commands I ran and a short explanation of what each task taught me.


### 🧩 Exercise 1 – master

**Scenario:** Initialize and verify a new Git exercise environment.

**Commands and explanation:**

```bash
git start
```

```bash
git verify
```

**git start sets up the environment for the current exercise, while git verify checks if your task solution is correct.**


### 🧩 Exercise 2 – commit-one-file

**Scenario:** Learn how to unstage a file after adding it.

**Commands and explanation:**

```bash
git add A.txt
```
```bash
git commit -m "add one file"
```
```bash
git verify
```

**Added A.txt to staging and committed it. This teaches how to move files between the working directory, staging area, and repository.**


### 🧩 Exercise 3 – commit-one-file-staged

**Scenario:** Prevent unwanted files from being tracked.

**Commands and explanation:**

```bash
nano .gitignore
```
```bash
#contents for .gitignore
*.exe
*.o
*.jar
libraries/
```
```bash
git add .
```
```bash
git commit -m "commit useful files"
```
```bash
git verify
```

**Added ignore patterns in .gitignore to skip temporary and compiled files and files of specific types. This ensures a clean, lightweight repository.**


### 🧩 Exercise 4 – chase-branch

**Scenario:** Merge one branch into another.

**Commands and explanation:**

```bash
git checkout chase-branch
```
```bash
git merge escaped
```
```bash
git verify
```

**Switched to chase-branch and merged escaped into it. Demonstrates basic merging workflow.**


### 🧩 Exercise 5 – Merge Conflict

**Scenario:** Handle a merge conflict manually.

**Commands and explanation:**

```bash
git checkout merge-conflict
```
```bash
git merge another-piece-of-work
```
```bash
nano equation.txt
```
```bash
#content of equation.txt
2 + 3 = 5
```
```bash
git add equation.txt
```
```bash
git commit -m "merge and resolve"
```
```bash
git verify
```

**Resolved conflicting edits by choosing the correct line and committing the final merged version.**


### 🧩 Exercise 6 – Stash

**Scenario:** Temporarily save unfinished work and restore it later.

**Commands and explanation:**

```bash
git stash
```
```bash
nano bug.txt
```
```bash
git commit -am "remove bug"
```
```bash
git stash apply
```
```bash
nano bug.txt
```
```bash
git commit -am "finish"
```
```bash
git verify
```

**Used stash to hide temporary changes, fixed the bug (editing nano.txt), then reapplied and committed previous edits.**


### 🧩 Exercise 7 – Change Branch History

**Scenario:** Reapply branch commits on a new base using rebase.

**Commands and explanation:**

```bash
git checkout change-branch-history
```
```bash
git rebase hot-bugfix
```
```bash
git verify
```

**Rebased to align commit history and keep a linear project timeline.**


### 🧩 Exercise 8 – Untrack Ignored File

**Scenario:** Stop tracking a file while keeping it locally.

**Commands and explanation:**

```bash
git rm --cached ignored.txt
```
```bash
git commit -am "untrack ignored.txt"
```
```bash
git verify
```

**--cached removes the file from Git tracking without deleting it from your system.**


### 🧩 Exercise 9 – Fix Case of Filename

**Scenario:** Handle filename case changes on case-insensitive file systems.

**Commands and explanation:**

```bash
git reset HEAD^
```
```bash
mv File.txt file.txt
```
```bash
git add file.txt
```
```bash
git commit -m "lowercase filename"
```
```bash
git verify
```

**Reset previous commit, renamed file properly, and recommitted it — avoiding duplication.**


### 🧩 Exercise 10 – Fix Old Typo

**Scenario:** Modify the previous commit without creating a new one.

**Commands and explanation:**

```bash
git commit -a --amend
```
```bash
git verify
```

**--amend lets you add or change files in the last commit, cleaning up recent mistakes.**


### 🧩 Exercise 11 – Change Commit Date

**Scenario:** Alter a commit’s timestamp.

**Commands and explanation:**

```bash
git commit --amend --no-edit --date="1987-08-03"
```
```bash
git verify
```

**Used --date to set a custom commit date without modifying the message or contents.**


### 🧩 Exercise 12 – Commit Lost

**Scenario:** Recover a lost commit using Git reflog.

**Commands and explanation:**

```bash
git reflog
```
```bash
git reset --hard HEAD@{1}
```
```bash
git verify
```

**Checked previous HEAD movements via reflog and restored the state using reset --hard.**


### 🧩 Exercise 13 – Split Commit

**Scenario:** Divide a single commit into multiple logical ones.

**Commands and explanation:**

```bash
git rebase -i HEAD^^
```
```bash
git add file.txt
```
```bash
git rebase --continue
```
```bash
git add file.txt
```
```bash
git rebase --continue
```
```bash
git verify
```

**Interactive rebase allowed breaking one large commit into smaller, focused commits.**


### 🧩 Exercise 14 – Commit Lost (Reflog Recovery)

**Scenario:** Recover from accidental history rewrites.

**Commands and explanation:**

```bash
git reflog
```
```bash
git reset --hard HEAD@{1}
```
```bash
git verify
```

**Again used reflog to roll back to a safe previous commit — vital for undoing mistakes.**


### 🧩 Exercise 15 – Split Commit (Two Files)

**Scenario:** Separate two files committed together into two commits.

**Commands and explanation:**

```bash
git reset HEAD^
```
```bash
git add first.txt
```
```bash
git commit -m "First.txt"
```
```bash
git add second.txt
```
```bash
git commit -m "Second.txt"
```
```bash
git verify
```

**Unstaged both files, then committed them separately for better granularity.**


### 🧩 Exercise 16 – Too Many Commits

**Scenario:** Reorder or squash multiple commits interactively.

**Commands and explanation:**

```bash
git rebase -i HEAD~4
```
```bash
git verify
```

**Interactive rebase (-i) lets you edit, reorder, or squash commits into a cleaner timeline.**


### 🧩 Exercise 17 – Executable

**Scenario:** Make a script file executable and commit the permission change.

**Commands and explanation:**

```bash
git update-index --chmod=+x script.sh
```
```bash
git commit -m "make executable"
```
```bash
git verify
```

**Changed file permissions with --chmod, which Git tracks as a metadata update.**


### 🧩 Exercise 18 – Commit Parts

**Scenario:** Commit only specific changes (hunks) from a file.

**Commands and explanation:**

```bash
git add --patch file.txt
```
```bash
git commit -m "task 1 related"
```
```bash
git commit -am "rest of the content"
```
```bash
git verify
```

**Patch interactively stages only the selected parts of the file before committing.**


### 🧩 Exercise 19 – Pick Your Features

**Scenario:** Cherry-pick and merge commits from other branches selectively.

**Commands and explanation:**

```bash
git log --oneline --decorate --graph --all -8
```
```bash
git checkout pick-your-features
```
```bash
git cherry-pick feature-a
```
```bash
git cherry-pick feature-b
```
```bash
git merge --squash feature-c
```
```bash
git commit -am "Complete Feature C"
```
```bash
git verify
```

**Applied specific commits from other branches and squashed multiple changes into one.**


### 🧩 Exercise 20 – Rebase Complex

**Scenario:** Move commits from one base branch onto another.

**Commands and explanation:**

```bash
git rebase --onto your-master issue-555 rebase-complex
```
```bash
git verify
```

**Transferred commits from issue-555 to start from your-master, which is a common cleanup technique.**


### 🧩 Exercise 21 – Invalid Order

**Scenario:** Reorder commits to correct history sequence.

**Commands and explanation:**

```bash
git rebase -i HEAD~4
```
```bash
git verify
```

**Fixed commit order by interactively rearranging them.**


### 🧩 Exercise 22 – Find Swearwords

**Scenario:** Find and fix commits that introduced offensive words.

**Commands and explanation:**

```bash
git log -S shit
```
```bash
git rebase -i HEAD~105
```
```bash
git log -p -1
```
```bash
git add list.txt
```
```bash
git commit --amend
```
```bash
git rebase --continue
```
```bash
git log -p -1
```
```bash
git add words.txt
```
```bash
git commit --amend
```
```bash
git rebase --continue
```
```bash
git log -p -1
```
```bash
git add words.txt
```
```bash
git commit --amend
```
```bash
git rebase --continue
```
```bash
git verify
```

**Searched commits that added the word “shit” and replaced them with “flower,” cleaning history responsibly.**


### 🧩 Exercise 23 – Find Bug

**Scenario:** Locate the first commit that introduced a bug using git bisect.

**Commands and explanation:**

```bash
git checkout find-bug
```
```bash
git bisect start
```
```bash
git bisect bad
```
```bash
git bisect good 1.0
```
```bash
git bisect run sh -c "openssl enc -base64 -A -d < home-screen-text.txt |
```
```bash
grep -v jackass"
```
```bash
git push origin 4d2725ac4c874dbb207770001def27aed48e9ddb:find-bug
```

**Automated bug hunt using bisect, running a base64-decoding test to find when “jackass” appeared.**


## 🏁 Conclusion

Through these 23 exercises, I learned how Git actually works under the hood - from commits and merges to rebases, cherry-picks, reflogs, and even debugging with bisect.
Each task simulated real-world version control challenges that every developer eventually faces.
