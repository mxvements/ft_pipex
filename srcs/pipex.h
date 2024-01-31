/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:09:09 by luciama2          #+#    #+#             */
/*   Updated: 2024/01/26 13:09:11 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
 #include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# define READ_END		0
# define WRITE_END		1

typedef struct s_file
{
	int		fd;
	char	*path;
}	t_file;

typedef struct s_data
{
	int		id[2];
	int		fd_pipe[2];
	char	**env;
	char	*cmd1;
	char	*cmd2;
	t_file	*infile;
	t_file	*outfile;
}	t_data;

#endif