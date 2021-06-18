/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:42:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 18:10:52 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **get_paths(char *envp[])
{
	int     i;
	int     cmp;
	char    **paths;

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

void	match_paths(char **paths, t_data data)
{
	
}

void	find_cmd_current_path(void) // NOT NOW
{

}

void    cmd_checker(char *argv[], char *envp[], int *fd)
{
	t_data	data;
	
	data.content0 = ft_split(argv[2], ' ');
	data.content1 = ft_split(argv[3], ' ');
	data.paths = get_paths(envp);
	data.fd = fd;
	printf("[%d][%d]", data.fd[0], data.fd[1]);
	if (data.paths != NULL)
	{
		match_paths(data.paths, data);
		return ;
	}
		/*	ENV VAR(PATH) NOT FOUND	*/
		/*	SEARCH IN CURRENT PATH	*/
		find_cmd_current_path(); //NOT NOW
}