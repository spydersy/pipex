/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 12:21:45 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 17:56:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_str_arr(char **str_arr)
{
	int		i;

	i = -1;
	while (str_arr[++i])
	{
		free(str_arr[i]);
		str_arr[i] = NULL;
	}
	free(str_arr);
	str_arr = NULL;
}

void	free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_int(int *arr)
{
	free(arr);
	arr = NULL;
}

void	free_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	free_data(t_data data)
{
	free_str_arr(data.content0);
	free_str_arr(data.content1);
	free_str_arr(data.paths);
	free_str_arr(data.envp);
	free_str(data.abs_cmd0);
	free_str(data.abs_cmd1);
	free_fd(data.fd);
	free_int(data.fd);
}
