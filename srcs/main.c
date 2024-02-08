/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:08:08 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/26 12:08:10 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	firstcommand(t_data *data)
{
	printf("first command, cmd path: %s\n", data->cmd1_args[0]);
	printf("first command, infile path: %s\n", data->infile->path);

	close(data->fd_pipe[READ_END]); //first command writes on the pipe fd
	dup2(data->fd_pipe[WRITE_END], STDOUT_FILENO);
	close(data->fd_pipe[WRITE_END]);
	/*	open file inside child */
	data->infile->fd = open(data->infile->path, O_RDONLY);
	dup2(STDOUT_FILENO, data->infile->fd);
	//execve
	execve(data->cmd1_args[0], data->cmd1_args, data->env);
}

void	secondcommand(t_data *data)
{
	printf("second command, outfile path: %s\n", data->cmd2_args[0]);
	printf("second command, outfile path: %s\n", data->outfile->path);

	close(data->fd_pipe[WRITE_END]);
	dup2(data->fd_pipe[READ_END], STDIN_FILENO);
	close(data->fd_pipe[READ_END]);
	//open outputfile
	data->outfile->fd = open(data->outfile->path, O_RDONLY);
	dup2(STDIN_FILENO, data->outfile->fd);
	//execve
	execve(data->cmd2_args[0], data->cmd2_args, data->env);
}

void	pipex(t_data *data)
{
	pipe(data->fd_pipe);
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
	//wait pid
	//salir con el resutlado del ultimo comando ejecutado
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	//infile.txt "ls -l" "cat -e" outfile.txt
	if (argc != 5)
		printf("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (argc == 5)
	{
		data = init_data(argv, env);
		if (!data)
			return (0); //ERROR
		pipex(data);
	}
	return (0);
}
