/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:09:59 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 11:00:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

/*      COLORS          */
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

/*		ERRORS			*/
# define SUCCESS		0
# define NOSUCHFILE		1
# define PERMISSION		126
# define CMDNOTFOUND	127

typedef struct s_data
{
	int		*fd;
	int		exitstat;
	char	**content0;
	char	**content1;
	char	*filein;
	char	*fileout;
	char	**paths;
	char	*abs_cmd0;
	char	*abs_cmd1;
	int		*pipes;
}				t_data;

size_t	ft_strlen(const char *s);

void	ft_error(char *descriptor, int flag);
void	to_execution(t_data data);
void	cmd_checker(char *argv[], char *envp[], int *fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);

int		pipex(char *argc[], char *envp[]);
int		*file_checker(char *argv[]);
int		arguments_checker(char *argc[], char *envp[]);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
