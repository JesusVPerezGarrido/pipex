NAME		:=	pipex

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

LIBFT_DIR	:=	./lib/libft

INCS		:=	-I ./inc \
				-I $(LIBFT_DIR)

LIBS		:=	$(LIBFT_DIR)/libft.a

SRCS		:=	src/pipex.c

OBJS		:=	$(patsubst src%, obj%, $(SRCS:.c=.o))

all: libft obj $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) && printf "Compiling: $(NAME)\n"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

obj:
	@mkdir -p obj && printf "Creating obj directory\n"

libft:
	@make --silent -C $(LIBFT_DIR)

clean:
	@rm -rf obj && printf "Removing $(NAME) object files\n"
	@make --silent -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -f pipex && printf "Removing $(NAME)\n"

re: fclean all

.PHONY: all, clean, fclean, re, libft
