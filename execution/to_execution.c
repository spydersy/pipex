/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 13:04:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_command(t_data data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(NULL, 1);
	if (pid == 0)
	{
		
	}
}

t_data	to_execution(t_data data)
{
	first_command(data);
	return (data);
}
