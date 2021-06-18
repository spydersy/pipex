/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:14:41 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 12:20:50 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     arguments_checker(char *argc[], char *envp[])
{
    file_checker(argc);
    cmd_checker(argc, envp);
    return (0);
}