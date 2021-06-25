/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:17:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/25 13:29:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int			main()
{
	char	*argv[] = {"cmd", "vfdsv", NULL};
	char	*str;

	if (execve("/bin/", argv, NULL) == -1)
		perror(str);
}

// int		main(void)
// {
// 	int 	pipes[2];
// 	int		status;
// 	char	*argv[] = {"ls", "-la", NULL};
// 	pid_t	pid0;
// 	pid_t	pid1;

// 	if (pipe(pipes) == -1)
// 		return (-1);
// 	pid0 = fork();
// 	if (pid0 == 0)
// 	{
// 		dup2(pipes[1], 1);
// 		close(pipes[0]);
// 		close(pipes[1]);
// 		if (execve("/usr/bin/ls", argv, NULL) == -1)
// 			printf("ERROR EXECVE : ls\n");
// 		exit(7);
// 	}
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		char *gg[] = {"grep", "main", NULL};
// 		dup2(pipes[0], 0);
// 		close(pipes[0]);
// 		close(pipes[1]);
// 		if (execve("/usr/bin/grep", gg, NULL) == -1)
// 			printf("ERROR EXECVE : grep");
// 		exit(5);
// 	}
// 	close(pipes[0]);
// 	close(pipes[1]);
// 	waitpid(pid0, &status, 0);
// 	waitpid(pid1, &status, 0);

// 	return (0);
// }
