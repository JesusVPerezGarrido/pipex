/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:20 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 12:11:33 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_child(int infd, int outfd, char *fullcmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		child_fds(infd, outfd);
		execute_cmd(fullcmd, envp);
	}
}
