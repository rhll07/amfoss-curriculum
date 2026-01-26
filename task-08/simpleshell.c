#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define MAX_ARGS 100
#define MAX_BG   100

pid_t bg_pids[MAX_BG];
int bg_count = 0;
pid_t fg_pid = -1;

// Signal handlers

void sigint_handler(int sig) {
    (void)sig;

    printf("\nBackground processes:\n");
    for (int i = 0; i < bg_count; i++) {
        printf("PID: %d\n", bg_pids[i]);
    }
    printf("simpleshell> ");
    fflush(stdout);
}

void sigtstp_handler(int sig) {
    (void)sig;

    if (fg_pid > 0) {
        kill(fg_pid, SIGTSTP);
    }
    printf("\nsimpleshell> ");
    fflush(stdout);
}

// Utility

void remove_bg_pid(pid_t pid) {
    for (int i = 0; i < bg_count; i++) {
        if (bg_pids[i] == pid) {
            for (int j = i; j < bg_count - 1; j++) {
                bg_pids[j] = bg_pids[j + 1];
            }
            bg_count--;
            return;
        }
    }
}

// Main Shell

int main(void) {
    char line[MAX_LINE];
    char *args[MAX_ARGS];

    // Register signal handlers
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);

    while (1) {
        // Clean up finished background processes
        pid_t done;
        while ((done = waitpid(-1, NULL, WNOHANG)) > 0) {
            remove_bg_pid(done);
        }

        // Prompt
        printf("simpleshell> ");
        fflush(stdout);

        // Read input
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            printf("\n");
            break;
        }

        // Remove newline
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) == 0)
            continue;

        // Parse input (tokenize)
        int argc = 0;
        int background = 0;
        char *token = strtok(line, " ");

        while (token != NULL && argc < MAX_ARGS - 1) {
            if (strcmp(token, "&") == 0) {
                background = 1;
            } else {
                args[argc++] = token;
            }
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        if (argc == 0)
            continue;

        // Handle built-in commands

        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "cd: missing argument\n");
            } else if (chdir(args[1]) != 0) {
                perror("cd");
            }
            continue;
        }

        if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            } else {
                perror("pwd");
            }
            continue;
        }

        // Handle external commands

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            // Parent process
            if (background) {
                if (bg_count < MAX_BG) {
                    bg_pids[bg_count++] = pid;
                    printf("[background pid %d]\n", pid);
                }
            } else {
                fg_pid = pid;
                waitpid(pid, NULL, 0);
                fg_pid = -1;
            }
        }
    }

    return 0;
}