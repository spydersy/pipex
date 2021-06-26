/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:11:58 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 10:31:31 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	len_checker(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_strlen(argv[i]) == 0)
			return (1);
	}
	return (0);
}

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
