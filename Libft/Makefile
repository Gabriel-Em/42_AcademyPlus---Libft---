# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 02:05:19 by gpop              #+#    #+#              #
#    Updated: 2017/12/24 19:07:07 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_strlen \
			ft_strdup \
			ft_strcpy \
			ft_strncpy \
			ft_strcat \
			ft_strncat \
			ft_strlcat \
			ft_strchr \
			ft_strrchr \
			ft_strstr \
			ft_strnstr \
			ft_strcmp \
			ft_strncmp \
			ft_atoi \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_memalloc \
			ft_memdel \
			ft_strnew \
			ft_strdel \
			ft_strclr \
			ft_striter \
			ft_striteri \
			ft_strmap \
			ft_strmapi \
			ft_strequ \
			ft_strnequ \
			ft_strsub \
			ft_strjoin \
			ft_strtrim \
			ft_strsplit \
			ft_itoa \
			ft_putchar \
			ft_putstr \
			ft_putendl \
			ft_putnbr \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_lstnew \
			ft_lstdelone \
			ft_lstdel \
			ft_lstadd \
			ft_lstiter \
			ft_lstmap \
			ft_swap \
			ft_strrev \
			ft_quicksort \
			ft_pow \
			ft_min \
			ft_max \
			ft_isspace \
			ft_isupper \
			ft_islower \
			ft_intlen \
			ft_putnbrtab \
			ft_word_count \
			ft_lstappend \
			ft_strshorten \
			ft_strcutuntil \
			get_next_line \
			ft_swapstr \
			ft_lstlen \
			ft_putstr_w \
			ft_putnbr_w \
			ft_abs
OBJ = $(patsubst %,%.o,$(FUNCTIONS))
SRC = $(patsubst %,%.c,$(FUNCTIONS))
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)
	@true

$(NAME):
	gcc -I ./includes $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
