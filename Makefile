NAME=		pipex

CC=			cc
CFLAGS=		-Wall -Wextra -Werror -g3
CSANITIZE=	-fsanitize=address
#################################
RED		=	\033[91m
GREEN	=	\033[92m
YELLOW	=	\033[93m
BLUE	=	\033[94m
PINK	=	\033[95m
CLEAR	=	\033[0m
################################
PIPEX_DIR=	./srcs/
SRCS_FILES=	main.c
SRCS=		$(addprefix $(PIPEX_DIR), $(SRCS_FILES))
################################

#add libft

###############################
OBJS_DIR=	./objs/
OBJS=		$(SRCS:$(PIPEX_DIR)%.c=$(OBJS_DIR)%.o)
##############################

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(BLUE)Compiling pipex$(CLEAR)\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)pipex -> OK\n$(CLEAR)\n"
	@echo "$(YELLOW)\tUsage: ./pipex file1 cmd1 cmd2 file2$(CLEAR)\n"

$(OBJS_DIR)%.o: $(PIPEX_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

sanitize: fclean $(NAME)
	$(CC) $(CFLAGS) $(CSANITIZE) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norminette:
	norminette $(OBJS)
