/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
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

/*  2   */
/* wait */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ wait w/ fork\n");
	printf("\x1b[0m"); //reset
	int pid;
	int	n;
	int i;
	
	pid = fork();
	if (pid == 0)
		n = 1; //this process should print until (1 + 4)
	else
		n = 6; //this process should print unitl (6 + 4)
	/*
		the OS will handle how the process get printing numbers
		we dont know the order, its impredictable
		that's why we end up using the wait function

		pid_t wait(int *stat_loc)
		wait for process termination (the parent waits for the children)
	*/
	if (pid != 0)
		wait(NULL); //we dont wait in the child process
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (pid != 0)
		printf("\n");
	return (0);
}