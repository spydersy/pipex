/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 05:09:59 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/26 10:25:05 by abelarif         ###   ########.fr       */
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

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define SUCCESS		0
# define NOSUCHFILE		1
# define PERMISSION		126
# define CMDNOTFOUND	127
# define STDIN			0
# define STDOUT			1
# define STDERROR		2
typedef struct s_data
{
	int		*fd;
	int		exit_status;
	char	**content0;
	char	**content1;
	char	**envp;
	char	**paths;
	char	*abs_cmd0;
	char	*abs_cmd1;
}				t_data;

size_t	ft_strlen(const char *s);

t_data	to_execution(t_data data);
t_data	arguments_checker(char *argc[], char *envp[]);
t_data	cmd_checker(char *argv[], char *envp[], int *fd);

void	free_data(t_data data);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_error(char *descriptor, int flag);

char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

int		len_checker(char **argv);
int		*file_checker(char *argv[]);
int		pipex(char *argc[], char *envp[]);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
