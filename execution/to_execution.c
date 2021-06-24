/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:49:42 by abelarif          #+#    #+#             */
/*   Updated: 2021/06/24 10:53:52 by abelarif         ###   ########.fr       */
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

void    exec_first_cmd(t_data data)
{
    
}

void    exec_second_cmd(t_data data)
{
    
}

void    to_execution(t_data data)
{
    // printf("[%d][%d][%s][%s][%s][%s]\n",
    // data.fd[0], data.fd[1],
    // data.abs_cmd0, data.abs_cmd1,
    // data.content0[0], data.content1[0]);

    printf("[%d][%d][%s][%s][%s][%s]\n",
    data.fd[0], data.fd[1],
    data.abs_cmd0, data.abs_cmd1,
    data.content0[0], data.content1[0]);
    
    exec_first_cmd(data);
    exec_second_cmd(data);
}

// int     main()
// {
    // int i;

    // char    *cmd = NULL;
    // char    *args[] = {};
    // return (0);
// }

/*
  *         USEFUL FUNCTION 
   *                            void	to_execution(t_data data)
   *                            {
   *                            	// int		pipe[2];
   *                            	int ret;
   *                            	int	status;
   *                            
   *                            	if (data.fd[0] < 0)
   *                            	ret = fork();
   *                            	if (ret < 0)
   *                            		ft_error("FORK", 1);
   *                            	if (ret == 0)
   *                            	{
   *                            		printf("ERRRRRRRRRRROR\n");
   *                            		int x = open("gggggggggg", O_RDONLY);
   *                            			exit(1);
   *                            
   *                            	}
   *                            	else
   *                            	{
   *                            		int f;
   *                            		waitpid(ret, &status, 0);
   *                            		if (WIFEXITED(status))
   *                            		{
   *                            			printf("******\n");
   *                            			f = WEXITSTATUS(status);
   *                            		}
   *                            		printf("[%d][%d]", f, status);
   *                            	}
   *                            }
  *
*/

/*
void    exec_pipe(t_command *command, char *infile,
                        char *outfile, char **envp)
{
        t_exec_data     edata;

        if (pipe(edata.fds) == -1)
                fatal("pipe function failed!");
        first_command(command, infile, envp, &edata);
        second_command(command, outfile, envp, &edata);
        close(edata.fds[0]);
        close(edata.fds[1]);
        waitpid(edata.pid1, &edata.child_state1, 0);
        waitpid(edata.pid2, &edata.child_state2, 0);
        if (WIFEXITED(edata.child_state2))
        {
                ft_free_command(&command);
                reset_files(edata.fd0, edata.fd1);
                exit(WEXITSTATUS(edata.child_state2));
        }
}

void    first_command(t_command *command, char *infile,
                        char **envp, t_exec_data *edata)
{
        edata->pid1 = fork();
        if (edata->pid1 == -1)
                fatal("fork function failed!");
        else if (edata->pid1 == 0)
        {
                dup_file(open_file(infile, STDIN), STDIN, &(edata->fd0));
                dup_pipe(0, edata->fds);
                command->name = replace_commands(command->name, envp);
                if (execve(command->name, command->args, envp) == -1)
                        fatal_execve();
        }
}

void    second_command(t_command *command, char *outfile,
                        char **envp, t_exec_data *edata)
{
        edata->pid2 = fork();
        if (edata->pid2 == -1)
                fatal("fork function failed!");
        else if (edata->pid2 == 0)
        {
                dup_pipe(1, edata->fds);
                dup_file(open_file(outfile, STDOUT), STDOUT, &(edata->fd1));
                command->next->name = replace_commands(command->next->name, envp);
                if (execve(command->next->name, command->next->args, envp) == -1)
                        fatal_execve();*/