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
# include <sys/wait.h>
# include <errno.h>
# define STDOUT_FILENO
# define STDINT_FILEIN

typedef struct s_data
{
	char	**env;
	char	**argv;
	int		id[2];
}	t_data;

#endif