/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:55:42 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/11 11:04:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_fds(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}
