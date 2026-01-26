# task-08 (Build a Simple Shell)

This is a CLI (Command Line Interface) based simple shell built using C. It can read command inputs from the user,
process it, and produce an output. It also can handle background processes, keep a track on it and could print the PID's of the background processes and also kill the currently running foreground processes on user interrupt.

### The preprocessor directives used in this program are :
- **#include**
- **#define**

### Header files included are :
- **stdio.h**
- **stdlib.h**
- **string.h**
- **unistd.h**
- **sys/wait.h**
- **signal.h**

### Constatnt used are :
- **MAX_LINE**
- **MAX_ARGS**
- **MAX_BG**

### The structure of the program is as follows:
- **Signal handlers** (To print PID's of background processes or kill a process upon user input/interrupt
- **Utility** (To manage the system resources efficiently)
- **Main Shell**
	- It registers signal handlers
	- Cleans up the finished background processes
	- Prints the prompt
	- Reads the input from user
	- Removes newline (\n) from the end of the command/input and parses the input (string tokenizing) into command and arguments
	- It handles built-in commands and external commands differently. If the user inputs a built-in command the parent process(the shell itself) executes it with system calls. While if an external command is input, a child process is created using **fork()** and the command is executed in the child process using **execvp()**
	- Could handle errors (if invalid input is given, the shell prints it)
	- It supports background execution when user adds **&** at the end of a command. The shell continues to print prompt and accept input without waiting.
	- Signal handlings are implemented as follows :
		- Upon pressing **Ctrl+C**, the shell prints the PID's of the currently running background processes
		- Upon pressing **Ctrl+Z**, the shell suspends/kills the currently running foreground processes

### You could also use/test this simple shell
1. Clone this repo
```bash
https://github.com/rhll07/amfoss-curriculum
```

2. Change the directory
```bash
cd task-08
```

3. Compile the C program
```bash
gcc -Wall -Wextra simpleshell.c -o simpleshell
```

4. Run the shell
```bash
./simpleshell
```
