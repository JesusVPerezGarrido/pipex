/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:50:57 by jeperez-          #+#    #+#             */
/*   Updated: 2024/12/04 12:43:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

# define CMD_DIR "/home/jeperez-/bin:/home/jeperez-/bin:/home/jeperez-/.cargo/ \
bin:/usr/local/cargo/bin:/home/jeperez-/.opam/default/bin:/usr/local/sbin:/usr \
/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin \
:/usr/local/go/bin"

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
	OPEN_ERROR,
	MALLOC_ERROR,
	EXEC_ERROR,
}	t_error_code;

void	ft_end(t_error_code code);
void	free_matrix(char **matrix);
char	*get_cmd_name(char *full_cmd);
char	*get_cmd_path(char *full_cmd);
void	validate_args(int argc, char **argv);
void	execute_cmd(char *full_cmd, char **envp);
void	child_fds(int in, int out);

#endif
