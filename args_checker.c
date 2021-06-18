/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:14:41 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 13:33:51 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     arguments_checker(char *argc[], char *envp[])
{
    int     *fd;

    fd = file_checker(argc);
    cmd_checker(argc, envp, fd);
    return (0);
}