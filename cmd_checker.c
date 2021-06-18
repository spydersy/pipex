/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:42:44 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 13:39:49 by abelarif         ###   ########.fr       */
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

void	replace_paths(char **paths, char **argv)
{
	int		i;
	char	*tmp0;
	char	*tmp1;

	i = -1;
	while (paths[++i])
	{
		tmp0 = ft_strjoin(paths[i], "/");
		tmp1 = ft_strjoin(tmp0, argv[2]);
		free(tmp0);
		tmp0 = NULL;
		if (open(tmp1, O_RDONLY))
		{
			break ;
		}
		free(tmp1);
		tmp1 = NULL;
	}
}

void	find_cmd_current_path(void) // NOT NOW
{

}

void    cmd_checker(char *argv[], char *envp[], int *fd)
{
	t_data	data;
	
	// printf("[%d][%d]", fd[0], fd[1]);
	data.content0 = ft_split(argv[2], ' ');
	data.content1 = ft_split(argv[3], ' ');
	data.paths = get_paths(envp);
	if (data.paths != NULL)
	{
		replace_paths(data.paths, argv);
		return ;
	}
		/*	ENV VAR(PATH) NOT FOUND	*/
		/*	SEARCH IN CURRENT PATH	*/
		find_cmd_current_path(); //NOT NOW
}