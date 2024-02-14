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
*	./pipex infile.txt ls cat outfile.txt //OK
*
*	EX2 con flags
*	< infile.txt ls -l | cat -e > outfile.txt
*	./pipex infile.txt "ls -l" "cat -e" outfile.txt //OK
*
*	EX3 con contrabarra
*	< infile.txt \ls | \cat > outfile.txt
*	./pipex infile.txt \ls \cat outfile.txt //OK
*
*	EX4 ruta absoluta
*	< infile.txt /bin/ls | /bin/cat > outfile.txt
*	./pipex infile.txt /bin/ls /bin/cat outfile.txt //OK
*
*	EX5 uno con flags y el otro no
*	< infile.txt ls | wc -l > outfile.txt
*	./pipex infile.txt ls "wc -l" outfile.txt //OK
*
*	EX6, unos de los archivos no existe, es NULL, lo gestiona el hijo
*	< "" ls | wc -l > outfile.txt
*	./pipex "" ls "wc -l" outfile.txt //OK
*		bash: : No such file or directory
*		creates outfile.txt (it only contains a \t \t 0)
*
*	EX7 does not execute,"file.txt no such file or directory" no existe infile
*	< file.txt ls | wc -l > outfile.txt
*	./pipiex file.txt ls "wc -l" outfile.txt
*	
*
*	EX9, los archivos son NULL, lo gestionan los hijos
*	./pipex "" ls cat ""
*
*	EX10, los ejecutables son NULL, los gestionan los hijos
*	./pipex infile.txt "" "" outfile.txt
*
*	EX11, siendo /wc (en ruta relativa) un archivo en lugar de un binario
*		 ejecutable
*	< infile.txt /wc | cat > outfile.txt
*	./pipex infile.txt /wc cat outfile.txt
*		bash: /wc: No such file or directory
*	
*	EX12
*	< infile.txt ./wc | cat > outfile.txt
*	./pipex infile.txt ./wc cat outfile.txt
*		bash: ./wc: Permission denied
*
*	archivo de salida /dev/stdout
*/

int	main(int argc, char **argv, char **env)
{
	t_data	*data;

	if (argc != 5)
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	if (argc == 5)
	{
		data = init_data(argv, env);
		if (!data)
			return (0);
		pipex(data);
	}
	return (0);
}
