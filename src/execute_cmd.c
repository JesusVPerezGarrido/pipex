/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:42:07 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/11 10:57:58 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *full_cmd, char **envp)
{
	char	**cmd_args;
	char	*cmd_name;

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
