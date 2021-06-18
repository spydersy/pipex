/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:11:58 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 12:26:36 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_error(char *descriptor, int flag)
{
    char    *err;

    err = NULL;
    ft_putstr_fd(KRED, 2);
    if (descriptor!= NULL)
        ft_putstr_fd(descriptor, 2);
    else
        perror(err);
    if (flag == 1)
        exit(EXIT_FAILURE);
}