/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:08 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 16:44:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_end.h"

void	ft_end(t_error_code code)
{
	if (code != OK)
	{
		ft_printf("Error code: %i\n", code);
		exit(1);
	}
	exit(code);
}
