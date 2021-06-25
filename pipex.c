/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:13:25 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/25 13:14:51 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char *argc[], char *envp[])
{
	t_data	data;

	data = arguments_checker(argc, envp);
	free_data(data);
	printf("SLAOUI ZAML : %d\n", data.exit_status);
	return (data.exit_status);
}
