/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/18 11:49:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_end(t_error_code code, ...)
{
	va_list	args;

	va_start(args, code);
	if (code == ARG_NUM)
		ft_putstr_fd("Usage: ./pipex infile cmd cmd outfile.\n", STDERR_FILENO);
	if (code == BAD_CMD_NAME)
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	if (code == BAD_FILENAME)
		ft_putstr_fd("zsh: no such file or directory: ", STDERR_FILENO);
	if (code == FILE_NO_EXIST)
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	if (code == FILE_NO_PERMS)
		ft_putstr_fd("zsh: permission denied: ", STDERR_FILENO);
	if (code == BAD_CMD_NAME || code == BAD_FILENAME || code == FILE_NO_EXIST
		|| code == FILE_NO_PERMS)
		ft_putendl_fd(va_arg(args, void *), STDERR_FILENO);
	va_end(args);
	exit(code);
}
