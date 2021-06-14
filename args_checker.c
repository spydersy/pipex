/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:57:35 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/14 14:55:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_cmd(char *cmd0, char *cmd1)
{
    int         i;

    i = -1;
    while (cmd0[++i])
    {
        free(cmd0[i]);
        cmd0[i] = NULL;
    }
    i = -1;
    while (cmd1[++i])
    {
        free(cmd1[i]);
        cmd1[i] = NULL;
    }
    free(cmd0);
    free(cmd1);
    cmd0 = NULL;
    cmd1 = NULL;
}

void    existence(char *cmd0, char *cmd1)
{
    if ()
}

void    which_cmd(char **cmd0, char **cmd1, char **paths)
{
    int     i;
    int     index;
    char    *tmp0;
    char    *tmp1;

    i = -1;
    while (paths[++i])
    {
        index = 0;
        if (i == 0)
            index = 5;
        tmp0 = ft_strjoin(paths[i] + index, cmd0);
        tmp1 = ft_strjoin(paths[i] + index, cmd1);
        if ()
    }
}

char    *paths_finder(char **cmd0, char **cmd1)
{
    int     i;

    i = -1;
    while (g_args.envp[++i])
        if (ft_strncmp(g_args.envp[i],
            "PATH=", max_of(ft_strlen(g_args.envp[i]), 5)) == 0)
            return (g_args.envp[i]);
    free_cmd(cmd0, cmd1);
    ft_error("Cant find environnement variable : \"PATH\"",1);
    return (NULL);
}

char    **get_paths(char **cmd0, char **cmd1)
{
    int     i;
    int     fd;
    char    **paths;
    char    *env_var;

    env_var = paths_finder(cmd0, cmd1);
    paths = ft_split(env_var, ':');
    which_cmd(cmd0, cmd1, paths);
    if (paths == NULL)
        ft_error(NULL, 1);
    return (paths);
}

void    cmd_checker(void)
{
    // int     fdcmd0;
    // int     fdcmd1;
    char    **content0;
    char    **content1;
    char    **paths;
   
    content0 = ft_split(g_args.argv[2], ' ');
    content1 = ft_split(g_args.argv[3], ' ');
    if (content0 == NULL || content1 == NULL)
        ft_error(NULL, 1);
    paths = get_paths(content0, content1);
    // fdcmd0 = open(content0[0], O_RDONLY);
    // fdcmd1 = open(content1[0], O_RDONLY);
}

void    files_checker(void)
{
    g_args.infile = open(g_args.argv[1], O_RDONLY);
    g_args.outfile = open(g_args.argv[4], O_WRONLY | O_CREAT, 0666);
    if (g_args.infile < 0)
    {
        ft_error( "No such file (infile)", 1);
    }
    if (g_args.outfile < 0)
    {
        ft_error( "cant open output file", 1);
    }
}

void    args_checker(void)
{
    files_checker();
    cmd_checker();
}
