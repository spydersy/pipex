/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:42:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/21 13:06:15 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_paths(char *envp[])
{
	int		i;
	int		cmp;
	char	**paths;

	i = -1;
	while (envp[++i])
	{
		cmp = ft_strncmp(envp[i], "PATH=", 5);
		if (cmp == 0)
			break ;
	}
	if (envp[i] == NULL)
		return (NULL);
	else
	{
		paths = ft_split(envp[i] + 6, ':');
		if (paths == NULL)
			ft_error(NULL, 1);
		return (paths);
	}
}

void	join_bs(char **paths)
{
	int		i;
	char	*tmp;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
	}	
}

void	find_cmd_current_path(char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin("./", cmd);
	if (tmp == NULL)
		ft_error(NULL, 1);
	if (open(tmp, O_RDONLY) < 0)
	{
		free(tmp);
		tmp = NULL;
		cmd = NULL;
	}
	else
	{
		cmd = tmp;
	}
}

void	match_paths(t_data data, char *cmd, char **abs_cmd)
{
	int		i;
	char	*tmp;
	int		fd;

	i = -1;
	while (data.paths[++i])
	{
		tmp = ft_strjoin(data.paths[i], cmd);
		fd = open(tmp, O_RDONLY);
		if (fd < 0)
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			*abs_cmd = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
			close(fd);
			break ;
		}
	}
	find_cmd_current_path(cmd);
}

void	cmd_checker(char *argv[], char *envp[], int *fd)
{
	t_data		data;
	static int	first_time = 1;

	data.content0 = ft_split(argv[2], ' ');
	data.content1 = ft_split(argv[3], ' ');
	data.paths = get_paths(envp);
	data.fd = fd;
	if (first_time == 1)
	{
		join_bs(data.paths);
		first_time = 0;
	}
	if (data.paths != NULL)
	{
		match_paths(data, data.content0[0], &data.abs_cmd0);
		match_paths(data, data.content1[0], &data.abs_cmd1);
		to_execution(data);
		return ;
	}
	find_cmd_current_path(data.content0[0]);
	find_cmd_current_path(data.content1[0]);
	to_execution(data);
}
