# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 14:13:48 by mal-mora          #+#    #+#              #
#    Updated: 2024/09/26 14:53:34 by moel-fat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = cc
FLAGS = -Wall -Wextra -Werror -o3
RM = rm -rf
NAME = cub3D
B_NAME = cub3D_bonus

CFILES = cub3d.c\
		 src/parsing.c\
		 src/list_making.c\
		 src/initialization.c\
		 src/events.c\
		 src/utils.c \
		 src/raycasting.c\
		 src/render.c\
		 src/draw_3d.c\
		 src/ray_cast_utils.c\
		 src/draw_3d_utils.c\
		 src/parse_colors.c\
		 src/parse_map.c\
		 src/parse_map1.c\
		 src/parse_map2.c\
		 src/parse_player.c\
		 src/parse_textures.c\
		 src/parsing_utils.c\
		 src/parsing_utils1.c\
		 src/update_player.c\
		 src/utils_func.c\
		 src/utils1.c

BFILES = cub3d_bonus.c\
		 src_bonus/parsing_bonus.c\
		 src_bonus/list_making_bonus.c\
		 src_bonus/initialization_bonus.c\
		 src_bonus/events_bonus.c\
		 src_bonus/utils_bonus.c \
		 src_bonus/raycasting_bonus.c\
		 src_bonus/render_bonus.c\
		 src_bonus/draw_3d_bonus.c\
		 src_bonus/ray_cast_utils_bonus.c\
		 src_bonus/draw_3d_utils_bonus.c\
		 src_bonus/parse_colors_bonus.c\
		 src_bonus/parse_map_bonus.c\
		 src_bonus/parse_map1_bonus.c\
		 src_bonus/parse_map2_bonus.c\
		 src_bonus/parse_player_bonus.c\
		 src_bonus/parse_textures_bonus.c\
		 src_bonus/parsing_utils_bonus.c\
		 src_bonus/parsing_utils1_bonus.c\
		 src_bonus/animation_bonus.c\
		 src_bonus/animation_utils_bonus.c\
		 src_bonus/init_sprint_bonus.c\
		 src_bonus/update_player_bonus.c\
		 src_bonus/utils_func_bonus.c\
		 src_bonus/utils1_bonus.c\


OBJ = $(patsubst %.c, %.o, $(CFILES))
B_OBJ = $(patsubst %.c, %.o, $(BFILES))

all: lib $(NAME)

lib:
	@make -C libft

$(OBJ) : %.o: %.c includes/cub3d.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : libft/libft.a $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) ./.MLX/libmlx42.a -lglfw -L/Users/$(USER)/.brew/opt/glfw/lib -pthread -lm libft/libft.a -o $(NAME)
	@echo making mandatory... Done.

bonus: lib $(B_NAME)

$(B_OBJ) : %.o: %.c includes/cub3D_bonus.h
	@$(CC) $(FLAGS) -c $< -o $@

$(B_NAME) : libft/libft.a $(B_OBJ)
	@$(CC) $(FLAGS) $(B_OBJ) ./.MLX/libmlx42.a -lglfw -L/Users/$(USER)/.brew/opt/glfw/lib -pthread -lm libft/libft.a -o $(B_NAME)
	@echo making bonus ... Done.

clean:
	@$(RM) $(OBJ) $(B_OBJ)
	@make -C libft clean
	@echo cleaning ... Done.

fclean: clean
	$(RM) $(NAME) $(B_NAME)
	make -C libft fclean

re: fclean all
