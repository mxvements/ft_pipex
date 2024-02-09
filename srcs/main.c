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

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	//./pipex infile.txt "ls -l" "cat -e" outfile.txt
	//./pipex infilex.txt \ls \cat outfile.txt
	// < infile.txt \ls | \wc >  outfile.txt
	if (argc != 5)
		printf("Usage: ./pipex file1 cmd1 cmd2 file2");
	if (argc == 5)
	{
		data = init_data(argv, env);
		if (!data)
			return (0); //ERROR
		pipex(data);
	}
	return (0);
}
