# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 02:05:19 by gpop              #+#    #+#              #
#    Updated: 2017/11/25 19:43:22 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE_DIR = srcs/
HEADER_DIR = includes/
FUNCTIONS = ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_strlen \
			ft_strdup \
			ft_strcpy \
			ft_strncpy \
			ft_strcat \
			ft_strncat
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc -I $(HEADER_DIR) $(FLAGS) -c $(patsubst %,$(SOURCE_DIR)%.c,$(FUNCTIONS))
	ar rcs $(NAME) $(patsubst %,%.o,$(FUNCTIONS))

clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS))

fclean: clean
	@rm -f $(NAME)

re: fclean all
