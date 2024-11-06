/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:51:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 12:12:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**prepare_cmd_args(char *str)
{
	char	**cmd_args;
	char	*placeholder;
	char 	**cmd_directories;
	int		index;
	
	cmd_directories = ft_split(CMD_DIR, ':');
	index = -1;
	cmd_args = ft_split(str, ' ');
	while (cmd_directories[++index])
	{
		placeholder = ft_strjoin(cmd_directories[index], cmd_args[0]);
		if (access(placeholder, F_OK) != -1)
		{
			free(cmd_args[0]);
			cmd_args[0] = placeholder;
			break ;
		}
		free(placeholder);
	}
	index = -1;
	while (cmd_directories[++index])
		free(cmd_directories[index]);
	free(cmd_directories);
	return (cmd_args);
}

void	validate_command(char *full_cmd)
{
	
}

void	validate_file(char *file_name)
{
	
}

void	validate_args(int argc, char **argv)
{
	int	index;
	
	if (argc != 5)
		exit(1);
	index = 1;
	while (index < argc)
	{
		if (index != 1 || index != argc - 1)
			validate_command(argv[index]);
		else
			validate_file(argv[index]);
	}
}

int	main(int argc, char **argv)
{
	validate_args(argc, argv);
}
