/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:46:35 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/06 16:52:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_H
# define PIPEX_UTILS_H

# include "ft_end.h"
# include "libft.h"

# define CMD_DIR "/bin/:/usr/bin/:/sbin/:/usr/sbin"

void	free_matrix(char **matrix);
char	*get_cmd_name(char *full_cmd);
char	*get_cmd_path(char *full_cmd);

#endif
