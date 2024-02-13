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

char	**init_cmd_args(t_data *data, char **cmd_args, char *command)
{
	/*if (*command == '0')
		return (NULL);*/
	cmd_args = ft_split(command, ' ');
	if (!cmd_args || !(*cmd_args))
		return (NULL);
	cmd_args = check_cmd_full_path(data, cmd_args);
	if (!cmd_args)
		return (NULL);
	//printf("full path: %s \n", *cmd_args); //TO CHECK
	return (cmd_args);
}

t_file	*init_file_struct(t_file *file, char *name)
{
	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->path = name;
	return (file);	
}

t_data	*init_data(char **argv, char **env)
{
	t_data	*data;

	/*if (*argv[2] == '\0' || *argv[3] == '\0')
		return (NULL);*/
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = env;
	data->paths = get_paths(env);
	if (!data->paths)
		return (free_data(data));
	data->cmd1_args = init_cmd_args(data, data->cmd1_args, argv[2]);
	/*if (!(data->cmd1_args))
		return (free_data(data));*/
	data->cmd2_args = init_cmd_args(data, data->cmd2_args, argv[3]);
	/*if (!(data->cmd1_args))
		return (free_data(data));*/
	data->infile = init_file_struct(data->infile, argv[1]);
	/*if (!(data->infile))
		return (free_data(data));*/
	data->outfile = init_file_struct(data->outfile, argv[4]);
	/*if (!(data->outfile))
		return (free_data(data));*/
	return (data);
}
