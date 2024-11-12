/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/12 11:29:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_error_code code)
{
	if (code != OK && code != EXEC_ERROR)
	{
		ft_printf("Error code: %i\n", code);
		exit(code);
	}
	exit(0);
}
