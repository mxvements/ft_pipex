/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:11:53 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 14:11:55 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*       6       */
/* fork and pipe */
int	main(void)
{
	printf("\x1b[33m"); //yellow
	printf("+ fork and pipe: practical use\n");
	printf("\x1b[0m"); //reset
	int fd[2];
	int arr[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 3, 1, 2, 5, 3};
	int arrsize = sizeof(arr) / sizeof(int);
	int id;
	int start, end;
	int sum = 0;
	int sum_child;

	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	//indices
	if (id == 0)
	{
		start = 0;
		end = arrsize / 2;
	}
	else
	{
		start = arrsize / 2;
		end = arrsize;
	}
	//sum
	for (int i = start; i < end; i++)
		sum += arr[i];
	printf("Calculated partial sum: %d\n", sum);
	//send partial sum to the other process
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (3);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &sum_child, sizeof(sum_child)) == -1)
			return (4);
		close(fd[0]);

		int totalsum = sum + sum_child;
		printf("Total sum: %d\n", totalsum);
		wait(NULL);
	}
	return (0);
}

