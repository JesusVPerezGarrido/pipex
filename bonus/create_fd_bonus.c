/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:47:19 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 13:50:51 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_fd(t_fdbundle *fd, int argc, char **argv)
{
	int	index;

	fd->input = open(argv[1], O_RDONLY);
	if (fd->input == -1)
		ft_end(OPEN_ERROR);
	while(access(argv[argc -1], F_OK) == 0)
		unlink(argv[argc - 1]);
	fd->output = open(argv[argc - 1], O_CREAT | O_WRONLY, 00644);
	if (fd->output == -1)
		ft_end(OPEN_ERROR);
	fd->pipe = ft_calloc(argc - 4, sizeof(t_pipe));
	index = 0;
	while (index < argc - 4)
	{
		if (pipe(fd->pipe[index].pipe) == -1)
		{
			ft_end(PIPE_ERROR);
		}
		index++;
	}
}
