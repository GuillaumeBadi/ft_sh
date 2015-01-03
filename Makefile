# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbadi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/25 03:19:18 by gbadi             #+#    #+#              #
#    Updated: 2015/01/03 19:12:59 by gbadi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				ft_minishell1

LIB =				libft

SRC =				\
					ft_prompt.c\
					ft_get_path.c\
					ft_exit.c\
					ft_pwd.c\
					ft_subc.c\
					ft_get_env.c\
					ft_get_home.c\
					ft_get_bin.c\
					ft_fuckit.c\
					ft_isonlyspace.c\
					ft_split_custom.c\
					ft_last_history.c\
					ft_aliases.c\
					ft_exec.c\
					ft_unsetenv.c\
					ft_add_alias.c\
					ft_minishellrc.c\
					ft_setenv.c\
					ft_repl.c\
					ft_clear.c\
					ft_env.c\
					ft_cd.c\
					ft_get_command.c\
					main.c\


FLAGS = 			-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
#	make -C $(LIB)
#	make -C $(LIB) clean
	gcc -o $(NAME) $(FLAGS) $(SRC) libft/libft.a -I./libft/

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
