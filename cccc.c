#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main()
{
	char *str = strdup("test00");
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
//		free(str);
		exit (0);
	}
	else
		free(str);
return (0);
}
