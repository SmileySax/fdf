SRC = 	ft_bzero.c	get_next_line.c	get_next_line_utils.c \
		ft_split.c	lib_part.c		mapparcer.c	visual.c
#
OBJ = $(SRC:.c=.o)
#
SRC_BONUS = main.c get_next_line.c get_next_line_utils.c read_file.c \
				  	split.c minilib.c utils.c hook.c draw.c menu.c init.c
#
OBJ_BONUS = $(SRC_BONUS:.c=.o)
#
CC_FLAGS = -Wall -Werror -Wextra
#
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
MATH_FLAGS = -lm
#
NAME = fdf
#
all: $(NAME)
#
$(NAME): $(OBJ)
	@$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ) -o $@
	@echo "\033[32m\033[40m\033[1m[fdf compiled]"
#
%.o: %.c
	@$(CC) $(CC_FLAGS) -c $<
#
bonus: $(OBJ_BONUS)
	$(CC) $(CC_FLAGS) $(MATH_FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME)
#
clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "\033[31m\033[40m\033[1m[all clean]"
#
fclean: clean
	@rm -rf $(NAME)
#
re: fclean all
