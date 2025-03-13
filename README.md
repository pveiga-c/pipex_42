# Pipex

## Description

The **pipex** project is an introduction to UNIX pipes and process management. The goal is to replicate the behavior of shell pipelines by redirecting input and output between commands using system calls.

## Program Usage

The program should be executed as follows:

```sh
./pipex file1 cmd1 cmd2 file2
```

It must behave like the shell command:

```sh
< file1 cmd1 | cmd2 > file2
```

### Arguments:
- `file1` and `file2`: Input and output files.
- `cmd1` and `cmd2`: Shell commands with their parameters.

### Example:
```sh
./pipex infile "ls -l" "wc -l" outfile
```
This should behave like:
```sh
< infile ls -l | wc -l > outfile
```

## Project Requirements

- The program must be named `pipex`.
- It must handle file input/output redirection correctly.
- It should execute the commands using `execve`.
- The following system calls are allowed:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.
- Error handling must match shell behavior.
- If an error occurs, `pipex` should print `Error` to standard error.

## Project Rules

- The code must follow the **42 Norm**.
- The `Makefile` must contain the rules: `all`, `clean`, `fclean`, and `re`.
- Global variables are forbidden.

## Author

Pedro Cristóvão Veiga Correia

