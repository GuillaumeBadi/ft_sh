# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbadi <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 16:04:37 by gbadi             #+#    #+#              #
#*   Updated: 2014/11/12 20:31:50 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_intlen.c\
		ft_isalnum.c\
		ft_strtoupper.c\
		ft_putline.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_getc.c\
		ft_isprint.c\
		ft_memalloc.c\
		ft_assert.c\
		ft_isspace.c\
		ft_memccpy.c\
		ft_strndup.c\
		get_next_line.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c \
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlen.c\
		ft_putnbr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_iformat.c\
		ft_strrchr.c\
		ft_itoa.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_strrchr.c\
		ft_strsplit.c\
#		ft_lstnew.c\
#		ft_lstdelone.c\
#		ft_lstdel.c

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $@ $(SRCO)

%.o: %.c
	gcc -c $(FLAGS) -o $@ $^

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
