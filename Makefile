# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 00:58:37 by keaton            #+#    #+#              #
#    Updated: 2022/06/16 00:58:41 by keaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	utils.c		draw_utils.c	key_utils.c\
		ft_split.c	lib_part.c		mapparcer.c\
		main.c		visual.c		initiators.c\
		get_next_line.c		get_next_line_utils.c

OBJ = $(SRC:.c=.o)
CC_FLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm
NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
