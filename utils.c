/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:51:51 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/15 15:10:04 by abelarif         ###   ########.fr       */
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

int     max_of(int i, int j)
{
    if (i < j)
        return (j);
    else
        return (j);
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