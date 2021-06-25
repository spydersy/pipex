/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:17:21 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/25 12:24:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	*file_checker(char *argv[])
{
	int	infile;
	int	outfile;
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	if (fd == NULL)
		ft_error(NULL, 1);
	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	if (infile < 0)
	{	
		ft_putstr_fd(KRED, STDERROR);
		ft_putstr_fd(argv[1], STDERROR);
		ft_putstr_fd(": ", STDERROR);
		ft_error(NULL, 0);
	}
	if (outfile < 0)
	{
		ft_putstr_fd(argv[1], STDERROR);
		ft_putstr_fd(":", STDERROR);
		ft_error(NULL, 0);
	}
	fd[0] = infile;
	fd[1] = outfile;
	return (fd);
}
