NAME		:=	pipex
B_NAME		:=	pipex_bonus

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

LIBFT_DIR	:=	./lib/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)/inc

LIBS		:=	$(LIBFT)

SRCS		:=	$(addprefix src/, \
				pipex.c \
				validation.c \
				ft_end.c \
				pipex_utils.c \
				execute_cmd.c \
				child_fds.c )

B_SRCS		:=	$(addprefix bonus/, \
				child_fds_bonus.c \
				create_child_bonus.c \
				create_fd_bonus.c \
				execute_cmd_bonus.c \
				ft_end_bonus.c \
				pipex_bonus.c \
				pipex_utils_bonus.c \
				validation_bonus.c )

OBJS		:=	$(patsubst src%, obj%, $(SRCS:.c=.o))
B_OBJS		:=	$(patsubst bonus%, obj%, $(B_SRCS:.c=.o))

all: libft obj $(NAME)

bonus: libft obj $(B_NAME)

$(B_NAME): $(B_OBJS)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $@ && printf "Compiling: $@ with bonus\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@ && printf "Compiling: $@\n"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj/%.o: bonus/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj:
	@mkdir -p $@ && printf "Creating $@ directory\n"

libft: $(LIBFT)

$(LIBFT):
	@make --silent -C $(LIBFT_DIR)

clean:
	@rm -rf obj && printf "Removing $(NAME) object files\n"
	@make --silent -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -f $(NAME) $(B_NAME) && printf "Removing $(NAME)\n"

re: fclean all

.PHONY: all, clean, fclean, re, libft, bonus, bonus_exec
