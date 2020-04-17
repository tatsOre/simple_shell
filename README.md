# Simple Shell
### Simple replication of the command-line interpreter Shell. All files are written in C language.

### Overview:
The shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.  It is the program that is running when a user logs into the system (although a user can select a different shell with the chsh(1) command).
The shell implements a language that has flow control constructs, a macro facility that provides a variety of features in addition to data storage, along with built in history and line editing capabilities. [dash(1) - Linux man page](https://linux.die.net/man/1/dash)

### Compilation:
Code files must be compiled this way:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Usage:
The Simple Shell should work like this in interactive mode (simple commands can be typed directly to the running shell):
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
And also in non-interactive mode (commands can be put into a file and the file can be executed directly):
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
### Resources:
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)

### Requirements:
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to [why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems)

### Libraries:

[stdarg.h](https://en.wikipedia.org/wiki/Stdarg.h) | [signal.h](https://en.wikipedia.org/wiki/C_signal_handling) |
[unistd.h](https://en.wikipedia.org/wiki/Unistd.h) | [sys/wait.h](https://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/wait.h.html) | [stdlib.h](https://es.wikipedia.org/wiki/Stdlib.h) | [sys/stat.h](https://pubs.opengroup.org/onlinepubs/007908799/xsh/sysstat.h.html)

### Files:

| File | Description |
| :---: | :---: |
| `simple_shell.h` | Libraries, declarations. |
| `builtin.c` | Search and init built-ins |
| `errormessages.c` | Messages Handlers |
| `execute.c` | Create and execute processes |
| `freeall.c` | Free memory |
| `getenv.c` | Get environment variables |
| `pathappend.c` | Append program to its path |
| `searchinit.c` | Execute local programs, redirect commands |
| `searchpathfile.c` | Search and validate file paths |
| `splitarguments.c` | Count arguments and breaks them into tokens |
| `str_handlers.c` | String Handlers Funcs |
| `hsh.c` | Main Function |

### Flowcharts:
![Flowchart](https://drive.google.com/open?id=1zAp6WFA6Acx2SbfE2dGTOl9tjFxOQZeX)

### Authors:
* Maria Fernanda Crespo Martinez | [Github](https://github.com/mfcrespo)
* Tatiana Orejuela Zapata | [Github](https://github.com/tatsOre)

##### Holberton School - Foundations - Low-level programming & Algorithm  Linux and Unix system programming.
#####  April, 2020. Cali, Colombia.
