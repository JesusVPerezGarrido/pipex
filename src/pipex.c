/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 13:20:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_end(t_error_code code)
{
	if (code != OK)
	{
		ft_printf("Error code: %i\n", code);
		exit(1);
	}
	exit(0);
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

char	*get_cmd_path(char *full_cmd)
{
	char	*cmd_path;
	char	*cmd_name;
	char	**path_matrix;
	int		index;

	cmd_name = get_cmd_name(full_cmd);
	if (!cmd_name)
		return (0);
	path_matrix = ft_split(CMD_DIR, ':');
	if (!path_matrix)
	{
		free(cmd_name);
		return (0);
	}
	index = 0;
	while (path_matrix[index])
	{
		cmd_path = ft_strjoin(path_matrix[index], cmd_name);
		if (access(cmd_path, F_OK) == 0)
		{
			free_matrix(path_matrix);
			return (cmd_path);
		}
		free(cmd_path);
		index++;
	}
	free_matrix(path_matrix);
	return (0);
}

void	valid_cmd(char *full_cmd)
{
	char	*cmd_path;

	if (!full_cmd || !full_cmd[0])
		ft_end(BAD_CMD_NAME);
	cmd_path = get_cmd_path(full_cmd);
	if (!cmd_path)
		ft_end(CMD_NO_EXIST);
	if (access(cmd_path, X_OK) == -1)
	{
		free(cmd_path);
		ft_end(CMD_NO_PERMS);
	}
	free(cmd_path);
}

void	valid_file(char *file_name, t_bool out)
{
	if (!file_name || !file_name[0])
		ft_end(BAD_FILENAME);
	if (out)
		return ;
	if (access(file_name, F_OK) == -1)
		ft_end(FILE_NO_EXIST);
	if (access(file_name, R_OK) == -1)
		ft_end(FILE_NO_PERMS);
}

void	validate_args(int argc, char **argv)
{
	int	index;
	
	if (argc != 5)
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

int	main(int argc, char **argv)
{
	validate_args(argc, argv);
	ft_end(OK);
}
