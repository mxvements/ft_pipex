CC=cc

CFLAGS=-Wall -Werror -Wextra -g3

all: fork wait ids multiple_forks fork_and_pipe execve

fork:
	$(CC) $(CFLAGS) fork.c -o fork.out

wait:
	$(CC) $(CFLAGS) wait.c -o wait.out

ids:
	$(CC) $(CFLAGS) ids.c -o ids.out

multiple_forks:
	$(CC) $(CFLAGS) multiple_forks.c -o multiple_forks.out

pipe:
	$(CC) $(CFLAGS) pipes.c -o pipe.out

fork_and_pipe:
	$(CC) $(CFLAGS) fork_and_pipe.c -o fork_and_pipe.out

execve:
	$(CC) $(CFLAGS) execve.c -o execve.out

fclean:
	rm -rf *.out
	rm -rf *.out.dSYM
