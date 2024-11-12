/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 13:38:28 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_end(t_error_code code)
{
	if (code != OK && code != EXEC_ERROR)
	{
		ft_putstr_fd("Error code: ", STDERR_FILENO);
		ft_putnbr_fd(code, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		exit(code);
	}
	exit(0);
}
