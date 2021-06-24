/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 10:19:27 by abelarif         ###   ########.fr       */
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

// void	to_execution(t_data data)
// {
    // printf("[%d][%d][%s][%s][%s][%s]\n", data.fd[0], data.fd[1],
    // data.abs_cmd0, data.abs_cmd1,
    // data.content0[0], data.content1[0]);
    // int pid = fork();
    // int status;
    // if (pid == 0)
    // {
        // printf("child0\n");
    // }
    // else
    // {
        // waitpid(pid, &status, 0);
        // printf("parent0\n");
        // pid = fork();
        // if (pid != 0)
        // {
            // waitpid(pid, &status, 0);
            // printf("parent1\n");
        // }
        // else
        // {
            // printf("child1\n");
        // }
    // }
// }

void    to_execution(t_data data)
{
    // printf("[%d][%d][%s][%s][%s][%s]\n",
    // data.fd[0], data.fd[1],
    // data.abs_cmd0, data.abs_cmd1,
    // data.content0[0], data.content1[0]);
    if (data.content0)
    {
    }
    printf("[%d][%d][%s][%s][%s][%s]\n",
    data.fd[0], data.fd[1],
    data.abs_cmd0, data.abs_cmd1,
    data.content0[0], data.content1[0]);
}

// int     main()
// {
    // int i;

    // char    *cmd = NULL;
    // char    *args[] = {};
    // return (0);
// }