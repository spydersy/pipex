/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 11:07:10 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	command_not_found(char *cmd, int exitstatus)
{
	ft_putstr_fd(KRED, STDERROR);
	ft_putstr_fd("command not found: ", STDERROR);
	ft_putstr_fd(cmd, STDERROR);
	ft_putstr_fd("\n", STDERROR);
	exit(exitstatus);
}

pid_t	first_command(t_data data, int *fdes)
{
	pid_t	pid0;

	pid0 = fork();
	if (pid0 == -1)
		ft_error(NULL, 1);
	if (pid0 == 0)
	{
		if (data.fd[0] == -1)
			exit(NOSUCHFILE);
		if (data.abs_cmd0 == NULL)
		{
			command_not_found(data.content0[0], CMDNOTFOUND);
		}
		if (dup2(fdes[1], STDOUT) == -1 || dup2(data.fd[0], STDIN) == -1)
			ft_error(NULL, 1);
		close(fdes[0]);
		close(fdes[1]);
		if (execve(data.abs_cmd0, data.content0, data.envp) == -1)
			ft_error(NULL, 1);
		exit (0);
	}
	return (pid0);
}

pid_t	second_command(t_data data, int *fdes)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		ft_error(NULL, 1);
	if (pid1 == 0)
	{
		if (data.fd[1] == -1)
			exit(NOSUCHFILE);
		if (data.abs_cmd1 == NULL)
		{
			command_not_found(data.content1[0], CMDNOTFOUND);
		}
		if (dup2(fdes[0], STDIN) == -1 || dup2(data.fd[1], STDOUT) == -1)
			ft_error(NULL, 1);
		close(fdes[0]);
		close(fdes[1]);
		if (execve(data.abs_cmd1, data.content1, data.envp) == -1)
			ft_error(NULL, 1);
		exit (0);
	}
	return (pid1);
}

t_data	to_execution(t_data data)
{
	int		fdes[2];
	int		status[2];
	pid_t	pid0;
	pid_t	pid1;

	if (pipe(fdes) == -1)
		ft_error(NULL, 1);
	pid0 = first_command(data, fdes);
	pid1 = second_command(data, fdes);
	close(fdes[0]);
	close(fdes[1]);
	waitpid(pid0, &status[0], 0);
	waitpid(pid1, &status[1], 0);
	if (WIFEXITED(status[1]))
	{
		data.exit_status = WEXITSTATUS(status[1]);
	}
	return (data);
}
