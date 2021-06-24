/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:17:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 15:09:37 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int		main(void)
{
	int 	pipes[2];
	int		status;
	char	*argv[] = {"ls", "-la", NULL};
	pid_t	pid0;
	pid_t	pid1;

	if (pipe(pipes) == -1)
		return (-1);
	pid0 = fork();
	if (pid0 == 0)
	{
		dup2(pipes[1], 1);
		close(pipes[0]);
		close(pipes[1]);
		if (execve("/usr/bin/ls", argv, NULL) == -1)
			printf("ERROR EXECVE : ls\n");
		exit(7);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		char *gg[] = {"grep", "main", NULL};
		dup2(pipes[0], 0);
		close(pipes[0]);
		close(pipes[1]);
		if (execve("/usr/bin/grep", gg, NULL) == -1)
			printf("ERROR EXECVE : grep");
		exit(5);
	}
	close(pipes[0]);
	close(pipes[1]);
	waitpid(pid0, &status, 0);
	waitpid(pid1, &status, 0);

	return (0);
}

/*
int		main()
{
	int		fd;
	int		dup;
	char	*buffer = malloc(sizeof(char) * 100);

	fd = open("test_file", O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR FILE [%d]\n", fd);
		return (-1);
	}
	dup = dup2(fd, 0);
	if (dup == -1)
	{
		printf("ERROR DUP [%d]\n", dup);
		return (-1);
	}
	printf("DUP | FD: [%d][%d]\n", dup, fd);
	read(0, buffer, 10);
	printf("[%s]\n", buffer);
	return (0);
}*/
