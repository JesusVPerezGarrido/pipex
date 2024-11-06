/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 16:52:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_END_H
# define FT_END_H

# include "libft.h"

typedef enum e_error_code
{
	OK,
	ARG_NUM,
	FILE_NO_EXIST,
	FILE_NO_PERMS,
	BAD_FILENAME,
	CMD_NO_EXIST,
	CMD_NO_PERMS,
	BAD_CMD_NAME,
	PIPE_ERROR,
}	t_error_code;

void	ft_end(t_error_code code);

#endif
