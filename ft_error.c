/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 07:33:18 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/13 09:06:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_error(char *error, int descriptor)
{
    char    *errdescriptor;

    ft_putstr_fd(KRED, 2);
    ft_putstr_fd("ERROR", 2);
    if (error == NULL)
        perror(errdescriptor);
    else
    {
        ft_putstr_fd(":\n", 2);
        ft_putstr_fd(error, 2);
    }
    if (descriptor == 1)
    {
        free_args();
        exit(EXIT_FAILURE);
    }
}
