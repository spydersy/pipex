/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:42:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 19:31:36 by abelarif         ###   ########.fr       */
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
		return (ft_split("", '\0'));
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
	if (paths == NULL)
		return ;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = tmp;
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
		fd = open(tmp, O_RDONLY, 0666);
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
			return ;
		}
	}
	*abs_cmd = ft_strdup(cmd);
}

char	**get_envp(char **envp)
{
	char	**arr;
	int		i;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		ft_error(NULL, 1);
	i = -1;
	while (envp[++i])
	{
		arr[i] = ft_strdup(envp[i]);
		if (arr[i] == NULL)
			ft_error(NULL, 1);
	}
	arr[i] = NULL;
	return (arr);
}

t_data	cmd_checker(char *argv[], char *envp[], int *fd)
{
	t_data		data;
	static int	first_time = 1;

	data.content0 = ft_split(argv[2], ' ');
	data.content1 = ft_split(argv[3], ' ');
	data.envp = get_envp(envp);
	data.paths = get_paths(data.envp);
	data.fd = fd;
	if (first_time == 1)
	{
		join_bs(data.paths);
		first_time = 0;
	}
	if (data.paths != NULL)
	{
		match_paths(data, data.content0[0], &(data.abs_cmd0));
		match_paths(data, data.content1[0], &(data.abs_cmd1));
	}
	else
	{
		data.abs_cmd0 = ft_strdup(data.content0[0]);
		data.abs_cmd1 = ft_strdup(data.content1[0]);
	}
	return (to_execution(data));
}
