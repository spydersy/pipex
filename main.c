/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:56:11 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 10:43:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (argc == 5)
	{
		dup_args(argv, envp);
		pipex();
		free_args();
		return (0);
	}
	ft_error("ARGS", 1);
	return (-1);
}
