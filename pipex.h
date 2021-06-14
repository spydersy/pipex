/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:56:33 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/14 12:47:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "./libft/libft.h"

/*      COLORS          */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct s_args
{
    char        **argv;
    char        **envp;
    int         infile;
    int         outfile;
}               t_args;

t_args          g_args;

int     count(char **arr);
int     max_of(int i, int j);

void    pipex(void);
void    free_args(void);
void    args_checker(void);
void    ft_error(char *error, int descriptor);
void    dup_args(char  *argv[], char *envp[]);

#endif
