# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: avuorio <avuorio@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 11:33:02 by avuorio       #+#    #+#                  #
#    Updated: 2021/10/12 13:59:25 by avuorio       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRC_FILES	= main.c \
				error.c \
				init.c \
				time.c \
				utils.c \
				print_tools.c

SRCS		= $(addprefix srcs/, $(SRC_FILES))
DIR			= srcs/

OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJS		= $(addprefix objs/, $(OBJ_FILES))
OBJS_DIR	= objs/

HEADER		= -I ./includes

CFLAGS		= -Wall -Werror -Wextra -pedantic
RM			= rm -f

all:		$(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@echo "\\n\033[35;1m  program ./philo created\033[0m \\n"

$(OBJS_DIR)%.o: $(DIR)%.c
	@echo "\\033[2;1m\n  compiling $<...\033[0m"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER)

clean:
	@$(RM) $(OBJS)
	@echo "\\n\033[35;1m  object files cleaned ! :)\033[0m \\n"

fclean: clean
	@$(RM) $(NAME)
	@rmdir objs
	@echo "\\033[35;1m  executable cleaned ! :)\033[0m \\n"

re: fclean all

.PHONY: 		all fclean clean re