/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/23 13:20:41 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// int main(int argc, char **argv)
// {
//   int pipefd[2];
//   int pid;

//   char *cat_args[] = {"cat", "to_execution.c", NULL};
//   char *grep_args[] = {"grep", "pipefd", NULL};

//   // make a pipe (fds go in pipefd[0] and pipefd[1])

//   pipe(pipefd);

//   pid = fork();

//   if (pid == 0)
//     {
//       // child gets here and handles "grep Villanova"

//       // replace standard input with input part of pipe

//       dup2(pipefd[0], 0);

//       // close unused hald of pipe

//       close(pipefd[1]);

//       // execute grep

//       execvp("grep", );
//     }
//     else
//     {
//       // parent gets here and handles "cat scores"

//       // replace standard output with output part of pipe

//       dup2(pipefd[1], 1);

//       // close unused unput half of pipe

//       close(pipefd[0]);

//       // execute cat

//       execvp("cat", cat_args);
//     }
// }


// int	main()
// {
// 	int ret;

// 	char *argv[] = {"cat", "to_execution.c", NULL};
// 	char *envp[] = {NULL};
// 	char *cmd = "/bin/cat";

// 	ret = execve(cmd, argv, envp);
// 	printf("ERROR[%d]\n", ret);
// 	perror(cmd);
// 	return (0);
// }

void	to_execution(t_data data)
{
	int ret;
	int	status;

	ret = fork();
	if (ret < 0)
		ft_error("FORK", 1);
	if (ret == 0)
	{
		int x = open("gggggggggg", O_RDONLY);
			exit(1);
		
	}
	else
	{
		int f;
		waitpid(ret, &status, 0);
		if (WIFEXITED(status))
		{
			printf("******\n");
			f = WEXITSTATUS(status);
		}
		printf("[%d][%d]", f, status);
	}
}
