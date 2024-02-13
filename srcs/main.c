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

/*	EXAMPLES
*
*	EX1 'normal'
*	< infile.txt ls | cat > outfile.txt
*	./pipex infile.txt ls cat outfile.txt
*
*	EX2 con flags
*	< infile.txt ls -l | cat -e outfile.txt
*	./pipex infile.txt "ls -l" "cat -e" > outfile.txt
*
*	EX3 con contrabarra
*	< infile.txt \ls | \cat outfile.txt
*	./pipex infilex.txt \ls \cat outfile.txt
*
*	EX4 ruta absoluta
*	< infile.txt /bin/ls | /bin/cat > outfile.txt
*	./pipex infile.txt /bin/ls /bin/cat outfile.txt
*
*	EX5 uno con flags y el otro no
*	< infile.txt ls | wc -l > outfile.txt
*	./pipex infile.txt ls "wc -l" outfile.txt
*
*	EX6
*	< "" ls | wc -l outfile.txt
*	./pipex "" ls "wc -l" outfile.txt
*	0 en el archivo, el primer comando no se ejecuta
*
*	EX7
*	< file.txt ls | wc -l > outfile.txt
*	./pipiex file.txt ls "wc -l" outfile.txt
*	does not execute,"file.txt no such file or directory"
*
*	EX9
*	./pipex "" "" "" ""
*
*
*	distintos comandos
*		wc como ultimo comando
*	infile.txt que no existe, str vacio ""
*	quitar entorno
*	quitar las variable PATH
*
*/
int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 5)
		printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	if (argc == 5)
	{
		data = init_data(argv, env);
		if (!data)
			return (0);
		pipex(data);
	}
	return (0);
}
