/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:36:18 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/02 16:36:25 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_data(t_data *data)
{
	if (data->cmd2)
		free(data->cmd2);
	if (data->cmd1)
		free(data->cmd1);
	if (data->outfile)
		free(data->outfile);
	if (data->infile)
		free(data->infile);
	if (data->paths) //DOUBLE PTR FREE
		free(data->paths);
	free(data);
	data = NULL;
	return (data);
}

t_file	*init_file_struct(t_file *file)
{
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	return (file);
}

t_cmd	*init_cmd_struct(t_cmd *cmd)
{
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	return (cmd);
}

t_data	*init_data_struct(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = NULL;
	data->paths = NULL;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	return (data);
}

t_data	*init_data(char **argv, char **env)
{
	t_data	*data;
	(void)argv;

	data = NULL;
	data = init_data_struct(data);
	if (!data)
		return (NULL);
	data->env = env;
	data->paths = get_paths(env);
	if (!data->paths)
		return (free_data(data));
	arrstr_print(data->paths); //TO CHECK
	data->infile = init_file_struct(data->infile);
	if (!(data->infile))
		return (free_data(data));
	data->outfile = init_file_struct(data->outfile);
	if (!(data->outfile))
		return (free_data(data));
	data->cmd1 = init_cmd_struct(data->cmd1);
	if (!data->cmd1)
		return (free_data(data));
	data->cmd2 = init_cmd_struct(data->cmd2);
	if (!data->cmd2)
		return (free_data(data));
	return (data);
}
