# Learning Git: My Journey Through the amFOSS Anveshan 2025!

## Introduction

As part of the amFOSS-Curriculum for freshers, I completed the official set of Git exercises from gitexercises.fracz.com.

Each exercise focuses on a key Git concept — from basic commits and branching to advanced rebasing, cherry-picking, squashing, and debugging history with bisect.

This blog documents all 23 exercises, the exact commands I used, and what I learned from those commands.

As it's the first time exploring advanced git commands, I hope I would soon be able to master it through practice !!!

### Exercise 1 - master

**Scenario:** To initialize and verify a new Git exercise environment.

**Commands and explanation:**

```bash
git start
```
```bash
git verify
```

**git start sets up the environment for the current exercise, while git verify checks if your task solution is correct.**


### Exercise 2 - commit-one-file

**Scenario:** To learn how to unstage a file after adding it.

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

**Added A.txt to staging area and committed it. This teaches how to move files between the working directory, staging area, and github repository.**


### Exercise 3 - commit-one-file-staged

**Scenario:** To prevent unwanted files from being tracked.

**Commands and explanantion:**
```bash
git reset HEAD A.txt
```
```bash
git commit -m "destage one file"
```
```bash
git verify
```

**Removed A.txt from the staging area by using "git reset HEAD A.txt" and then necessary commits was applied.**


### Exercise 4 - ignore-them

**Scenario: To ignore unwanted files or directories from being tracked to the repository.**

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

**Added the path of the file types and directories in .gitignore to skip temporary and compiled files. This ensures a clean, lightweight repository.**


###  Exercise 5 - chase-branch

**Scenario:** To merge one branch into another.

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

**Switched to chase-branch using "git checkout" and merged escaped branch into it by using "git merge". This demonstrates basic merging workflow.**


###  Exercise 6 - merge-conflict

**Scenario:** To handle a merge conflict manually.

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

**Merged the branches containing the specific commits containing conflicts, using "git checkout" and "git branch". Then manually resolved the conflict on equation.txt by choosing the correct line (equation). Then it was finally added, committed and verified.**


### Exercise 7 - save-your-work

**Scenario:** To temporarily save unfinished work and restore it later.

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

**Used stash to hide temporary changes, or in simple words, temporarily saved the changes without committing or passing to the staging area. Then fixed the bug (editing nano.txt), stash was applied ("git stash apply") and committed previous edits.**


### Exercise 8 - change-branch-history

**Scenario:** To reapply branch commits on a new base using rebase.

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

**Checked out to change-branch-history and then rebased hot-bugfix to it by using "git rebase". This ensures that all the commits in the branch "hot-bugfix" would be placed on top of the commits in the branch "change-branch-history".Rebase helps to align commit history and keep a linear project timeline.**


###  Exercise 9 - remove-ignored

**Scenario:** To stop tracking a file while preserving it locally.

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

**"git rm --cached" removes the file from Git tracking without actually deleting it from your system.**


### Exercise 10 - case-sensitive-filename

**Scenario:** To handle filename case changes on case-insensitive file systems.

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

**Reset previous commit by using "git reset HEAD^", renamed the file properly using "mv", and recommitted it.**


### Exercise 11 - fix-typo

**Scenario:** To modify the previous commit without creating a new one.

**Commands and explanation:**

```bash
git commit -a --amend
```
```bash
git verify
```

**"git commit -a --amend" allows to add or change files in the last commit, hence modigying it without creating a new commit.**


### Exercise 12 - forge-date

**Scenario:** To alter a commit’s timestamp.

**Commands and explanation:**

```bash
git commit --amend --no-edit --date="1987-08-03"
```
```bash
git verify
```

**Used "git commit --amend --no-edit --date" to set a custom commit date without modifying the message or contents and without creating a new commit.**


### Exercise 13 - fix-old-typo

**Scenario:** To reset multiple commits, fix the typo in a file and then continue rebasing to fix rebase conflict and then continue rebase and commit the final version of the file.

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

**Interactive rebase allowed breaking one large commit into smaller, focused commits. Here in this case, "git rebase -i HEAD^^" is used to rebase the 2 latest commands and then individually add and continue rebasing to achieve multiple commit history.**


### Exercise 14 - commit-lost

**Scenario:** To recover a lost commit using git reflog.

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

**Checked previous HEAD movements via reflog and restored the required commit using "git reset --hard HEAD@{}".**


### Exercise 15 - split-commit

**Scenario:** To divide a single commit into multiple commits.

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

**Used "git reset HEAD^" to unstage the last commit then staged and committed multiple times, accordingly.**


### Exercise 16 - too-many-commits

**Scenario:** To squash (combine) multiple commits interactively.

**Commands and explanation:**

```bash
git rebase -i HEAD~4
```
```bash
git verify
```

**Interactive rebase (-i) lets you edit, reorder, and squash commits into a cleaner timeline.**


### Exercise 17 - executable

**Scenario:** To make a script file executable and then commit the permission change.

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

**Changed file permissions with "--chmod=+x", in which git tracks as a metadata update through "git update-index".**


### Exercise 18 - commit-parts

**Scenario:** To commit only specific changes (hunks) from a file.

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

**"git add --patch" interactively stages only the selected parts of a file before committing. So that the user could commit remaining part of the file later.**


### Exercise 19 - pick-your-features

**Scenario:** To cherry-pick (select) and merge desired commits from various branches selectively.

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

**"git log --oneline --decorate --graph --all -8" is used to show the last 8 commits from all branches, drawn as a graph.**
**Then checked out to branch "pick-your-features" to select "feature-a", "feature-b" and "feature-c" as combined (git merge --squash feature).**


### Exercise 20 - rebase-complex

**Scenario:** To move commits from one base branch onto another.

**Commands and explanation:**

```bash
git rebase --onto your-master issue-555 rebase-complex
```
```bash
git verify
```

**Transferred commits from issue-555 to start from your-master, by using "git rebase --onto".**


### Exercise 21 - invalid-order

**Scenario:** To reorder commits to correct history sequence.

**Commands and explanation:**

```bash
git rebase -i HEAD~4
```
```bash
git verify
```

**Fixed commit order by interactively rearranging them (rearrange the lines).**


### Exercise 22 - find-swearwords

**Scenario:** To find and fix commits that introduced offensive words in 2 text files.

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

**Searched commits that added the word “shit” by using "git log -S", edited the commits and replaced them with “flower,” and amended commits and continued rebasing until completion.**


###  Exercise 23 - find-bug

**Scenario:** To locate the first commit that introduced a bug (the bug is occurence of word "jackass" in a text file with base-64 encryption) using git bisect.

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
git bisect run sh -c "openssl enc -base64 -A -d < home-screen-text.txt | grep -v jackass"
```
```bash
git push origin 4d2725ac4c874dbb207770001def27aed48e9ddb:find-bug
```

**"git bisect start" to check the current branch for bugs.**
**"git bisect bad" is used to mark current branch as buggy because it is already specified.**
**"git bisect good 1.0" to mark branch 1.0 as bug-free.**
**Then for each commit the bug is checked by searching for the word "jackass" by decoding home-screen-text.txt with openssl base64 decryption.**
**The hash value of the commit containing the bug or the commit in which the word "jackass" was introduced to home-screen-text.txt is pushed.**

## Conclusion

Through these 23 exercises, I learned how git works and to use it efficiently as a developer/contributor. Each exercise simulated real-world version control challenges that made me to explore more and to understand more about git.

