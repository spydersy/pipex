/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:56:11 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 10:53:01 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	dup_args(argv, envp);
	if (argc == 5)
	{
		pipex();
		free_args();
		return (0);
	}
	ft_error("ARGS", 1);
	return (-1);
}
