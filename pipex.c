/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:17:14 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 09:50:14 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    dup_args(char  *argv[], char *envp[])
{
    int     i;
    int     lenargv;
    int     lenenvp;
    
    i = -1;
    lenargv = count(argv);
    lenenvp = count(envp);
    g_args.argv = malloc(sizeof(char *) * (lenargv+ 1));
    g_args.envp = malloc(sizeof(char *) * (lenenvp+ 1));
    if (g_args.envp == NULL || g_args.argv == NULL)
        ft_error(NULL, 1);
    while (argv[++i])
    {
        g_args.argv[i] = ft_strdup(argv[i]);
        if (g_args.argv[i] == NULL)
            ft_error(NULL, 1);
    }
    g_args.argv[i] = NULL;
    i = -1;
    while (envp[++i])
    {
        g_args.envp[i] = ft_strdup(envp[i]);
        if (g_args.envp[i] == NULL)
            ft_error(NULL ,1);
    }
    g_args.envp[i] = NULL;
}

void    pipex(void)
{
    args_checker();
}