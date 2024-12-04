/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/04 12:40:05 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_end(t_error_code code)
{
	if (code == ARG_NUM)
		ft_fprintf(STDERR_FILENO, "Usage: ./pipex infile cmd cmd outfile.\n");
	exit(code);
}
