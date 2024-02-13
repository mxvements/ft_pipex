/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:25:31 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/08 16:25:33 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_dblstrarr(char **strarr)
{
	while (*strarr)
	{
		free(*strarr);
		*strarr = NULL;
		strarr++;
	}
	//free(strarr);
	return (NULL);
}

void	*free_data(t_data *data)
{
	if (data->cmd2_args)
		data->cmd2_args = free_dblstrarr(data->cmd2_args);
	if (data->cmd1_args)
		data->cmd1_args = free_dblstrarr(data->cmd1_args);
	if (data->paths)
		data->paths = free_dblstrarr(data->paths);
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
	free(data);
	data = NULL;
	return (data);
}
