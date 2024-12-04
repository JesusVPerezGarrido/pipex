/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/04 12:28:21 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_end(t_error_code code, char *message)
{
	if (code == ARG_NUM)
		ft_fprintf(STDERR_FILENO, "Usage: ./pipex infile cmd cmd outfile.\n");
	if (code == BAD_FILENAME || code == FILE_NO_EXIST)
		ft_fprintf(STDERR_FILENO, "zsh: no such file or directory: %s\n",
			message);
	if (code == FILE_NO_PERMS)
		ft_fprintf(STDERR_FILENO, "zsh: permission denied: %s\n", message);
	exit(code);
}
