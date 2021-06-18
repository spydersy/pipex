/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:17:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 05:25:14 by abelarif         ###   ########.fr       */
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

    }
    if (outfile < 0)
    {
        
    }
}