/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 18:00:04 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	second_command(t_data data, int *fdes)
{
	if (fdes[0] || data.fd[1])
	{
		
	}
}

void	first_command(t_data data, int *fdes)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(NULL, 1);
	if (pid == 0)
	{
		if (data.fd[0] == -1)
			exit (NOSUCHFILE);
		if (dup2(data.fd[0], STDIN) == -1)
			ft_error(NULL, 1);
		if (execve(data.abs_cmd0, data.content0, NULL) == -1)
			ft_error(NULL, 1);
	}
	
}

t_data	to_execution(t_data data)
{
	int	fdes[2];

	if (pipe(fdes) == -1)
		ft_error(NULL, 1);
	printf("FDES : [%d][%d]\n", fdes[0], fdes[1]);
	first_command(data, fdes);
	second_command(data,fdes);
	return (data);
}
