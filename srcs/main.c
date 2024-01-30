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

/*void	firstcommand(t_data *data)
{

}

void	secondcommand(t_data *data)
{

}*/

void	pipex(t_data *data)
{
	/*	1sr fork()
		2nd	pipe()
		childs will inherit parent's fd's
	*/
	pipe(data->fd_pipe);
	data->id[0] = fork();
	if (data->id[0] == 0) /* child process - cmd1 */
	{
		close(data->fd_pipe[READ_END]); //first command writes on the pipe fd
		dup2(data->fd_pipe[WRITE_END], STDOUT_FILENO);
		close(data->fd_pipe[WRITE_END]);
		/*	execve
			(1) env path 
			(2) char **args, {cm1, argv1, argv2, NULL} params of the program
			(3) env, passed with the main
		*/
		char *argvchild2[] = {"/bin/ls", "-l", NULL};
		execve("/bin/ls", argvchild2, data->env);
	}
	else /* parent process -> does another child for cmd2*/
	{	
		data->id[1] = fork();
		if (data->id[1] == 0) /* child process - cmd2 */
		{
			//data->fd_out = open();
			close(data->fd_pipe[WRITE_END]);
			dup2(data->fd_pipe[READ_END], STDIN_FILENO);
			close(data->fd_pipe[READ_END]);
			//execve
			char *argvchild2[] = {"/bin/cat", "-e", NULL};
			execve("/bin/cat", argvchild2, data->env);
		}
		else
		{
			close(data->fd_pipe[WRITE_END]);
			close(data->fd_pipe[READ_END]);
		}
		
	}
}

static t_data	*initdata(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return NULL;
	data->env = NULL;
	data->argv = NULL;
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 5)
		printf("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (argc == 5)
	{
		data = initdata(); //bzero
		if (!data)
			return (0); //ERROR
		data->env = env;
		data->argv = argv;
		pipex(data);
	}
	return (0);
}
