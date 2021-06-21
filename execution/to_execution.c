/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/21 14:10:09 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int	main()
// {
	// int ret;

	// char *argv[] = {"cat", "to_execution.c", NULL};
	// char *envp[] = {NULL};
	// char *cmd = "/usr/bin/cat";

	// ret = execve(cmd, argv, envp);
	// printf("ERROR[%d]\n", ret);
	// perror(cmd);
	// return (0);
// }

void	to_execution(t_data data)
{
	int		status;
	int		pipes[2];
	pid_t	pid;

	status = 1;
	if (data.fd[0] < 0)
		status = 0;
	pipe(pipes);
	pid = fork();
	if (pid == 0)
	{
		
	}
	else
	{

	}
	printf("[%d][%d]\n", pipes[0], pipes[1]);
	perror(data.content0[0]);
}
