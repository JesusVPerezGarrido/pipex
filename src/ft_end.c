/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/28 10:07:25 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_error_code code, ...)
{
	va_list	args;

	va_start(args, code);
	if (code == ARG_NUM)
		ft_putstr_fd("Usage: ./pipex infile cmd cmd outfile.\n", STDERR_FILENO);
	if (code == BAD_FILENAME || code == FILE_NO_EXIST)
		ft_putstr_fd("zsh: no such file or directory: ", STDERR_FILENO);
	if (code == CMD_NO_EXIST)
		ft_putstr_fd("zsh: command not found: ", STDERR_FILENO);
	if (code == FILE_NO_PERMS)
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	if (code == BAD_CMD_NAME || code == CMD_NO_PERMS)
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	if (code == BAD_CMD_NAME || code == BAD_FILENAME || code == FILE_NO_EXIST
		|| code == FILE_NO_PERMS || code == CMD_NO_EXIST
		|| code == CMD_NO_PERMS)
		ft_putendl_fd(va_arg(args, void *), STDERR_FILENO);
	va_end(args);
	exit(code);
}
