/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:09:59 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/18 12:20:16 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

/*      COLORS          */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct  s_data
{
    char    **content0;
	char    **content1;
	char    **paths;
}               t_data;

void    file_checker(char *argv[]);
void    ft_error(char *descriptor, int flag);
void    cmd_checker(char *argv[], char *envp[]);

int     pipex(char *argc[], char *envp[]);
int     arguments_checker(char *argc[], char *envp[]);
#endif
