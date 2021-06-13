/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:57:35 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 13:19:48 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void    cmd_checker(void)
{
    
}

void    args_checker(void)
{
    files_checker();
    cmd_checker();
}