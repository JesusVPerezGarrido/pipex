/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:43:39 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/18 11:37:35 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_matrix(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index])
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

char	*get_cmd_name(char *full_cmd)
{
	char	**cmd_matrix;
	char	*cmd_name;

	cmd_matrix = ft_split(full_cmd, ' ');
	if (!cmd_matrix)
		return (0);
	cmd_name = ft_strdup(cmd_matrix[0]);
	free_matrix(cmd_matrix);
	return (cmd_name);
}

static char	*test_path(char **path_matrix, char *cmd_name)
{
	int		index;
	char	*cmd_path;

	index = 0;
	if (access(cmd_name, F_OK) == 0)
	{
		return (ft_strdup(cmd_name));
	}
	while (path_matrix[index])
	{
		cmd_path = ft_freejoin(ft_strjoin(path_matrix[index], "/"), cmd_name);
		if (access(cmd_path, F_OK) == 0)
		{
			return (cmd_path);
		}
		free(cmd_path);
		index++;
	}
	return (0);
}

char	*get_cmd_path(char *full_cmd)
{
	char	*cmd_path;
	char	*cmd_name;
	char	**path_matrix;

	cmd_name = get_cmd_name(full_cmd);
	if (!cmd_name)
		return (0);
	path_matrix = ft_split(CMD_DIR, ':');
	if (!path_matrix)
	{
		free(cmd_name);
		return (0);
	}
	cmd_path = test_path(path_matrix, cmd_name);
	free(cmd_name);
	free_matrix(path_matrix);
	return (cmd_path);
}
