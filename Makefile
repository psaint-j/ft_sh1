# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaint-j <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/29 05:49:15 by psaint-j          #+#    #+#              #
#    Updated: 2015/04/07 20:09:55 by psaint-j         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
LIBF = -L./libft -lft
NAME = ft_minishell
SRCS = ./srcs/ft_countab.c\
	   ./srcs/get_cd.c\
	   ./srcs/get_env.c\
	   ./srcs/get_exec.c\
	   ./srcs/get_next_line.c\
	   ./srcs/get_params.c\
	   ./srcs/get_prompt.c\
	   ./srcs/main.c\
	   ./srcs/get_command.c\
	   ./srcs/get_setenv.c\
	   ./srcs/get_builtin.c\
	   ./srcs/get_main.c\
	   ./srcs/get_check_cd.c

OBJ_PATH = ./obj
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
		@make -C libft/
		@mkdir $(OBJ_PATH)
		@gcc -c $(SRCS) -g
		@mv *.o $(OBJ_PATH)
		@gcc $(CFLAGS) $(LIBF) -o $(NAME) $(OBJ_PATH)/*.o
		@echo "\033[33m"Compilation of $(NAME) : "\033[32m"Success"\033[0m"

clean:
		@make clean -C libft/
		@rm -rf $(OBJ_PATH)
		@echo "\033[33m"$(OBJ_PATH) : "\033[32m"Deleted"\033[0m"

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)
		@echo "\033[33m"$(NAME) : "\033[32m"Deleted"\033[0m"

re: fclean all
