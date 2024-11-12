/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:43:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 14:13:49 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	valid_cmd(char *full_cmd)
{
	char	*cmd_path;

	if (!full_cmd || !full_cmd[0])
	{
		ft_putendl_fd("szh: permission denied: ", STDERR_FILENO);
		exit(BAD_CMD_NAME);
	}
	cmd_path = get_cmd_path(full_cmd);
	if (!cmd_path)
		ft_end(MALLOC_ERROR);
	if (access(cmd_path, F_OK) == -1)
	{
		ft_putstr_fd("zsh: command not found: ", STDERR_FILENO);
		ft_putendl_fd(full_cmd, STDERR_FILENO);
		free(cmd_path);
		exit(CMD_NO_EXIST);
	}
	if (access(cmd_path, X_OK) == -1)
	{
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
		ft_putendl_fd(full_cmd, STDERR_FILENO);
		free(cmd_path);
		exit(CMD_NO_PERMS);
	}
	free(cmd_path);
}

static void	valid_file(char *file_name, t_bool out)
{
	if (!file_name || !file_name[0])
	{
		ft_putendl_fd("zsh: no suck file or directory: ", STDERR_FILENO);
		exit(BAD_FILENAME);
	}
	if (out)
		return ;
	if (access(file_name, F_OK) == -1)
	{
		ft_putstr_fd("zsh: no suck file or directory: ", STDERR_FILENO);
		ft_putendl_fd(file_name, STDERR_FILENO);
		exit(FILE_NO_EXIST);
	}
	if (access(file_name, R_OK) == -1)
	{
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
		ft_putendl_fd(file_name, STDERR_FILENO);
		exit(FILE_NO_PERMS);
	}
}

void	validate_args(int argc, char **argv)
{
	int	index;

	if (argc < 5)
		ft_end(ARG_NUM);
	index = 1;
	while (index < argc)
	{
		if (index != 1 && index != argc - 1)
			valid_cmd(argv[index]);
		else if (index == 1)
			valid_file(argv[index], 0);
		else
			valid_file(argv[index], 1);
		index++;
	}
}
