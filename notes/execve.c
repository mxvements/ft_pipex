/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:40 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/24 16:18:42 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

/*    7   */
/* execve */
int	main(void)
{
	/*
		int execve(const chat *path, char *const argv[], char *const envp[])
		execute a file

		transforms the calling process into a new process
		the new process if constructed from an ordinary file, whose name is
		pointed to by path, called the new process file. This file is either
		an executable object file or a file of data for an interpreter.

		it overlays the current process image with a new process image, the
		successful call has no process to return to. If execve does return to 
		the calling process, an error has ocurred; the return value will be -1 
		and the global variable errno is set to indicate the error.
	*/
	execve();
	return (0);
}
