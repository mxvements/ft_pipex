/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:07:24 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/09 11:07:25 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(void)
{
	perror("pipex error");
	exit(1);
}

void	firstcommand(t_data *data)
{
	//printf("first command, cmd path: %s\n", data->cmd1_args[0]);
	//printf("first command, infile path: %s\n", data->infile->path);
	if (data->cmd1_args == NULL)
		return (error_message());
	if (access(data->cmd1_args[0], F_OK) != 0)
		return (error_message());
	close(data->fd_pipe[READ_END]);
	dup2(data->fd_pipe[WRITE_END], STDOUT_FILENO);
	close(data->fd_pipe[WRITE_END]);
	data->infile->fd = open(data->infile->path, O_RDONLY);
	if (data->infile->fd < 0)
		return (error_message());
	dup2(data->infile->fd, STDIN_FILENO);
	if (execve(data->cmd1_args[0], data->cmd1_args, data->env) == -1)
		return (error_message());
}

void	secondcommand(t_data *data)
{
	//printf("second command, outfile path: %s\n", data->cmd2_args[0]);
	//printf("second command, outfile path: %s\n", data->outfile->path);
	if (data->cmd2_args == NULL)
		return (error_message());
	if (access(data->cmd2_args[0], F_OK) != 0)
		return (error_message());
	close(data->fd_pipe[WRITE_END]);
	dup2(data->fd_pipe[READ_END], STDIN_FILENO);
	close(data->fd_pipe[READ_END]);
	data->outfile->fd = open(data->outfile->path, O_WRONLY | O_CREAT | O_TRUNC,
							0777);
	if (data->outfile->fd < 0)
		return (error_message());
	dup2(data->outfile->fd, STDOUT_FILENO);
	if (execve(data->cmd2_args[0], data->cmd2_args, data->env) == -1)
		return (error_message());
}

void	pipex(t_data *data)
{
	int	stat_loc[2];
	
	pipe(data->fd_pipe); //errores
	data->id[0] = fork();
	if (data->id[0] == 0)
		firstcommand(data);
	else
	{
		data->id[1] = fork();
		if (data->id[1] == 0)
			secondcommand(data);
		else
		{
			close(data->fd_pipe[WRITE_END]);
			close(data->fd_pipe[READ_END]);
		}
	}
	waitpid(data->id[0], &stat_loc[0], 0);
	waitpid(data->id[1], &stat_loc[1], 0);
	exit(WEXITSTATUS(stat_loc[1]));
}