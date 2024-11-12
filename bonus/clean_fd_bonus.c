/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:39:18 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 13:40:50 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clean_fd(t_fdbundle fd, int npipe)
{
	int	index;

	close(fd.input);
	close(fd.output);
	index = 0;
	while (index < npipe)
	{
		close(fd.pipe[index].pipe[0]);
		close(fd.pipe[index].pipe[1]);
		index++;
	}
}
