/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:51:51 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 13:00:32 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     count(char **arr)
{
    int     i;

    i = 0;
    while (arr[i])
    {
        i++;
    }
    return (i);
}

void    free_args(void)
{
    int i;

    i = -1;
    while (g_args.argv[++i])
    {
        free(g_args.argv[i]);
        g_args.argv[i] = NULL;
    }
    free(g_args.argv[i]);
    g_args.argv[i] = NULL;
    free(g_args.argv);
    g_args.argv = NULL;
    i = -1;
    while (g_args.envp[++i])
    {
        free(g_args.envp[i]);
        g_args.envp[i] = NULL;
    }
    free(g_args.envp[i]);
    g_args.envp[i] = NULL;
    free(g_args.envp);
    g_args.envp = NULL;
}