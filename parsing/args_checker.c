/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:14:41 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 12:57:42 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_data	arguments_checker(char *argc[], char *envp[])
{
	int		*fd;
	t_data	data;

	fd = file_checker(argc);
	data = cmd_checker(argc, envp, fd);
	return (data);
}
