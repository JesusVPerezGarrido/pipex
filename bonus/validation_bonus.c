/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:43:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/04 12:38:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	valid_cmd(char *full_cmd)
{
	char	*cmd_path;

	if (!full_cmd || !full_cmd[0])
		ft_fprintf(STDERR_FILENO, "zsh: command not found: %s\n", full_cmd);
	else
	{
		cmd_path = get_cmd_path(full_cmd);
		if (!cmd_path)
			ft_fprintf(STDERR_FILENO, "zsh: permission denied: %s\n", full_cmd);
		else if (access(cmd_path, X_OK) == -1)
			ft_fprintf(STDERR_FILENO, "zsh: command not found: %s\n", full_cmd);
		free(cmd_path);
	}
}

static void	valid_file(char *file_name, t_bool out)
{
	if (!file_name || !file_name[0])
		ft_end(BAD_FILENAME, file_name);
	if (out)
		return ;
	if (access(file_name, F_OK) == -1)
		ft_fprintf(STDERR_FILENO, "zsh: no such file or directory: %s\n",
			file_name);
	if (access(file_name, R_OK) == -1)
		ft_fprintf(STDERR_FILENO, "zsh: permission denied: %s\n", file_name);
}

void	validate_args(int argc, char **argv)
{
	int	index;

	if (argc < 5)
		ft_end(ARG_NUM, 0);
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
