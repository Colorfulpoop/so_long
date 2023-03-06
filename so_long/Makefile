SRCS = main.c ft_check_map.c ft_read_map.c ft_add_graphics.c ft_controls.c ft_update.c ft_utils_map.c \
		ft_utils_control.c
OBJ = ${SRCS:.c=.o}
NAME = so_long
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
GETNEXTLINE := ./lib/get_next_line/*c
FT_PRINTF := ./lib/ft_printf/libftprintf.a
MINILIBX := ./minilibx
FLAG = -Wall -Werror -Wextra -g
CC = gcc
all :
	make -C $(MINILIBX)
	make -C ./lib/ft_printf
	@$(CC) $(FLAG) $(SRCS) $(LIBRARY) $(GETNEXTLINE) $(FT_PRINTF) -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
			make clean -C $(MINILIBX)
			make clean -C ./lib/ft_printf
			rm -f $(NAME) $(OBJ)
re: fclean all clean
