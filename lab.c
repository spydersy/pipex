/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:17:53 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 15:11:19 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

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
}
