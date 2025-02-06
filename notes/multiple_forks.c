/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:27:08 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 13:27:09 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*       4        */
/* multiple forks */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ multiple forks\n");
	printf("\x1b[0m"); //reset
	int pid1;
	int	pid2;

	pid1 = fork();
	pid2 = fork(); //4 processes
	/*
		how do we set the hierarchy of each process?

		for() ten times creates 2^10 process
	*/
	if (pid1 == 0)
	{
		printf("\x1b[32m");
		if (pid2 == 0)
			printf("\t\tWe are process y\n");
		else
			printf("\ttWe are process x\n");
	}
	else
	{
		printf("\x1b[36m");
		if (pid2 == 0)
			printf("\tWe are process z\n");
		else
			printf("We are the parent process\n");
	}
	printf("\x1b[0m");
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finished\n");
	return (0);
}
