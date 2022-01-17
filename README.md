# 42Cursus-pipex

## Introduction:
This project is the discovery in detail and by programming of a UNIX mechanism that you already know.<br/>

### Common Instructions:
- The executable file must be named pipex.<br/>
- You have to turn in a Makefile which will compile your source files. It must not relink.<br/>
- You have to handle errors sensitively. In no way can your program quit unexpectedly (Segmentation fault, bus error, double free, etc). If you are unsure, handle the errors like the shell command < file1 cmd1 | cmd2 > file2.<br/>
- Your program cannot have memory leaks.<br/>
- You are allowed to use the following functions:
  - access
  - open
  - unlink
  - close
  - read
  - write
  - malloc
  - waitpid
  - wait
  - free
  - pipe
  - dup
  - dup2
  - execve
  - fork
  - perror
  - strerror
  - exit

### Objectives:
Your objective is to code the Pipex program. It should be executed in this way:

```
 $> ./pipex file1 cmd1 cmd2 file2
```
- Just in case: file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters.<br/>

The execution of the pipex program should do the same as the next shell command:
```
 $> < file1 cmd1 | cmd2 > file2
```

### Examples:
```
 $> ./pipex infile ``ls -l'' ``wc -l'' outfile
```
should be the same as “< infile ls -l | wc -l > outfile”.

```
 $> ./pipex infile ``grep a1'' ``wc -w'' outfile
```
should be the same as “< infile grep a1 | wc -w > outfile”.
