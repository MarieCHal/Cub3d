NAME =	cub3d
CC =	gcc
SRC =	main.c\
		get_map/get_next_line.c\
		libft/ft_split.c\
		libft/ft_substr.c\
		libft/ft_strlen.c\
		libft/ft_atoi.c\
		parsing/check_settings.c\
		parsing/init_color.c\
		parsing/ft_parse_space.c\
		parsing/check_texture.c\
		parsing/parse_map.c\
		#init/init.c\
		init/init_pos.c\
		init/init_len.c\
		init/init_map.c\
		init/init_rays.c\
		get_map/get_next_line.c\
		display/display.c\
		display/print_map.c\
		move/forward.c\
		move/backward.c\
		move/key_hook.c\
		move/rotation.c\
		move/player_location.c\
		ray/ray_len.c\
		ray/map_check_vert.c\
		ray/map_check_hor.c\
		ray/x_ray_length.c\
		ray/y_ray_length.c\
		ray/vert_dist.c\
		ray/hor_dist.c\
		ray/sidedist_y.c\
		ray/xaxis_y.c\
		ray/x_ray_length.c\
		ray/check_wall.c#
		
FLAGS =	-Wall -Werror -Wextra -g3 -fsanitize=address -fno-omit-frame-pointer
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJ)
	make -C libft
	$(CC) $(FALGS) $(SRC)  -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(NAME)

$(NAME) :	$(OBJ)
	make -C libft
	$(CC) $(FALGS) $(SRC) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)
fclean: clean
	make fclean	-C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
