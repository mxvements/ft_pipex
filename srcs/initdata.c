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

/**
 * @brief	t_data	*init_data(char **argv, char **env)
 * 			note: this function does NOT handle malloc errors on variable
 * 			initalization, all errors should be handled by the children's
 * 			executions 
 * @param argv char **, arguments passed by main
 * @param env char **, environment passed by main
 * @return t_data*, structure with the parsing done
 */
t_data	*init_data(char **argv, char **env)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = env;
	data->paths = get_paths(env);
	if (!data->paths)
		data->paths = ft_calloc(1, sizeof(char *));
	data->cmd1_args = init_cmd_args(data, data->cmd1_args, argv[2]);
	data->cmd2_args = init_cmd_args(data, data->cmd2_args, argv[3]);
	data->infile = init_file_struct(data->infile, argv[1]);
	data->outfile = init_file_struct(data->outfile, argv[4]);
	return (data);
}
