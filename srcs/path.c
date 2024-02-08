/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:37:12 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/02 14:37:23 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	*varenv;
	int		equals_idx;
	char	**paths;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	varenv = env[i];
	equals_idx = ft_strchri(varenv, '=') + 1;
	paths = ft_split((varenv + equals_idx), ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	**check_cmd_full_path(t_data *data, char **cmd_args)
{
	char	*full_path;
	char	*tmp;

	if (access(cmd_args[0], F_OK) == 0)
		return (cmd_args);
	tmp = cmd_args[0];
	cmd_args[0] = ft_strjoin("/", tmp);
	if (!(cmd_args[0]))
		return (NULL);
	free(tmp);
	while (*(data->paths))
	{
		full_path = ft_strjoin(*data->paths, cmd_args[0]);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
		{
			cmd_args[0] = full_path;
			break;
		}
		(data->paths)++;
		free(full_path);
	}
	return (cmd_args);
}
