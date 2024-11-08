/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:43:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/08 13:08:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static void	valid_cmd(char *full_cmd)
{
	if (!full_cmd || !full_cmd[0])
		ft_end(BAD_CMD_NAME);
}

static void	valid_file(char *file_name, t_bool out)
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
