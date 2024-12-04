/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/04 12:40:32 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int in_fd, int *outpipe, char *full_cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(outpipe[STDIN_FILENO]);
		child_fds(in_fd, outpipe[STDOUT_FILENO]);
		execute_cmd(full_cmd, envp);
	}
}

void	last_child(int *pipefd, int outfile_fd, char *full_cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(pipefd[STDOUT_FILENO]);
		child_fds(pipefd[STDIN_FILENO], outfile_fd);
		execute_cmd(full_cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	in_fd;
	int	cmd_pipe[2];
	int	out_fd;

	validate_args(argc, argv);
	in_fd = open(argv[1], O_RDONLY);
	if (in_fd == -1)
		ft_end(OPEN_ERROR);
	pipe(cmd_pipe);
	first_child(in_fd, cmd_pipe, argv[2], envp);
	while (access(argv[4], F_OK) == 0)
		unlink(argv[4]);
	out_fd = open(argv[4], O_CREAT | O_WRONLY, 00644);
	if (out_fd == -1)
		ft_end(OPEN_ERROR);
	last_child(cmd_pipe, out_fd, argv[3], envp);
	close(in_fd);
	close(out_fd);
	close(cmd_pipe[0]);
	close(cmd_pipe[1]);
	ft_end(OK);
}
