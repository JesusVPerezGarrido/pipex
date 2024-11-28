/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:50:57 by jeperez-          #+#    #+#             */
/*   Updated: 2024/11/28 10:04:08 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

typedef struct s_pipe
{
	int	pipe[2];
}		t_pipe;

typedef struct s_fdbundle
{
	int		input;
	t_pipe	*pipe;
	int		output;
}			t_fdbundle;

void	ft_end(t_error_code code, ...);
void	free_matrix(char **matrix);
char	*get_cmd_name(char *full_cmd);
char	*get_cmd_path(char *full_cmd);
void	validate_args(int argc, char **argv);
void	create_fd(t_fdbundle *fd, int argc, char **argv);
void	create_child(int infd, int outfd, char *fullcmd, char **envp);
void	child_fds(int in, int out);
void	execute_cmd(char *full_cmd, char **envp);
void	clean_fd(t_fdbundle fd, int npipe);

#endif
