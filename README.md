<div align="center">
    <img src="https://img.shields.io/badge/status-wip-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/started-24%20%2F%2001%20%2F%202024-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/badge/score-1--%20%2F%20100-success?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/languages/top/mxvements/ft_fdf?color=00ABAD&style=flat-square" />
    <img src="https://img.shields.io/github/last-commit/mxvements/ft_pipex?color=00ABAD&style=flat-square" />
    <br>
    <a href='https://www.linkedin.com/in/luciami' target="_blank"><img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat-square&logo=Linkedin&logoColor=white&labelColor=1323233&color=323233'/></a>
    <a href='https://profile.intra.42.fr/users/luciama2' target="_blank"><img alt='42' src='https://img.shields.io/badge/Madrid-100000?style=flat-square&logo=42&logoColor=white&labelColor=323233&color=323233'/></a>
    <br>
</div>

# ft_pipex

The representation in 3D of a landscape is a critical aspect of modern mapping. For example, in these times of spatial exploration, to have a 3D representation of Mars is a prerequisite condition to its conquest. As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these phenomena and their evolution, and as a result, be better prepared. It’s your turn today to modelize some 3D magnificent landscapes, imaginary or not.

# Mandatory part

| **Program Name** | pipex |
| ---------------- | --- |
| **Turn in files** | Makefile, *.h, *.c |
| **Makefile** | Name, all, clean, fclean, re |
| **Arguments** | file1 cmd1 cmd2 file2 |
| **External functs** | + open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid. + ft_printf and any equivalent YOU coded |
| **Libft auth** | Yes |
| **Description** | This project is about handling pipes.|

Your program will be executed as follows:
```
./pipex file1 cmd1 cmd2 file2
```

It must take 4 arguments:
• file1 and file2 are file names.
• cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:
```
 < file1 cmd1 | cmd2 > file2
```
## Examples
```
./pipex infile "ls -l" "wc -l" outfile
```
Should behave like: < infile ls -l | wc -l > outfile

```
./pipex infile "grep a1" "wc -w" outfile
```
Should behave like: < infile grep a1 | wc -w > outfile

## Requirements

Your project must comply with the following rules:
+ You have to turn in a Makefile which will compile your source files. It must not
relink.
+ You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
+ Your program mustn’t have memory leaks.
+ If you have any doubt, handle the errors like the shell command:
< file1 cmd1 | cmd2 > file2

# How to use

1 - Clone the repository
```
git@github.com:mxvements/ft_fdf.git
```

2 - Compilation

Enter the project folder and run make, makefile rules
```
`make` - compile fdf (with libft and gnl)
`make clean` - delete all *.o files (from fdf's srcs and libft + gnl)
`make fclean` - delete all *.o & *.a (executable) files
`make re` - use fclean + all, recompile fdf
```

# Other

## Norminete

At 42 School, it is expected that almost every project is written in accordance with the Norm, which is the coding standard of the school.

<a href="https://github.com/42School/norminette">
<a>Norminette's repository</a>

```
- No for, do...while, switch, case, goto, ternary operators and variable-length arrays are allowed
- Each function must be a maximum of 25 lines, not counting the function's curly brackets
- Each line must be at most 80 columns wide, comments included
- A function can take 4 named parameters maximum
- No assigns and declarations in the same line (unless static or const)
- You can't declare more than 5 variables per function
- ...
```
## Aknowledgments

+ [CodeVault's list on Unix Processes in C](https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)

# License
[MIT License](https://github.com/mxvements/ft_license/blob/main/LICENSE.txt)
