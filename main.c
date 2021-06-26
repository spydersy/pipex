/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:11:01 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 11:30:52 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	if (len_checker(argv))
	{
		ft_error("ERROR: ARGS\n", 1);
		return (-1);
	}
	if (argc == 5)
	{
		return (pipex(argv, envp));
	}
	ft_error("ERROR: ARGS\n", 1);
	return (-1);
}
