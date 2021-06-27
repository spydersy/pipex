/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 08:34:31 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/27 08:35:02 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	command_not_found(char *cmd, int exitstatus)
{
	ft_putstr_fd(KRED, STDERROR);
	ft_putstr_fd("command not found: ", STDERROR);
	ft_putstr_fd(cmd, STDERROR);
	ft_putstr_fd("\n", STDERROR);
	ft_putstr_fd(KWHT, 2);
	exit(exitstatus);
}

void	permission_denied(char *cmd, int exitstatus)
{
	ft_putstr_fd(KRED, STDERROR);
	ft_putstr_fd("Permission denied: ", STDERROR);
	ft_putstr_fd(cmd, STDERROR);
	ft_putstr_fd("\n", STDERROR);
	ft_putstr_fd(KWHT, 2);
	exit(exitstatus);
}

void	nosuchfile(char *cmd, int exitstatus)
{
	ft_putstr_fd(KRED, STDERROR);
	ft_putstr_fd("No such file or directory: ", STDERROR);
	ft_putstr_fd(cmd, STDERROR);
	ft_putstr_fd("\n", STDERROR);
	ft_putstr_fd(KWHT, 2);
	exit(exitstatus);
}

int	nosuchfile_condition(char *abs, char *cmd)
{
	int		cmp;
	int		max_len;
	int		len_cmd;
	int		len_abs;

	len_abs = ft_strlen(abs);
	len_cmd = ft_strlen(cmd);
	max_len = max(len_abs, len_cmd);
	cmp = ft_strncmp(cmd, abs, max_len);
	if (abs == NULL)
		return (1);
	else if (cmp == 0 && open(abs, O_RDONLY) == -1)
		return (1);
	return (0);
}
