/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:11:58 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/25 13:32:17 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// void	error_descr(int err, )
// {
// 		ft_putstr_fd(KRED, STDERROR);
// 		ft_putstr_fd(argv[1], STDERROR);
// 		ft_putstr_fd(": ", STDERROR);
// 		ft_error(NULL, 0);
// }

void	ft_error(char *descriptor, int flag)
{
	char	*err;

	err = NULL;
	ft_putstr_fd(KRED, STDERROR);
	if (descriptor != NULL)
		ft_putstr_fd(descriptor, STDERROR);
	else
		perror(err);
	ft_putstr_fd(KWHT, STDERROR);
	if (flag == 1)
		exit(EXIT_FAILURE);
}
