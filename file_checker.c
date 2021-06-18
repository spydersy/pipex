/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:17:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 12:24:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    file_checker(char *argv[])
{
    int infile;
    int outfile;

    infile = open(argv[1], O_RDONLY);
    outfile = open(argv[4], O_WRONLY | O_CREAT, 0666);

    if (infile < 0)
    {
        
        ft_putstr_fd(KRED, 2);
        ft_putstr_fd(argv[1], 2);
        ft_putstr_fd(": ", 2);
        ft_error(NULL, 0);
    }
    if (outfile < 0)
    {
        ft_putstr_fd(argv[1], 2);
        ft_putstr_fd(":", 2);
        ft_error(NULL, 0);
    }
}