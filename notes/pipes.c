/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:45:12 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 13:45:13 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*   5   */
/* pipes */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ pipes\n");
	printf("\x1b[0m"); //reset
	int pid1;
	int fd[2];
	int x;
	int y;
	/*
		int pipe(int filedes[2])
		create descriptor pair or interprocess communication

		in memory file, that only has a buffer, from which you can write or read
		fd[2], allocate the keys to the readbuffer and the writebuffer the pipe
		creates

		first pipe
		then fork
		we operate this way so the child process inherits the file descriptors
		we close one fd in one process while on the other it remains opened
		they remained open/closed independently from each other
		
		fd[0] - read
		fd[1] - write
	*/

	if (pipe(fd) == -1)
		printf("Error on pipe\n");
	pid1 = fork();
	if (pid1 == -1)
		printf("Error on fork\n");
	if (pid1 != 0)
	{
		close(fd[0]);
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
			printf("Error on writing to the pipe\n");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
			printf("Error on reading the pipe\n");
		close(fd[0]);
		printf("Got from child process: %d\n", y);
	}
	return (0);
}
