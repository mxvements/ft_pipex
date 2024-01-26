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
	data->id[0] = fork();
}

void	secondcommand(t_data *data)
{
	data->id[1] = fork();
}

void	pipex(t_data *data)
{
	firstcommand(data);
	secondcommand(data);
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
		data = initdata();
		if (!data)
			return (0); //ERROR
		data->env = env;
		data->argv = argv;
		pipex(data);
	}
	return (0);
}
