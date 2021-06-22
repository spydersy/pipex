/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/22 16:15:25 by abelarif         ###   ########.fr       */
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
	int		fds[2];
	int		wstatus;
	pid_t	ret;
	int	WEXITSTATUS = 0;
	
	if (pipe(fds) == -1)
		ft_error(NULL, 1);
	ret = fork();
	if (ret == 0)
	{
		printf("CHILD [%d]\n", ret);
		printf("open : [%d]\n", open("vdfsvdsfvfdb", O_RDONLY));
		printf("***********************\n");
		exit(EXIT_FAILURE);
	//	perror("error child");
		
	}
	else
	{
	//	wstatus = 0;
	
		printf("wait : [%d]\n", waitpid(ret, &wstatus, WEXITSTATUS));
		printf("WSTATUS : [%d]\n", wstatus % 255);
		printf("PARENT [%d]\n", ret);
	//	perror("error");
		exit(wstatus % 255);
	}
}
