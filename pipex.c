/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:13:25 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 10:36:53 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char *argc[], char *envp[])
{
	t_data	data;

	data = arguments_checker(argc, envp);
	free_data(data);
	return (data.exit_status);
}
