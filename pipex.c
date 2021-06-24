/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:13:25 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 12:44:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char *argc[], char *envp[])
{
	t_data	data;

	data = arguments_checker(argc, envp);
	free_data(data);
	return (0);
}
