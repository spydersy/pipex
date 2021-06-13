/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:51:51 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 09:05:50 by abelarif         ###   ########.fr       */
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

void    files_checker(void)
{
    char    *error_descriptor;

    g_args.infile = open(g_args.argv[1], O_RDONLY);
    g_args.outfile = open(g_args.argv[4], O_WRONLY);
    if (g_args.infile < 0)
    {
        ft_error( "cant open input file", 1);
    }
    if (g_args.outfile < 0)
    {
        ft_error( "cant open output file", 1);        
    }
}

void    cmd_checker(void)
{
    
}

void    args_checker(void)
{
    files_checker();
    cmd_checker();
}