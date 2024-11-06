/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_error_code.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:41:41 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 13:06:49 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ERROR_CODE_H
# define T_ERROR_CODE_H

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
}	t_error_code;

#endif
