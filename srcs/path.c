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
	char	**paths;
	char	*tmp;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split((env[i] + 5), ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		if (!(paths[i]))
			return (NULL);
		free(tmp);
	}
	return (paths);
}

char	**check_cmd_full_path(t_data *data, char **cmd_args)
{
	char	*full_path;
	int		i;

	if (cmd_args[0] == '\0')
		return (NULL);
	if (ft_strchr(cmd_args[0], '/') != NULL)
		return (cmd_args);
	i = -1;
	while ((data->paths[++i]))
	{
		full_path = ft_strjoin(data->paths[i], cmd_args[0]);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
		{
			free(cmd_args[0]);
			cmd_args[0] = full_path;
			break ;
		}
		free(full_path);
	}
	return (cmd_args);
}
