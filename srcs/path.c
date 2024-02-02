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
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	varenv = env[i];
	equals_idx = ft_strchri(varenv, '=') + 1;
	paths = ft_split((varenv + equals_idx), ':');
	if (!paths)
		return (NULL);
	return (paths);
}
