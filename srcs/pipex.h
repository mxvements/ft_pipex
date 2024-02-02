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
# include "../libft/libft.h"
//COLORS
# define ANSICOLOR_GRAY		"\x1b[30m"
# define ANSICOLOR_RED		"\x1b[31m"
# define ANSICOLOR_GREEN	"\x1b[32m"
# define ANSICOLOR_YELLOW	"\x1b[33m"
# define ANSICOLOR_BLUE		"\x1b[34m"
# define ANSICOLOR_MAGENTA	"\x1b[35m"
# define ANSICOLOR_CYAN		"\x1b[36m"
# define ANSICOLOR_RESET	"\x1b[0m"
//FILES DESCRIPTOR
# define READ_END		0
# define WRITE_END		1

typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_file
{
	char	*path;
	int		fd;
}	t_file;

typedef struct s_data
{
	int		id[2];
	int		fd_pipe[2];
	char	**env;
	char	**paths;
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	t_file	*infile;
	t_file	*outfile;
}	t_data;

/* DATA STRUCT FUNCTS */
t_data	*init_data(char **argv, char **env);
void	*free_data(t_data *data);
/* PATH */
char	**get_paths(char **env);
/* STR ARRAYS */
void	arrstr_print(char **arr);
#endif