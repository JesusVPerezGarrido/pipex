/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 14:13:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_child(int in_fd, t_pipe pipe, char *full_cmd, char **envp)
{
	create_child(in_fd, pipe.pipe[STDOUT_FILENO], full_cmd, envp);
	close(in_fd);
	close(pipe.pipe[STDOUT_FILENO]);
}

static void	middle_child(t_pipe pipe_in, t_pipe pipe_out, char *full_cmd, \
	char **envp)
{
	create_child(pipe_in.pipe[STDIN_FILENO], pipe_out.pipe[STDOUT_FILENO], \
		full_cmd, envp);
	close(pipe_in.pipe[STDIN_FILENO]);
	close(pipe_out.pipe[STDOUT_FILENO]);
}

static void	last_child(t_pipe pipe, int out_fd, char *full_cmd, char **envp)
{
	create_child(pipe.pipe[STDIN_FILENO], out_fd, full_cmd, envp);
	close(pipe.pipe[STDIN_FILENO]);
	close(out_fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_fdbundle	fd;
	int			index;

	validate_args(argc, argv);
	create_fd(&fd, argc, argv);
	index = 0;
	while (index < argc - 3)
	{
		if (index == 0)
			first_child(fd.input, fd.pipe[index], argv[index + 2], envp);
		else if (index == argc - 4)
			last_child(fd.pipe[index - 1], fd.output, argv[index + 2], envp);
		else
			middle_child(fd.pipe[index - 1], fd.pipe[index], argv[index + 2], \
				envp);
		index++;
	}
	free(fd.pipe);
	ft_end(OK);
}
