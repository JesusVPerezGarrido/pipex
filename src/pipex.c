/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/08 13:07:15 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_infile(int *pipefd, char *infile)
{
	int		infile_fd;
	char	*line;

	infile_fd = open(infile, O_RDONLY);
	line = get_next_line(infile_fd);
	while (line)
	{
		write(pipefd[STDIN_FILENO], line, ft_strlen(line));
		free(line);
		line = get_next_line(infile_fd);
	}
	close(infile_fd);
}

void	first_child(int in_fd, int *outpipe, char *full_cmd, char **envp)
{
	pid_t	pid;
	char	**cmd_args;
	char	*cmd_name;

	pid = fork();
	if (pid == 0)
	{
		close(outpipe[STDIN_FILENO]);
		dup2(in_fd, STDIN_FILENO);
		dup2(outpipe[STDOUT_FILENO], STDOUT_FILENO);
		cmd_name = get_cmd_path(full_cmd);
		cmd_args = ft_split(full_cmd, ' ');
		if (cmd_name)
		{
			free(cmd_args[0]);
			cmd_args[0] = cmd_name;
		}
		if (execve(cmd_args[0], cmd_args, envp) == -1)
		{
			free_matrix(cmd_args);
			ft_end(EXEC_ERROR);
		}
	}
}

void	last_child(int *pipefd, int outfile_fd, char *full_cmd, char **envp)
{
	pid_t	pid;
	char	**cmd_args;
	char	*cmd_name;

	pid = fork();
	if (pid == 0)
	{
		close(pipefd[STDOUT_FILENO]);
		dup2(outfile_fd, STDOUT_FILENO);
		dup2(pipefd[STDIN_FILENO], STDIN_FILENO);
		cmd_name = get_cmd_path(full_cmd);
		cmd_args = ft_split(full_cmd, ' ');
		if (cmd_name)
		{
			free(cmd_args[0]);
			cmd_args[0] = cmd_name;
		}
		if (execve(cmd_args[0], cmd_args, envp) == -1)
		{
			free_matrix(cmd_args);
			ft_end(EXEC_ERROR);
		}
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
}
