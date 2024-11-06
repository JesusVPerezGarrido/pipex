/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 16:44:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(int *pipefd, char *infile, char *full_cmd, char **envp)
{
	pid_t	pid;
	int		fd;
	char	**cmd_args;

	if (pipe(pipefd) == -1)
		ft_end(PIPE_ERROR);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		fd = open(infile, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		cmd_args = ft_split(full_cmd, ' ');
		free(cmd_args[0]);
		cmd_args[0] = get_cmd_path(full_cmd);
		execve(cmd_args[0], cmd_args, envp);
	}
}

void	last_child(int *pipefd, char *outfile, char *full_cmd, char **envp)
{
	pid_t	pid;
	int		fd;
	char	**cmd_args;

	pid = fork();
	if (pid == 0)
	{
		close(pipefd[1]);
		fd = open(outfile, O_CREAT | O_WRONLY, 0644);
		dup2(fd, STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		cmd_args = ft_split(full_cmd, ' ');
		free(cmd_args[0]);
		cmd_args[0] = get_cmd_path(full_cmd);
		execve(cmd_args[0], cmd_args, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];

	validate_args(argc, argv);
	first_child(pipefd, argv[1], argv[2], envp);
	last_child(pipefd, argv[4], argv[3], envp);
	ft_end(OK);
}
