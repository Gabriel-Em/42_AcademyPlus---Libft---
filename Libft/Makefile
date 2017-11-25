# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 02:05:19 by gpop              #+#    #+#              #
#    Updated: 2017/11/25 15:51:29 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE_DIR = srcs/
HEADER_DIR = includes/
FUNCTIONS = ft_strlen
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
