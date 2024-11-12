/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:42:07 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 13:09:19 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_cmd(char *full_cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_path = get_cmd_path(full_cmd);
	cmd_args = ft_split(full_cmd, ' ');
	if (cmd_path)
	{
		free(cmd_args[0]);
		cmd_args[0] = cmd_path;
	}
	if (execve(cmd_args[0], cmd_args, envp) == -1)
	{
		free_matrix(cmd_args);
		ft_end(EXEC_ERROR);
	}
}
