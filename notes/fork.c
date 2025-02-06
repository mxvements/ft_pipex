/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:26:42 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 11:27:26 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*  1   */
/* fork */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ fork\n");
	pid_t	pid;
	/*
		pid_t fork(void);
		forking the execution line

		a child proces is created, and starts executing the code as well
		P (pid != 0) -> C1 (pid 0)

		we have two ids returned from fork (for each process executing)
		+ the child process is always 0
		+ returns -1 for errors
	*/
	printf("\x1b[32m"); //green
	pid = fork();
	printf("Hello world from: %d \n", pid);
	if (pid == 0)
		printf("\tChild process\n");
	else
		printf("\tParent process\n");
	/*
		callign a 2nd fork()
		P -> C1 -> CC2
		  -> C2
		we get 4 processes in total
	*/
	printf("\x1b[36m"); //cyan
	pid = fork();
	if (pid == 0)
		printf("\t\tChild process\n");
	if (pid != 0)
	{
		printf("\t\tParent processs\n");
		pid = fork();
		printf("\x1b[34m");
		if (pid != 0)
			printf("\t\t\tThird fork, only on previous parents\n");
	}
	printf("\x1b[0m"); //reset
	return (0);
}