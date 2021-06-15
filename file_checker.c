/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:09:33 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/15 15:27:04 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    files_checker(void)
{
	g_args.infile = open(g_args.argv[1], O_RDONLY);
	g_args.outfile = open(g_args.argv[4], O_WRONLY | O_CREAT, 0666);
	if (g_args.infile < 0)
	{
		ft_error( ft_strjoin("no such file or directory: ",
		g_args.argv[1]), 1);
	}
	if (g_args.outfile < 0)
	{
		ft_error( ft_strjoin("cant open output file: ",
		g_args.argv[4]), 1);
	}
	//close file descriptors;
}