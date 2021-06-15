/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:10:17 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/15 15:35:09 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(void)
{
    int     i;

    i = -1;
    while (g_args.envp[++i])
    {
        if (ft_strncmp(g_args.envp[i], "PATH=", 5) == 0)
        {
            return (g_args.envp[i] + 5);    
        }
    }
    return (NULL);
}

void    check_cmd(char **cmd)
{
    int     i;
    char    *absolut_path;

    i = -1;
    while (g_args.paths[++i])
    {
        absolut_path =ft_strjoin(g_args[i], );        
    }
}

void    which_cmd()
{
    char **cmd0;
    char **cmd1;

    cmd0 = ft_split(g_args.argv[2], ' ');//free
    cmd1 = ft_split(g_args.argv[2], ' ');//free
    check_cmd(cmd0);
    check_cmd(cmd1);
}

void    cmd_checker(void)
{
    char    **paths;

    g_args.paths = ft_split(get_path(), ':');
    which_cmd();
}