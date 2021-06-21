/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:14:41 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/21 12:14:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	arguments_checker(char *argc[], char *envp[])
{
	int	*fd;

	fd = file_checker(argc);
	cmd_checker(argc, envp, fd);
		printf("TEST\n");

	return (0);
}
