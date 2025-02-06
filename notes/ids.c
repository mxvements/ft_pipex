/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ids.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:49:20 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 12:49:23 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*  3   */
/* ids */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ ids w/ fork\n");
	printf("\x1b[0m"); //reset
	int pid;
	/*
		pid_t getpid(void);
		pid_t getppid(void);
		get parent or calling process identification
	*/
	pid = fork();
	if (pid == 0)
	{
		sleep(1);
		printf("child: \n");
	}
	if (pid != 0)
		printf("parent: \n");
	printf("\tCurrent id: %d, Parent id: %d\n", getpid(), getppid());
	if (wait(NULL) == -1)
		printf("No children to wait for\n");
	else
		printf("Finished exection\n");
	return (0);
}