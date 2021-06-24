/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:17:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 18:45:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		main(void)
{
	int 	pipes[2];
	char	*argv[] = {"ls", "-l", "-a", NULL};
	pid_t	pid;

	if (pipe(pipes) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipes[1], 1);
	//	close(pipes[0]);
		close(pipes[1]);
		if (execve("/bin/ls", argv, NULL) == -1)
			printf("ERROR EXECVE : ls\n");
	}
	pid = fork();
	if (pid == 0)
	{
		char *gg[] = {"grep", "main", NULL};
		dup2(pipes[0], 0);
		close(pipes[0]);
	//	close(pipes[1]);
		if (execve("/usr/bin/grep", gg, NULL) == -1)
			printf("ERROR EXECVE : grep");
	}
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
