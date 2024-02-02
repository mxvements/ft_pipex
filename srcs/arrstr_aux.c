/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:57:08 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/02 15:57:16 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arrstr_print(char **arr)
{
	int	i;

	i = 0;
	ft_putstr_fd(ANSICOLOR_CYAN, 1);
	ft_putstr_fd("PRINTING STR ARRAY: \n", 1);
	while (arr[i] != NULL)
	{
		ft_putstr_fd(arr[i++], 1);
		write(1, "\n", 1);
	}
	ft_putstr_fd(ANSICOLOR_RESET, 1);
}

