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
	cmd_args = ft_split(command, ' ');
	if (!cmd_args)
		return (NULL);
	cmd_args = check_cmd_full_path(data, cmd_args);
	if (!cmd_args)
		return (NULL);
	//printf("full path: %s \n", *cmd_args); //TO CHECK
	return (cmd_args);
}

/*t_data	*init_data_struct(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = NULL;
	data->paths = NULL;
	data->cmd1_args = NULL;
	data->cmd2_args = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	return (data);
}*/
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

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = env;
	data->paths = get_paths(env);
	if (!data->paths)
		return (free_data(data));
	//arrstr_print(data->paths); //TO CHECK
	data->cmd1_args = init_cmd_args(data, data->cmd1_args, argv[2]);
	if (!data->cmd1_args)
		return (free_data(data));
	data->cmd2_args = init_cmd_args(data, data->cmd2_args, argv[3]);
	if (!data->cmd1_args)
		return (free_data(data));
	data->infile = init_file_struct(data->infile, argv[1]);
	if (!(data->infile))
		return (free_data(data));
	data->outfile = init_file_struct(data->outfile, argv[4]);
	if (!(data->outfile))
		return (free_data(data));
	return (data);
}
