# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/04/28 11:37:16 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c						\
		map_checks.c				\
		map_checks_utils.c			\
		map_parse_utils.c			\
		map_init_data.c				\
		map_read_utils.c			\
		picture_parsing.c			\
		game_exit.c					\
		input_handling.c			\
		color_manipulations.c		\
		ft_split_spaces.c			\
		raycasting.c 				\
		raycasting_floor_ceiling.c	\
		raycasting_walls.c 			\
		init_game.c 				\
		input_handling_rot.c 		\

SRCS_BONUS = main.c					\
		map_checks.c				\
		map_checks_utils.c			\
		map_parse_utils.c			\
		map_init_data.c				\
		map_read_utils.c			\
		picture_parsing.c			\
		game_exit.c					\
		input_handling.c			\
		color_manipulations.c		\
		ft_split_spaces.c			\
		raycasting.c 				\
		raycasting_floor_ceiling.c	\
		raycasting_walls.c 			\
		init_game.c 				\
		input_handling_mouse.c 		\
		minimap.c					\
		input_handling_rot.c 		\

NAME = cub3d
BONUS = bonus

LIBFT = include/libft/
MLX = mlx/

SRCS_DIR = srcs/
SRCS_BONUS_DIR = srcs_bonus/

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c include/cub3d.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -O3 -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c include/cub3d_bonus.h
	@mkdir -p $(OBJS_BONUS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) include/libft/libft.a $(MLX)libmlx.a

$(BONUS): $(OBJECTS_BONUS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS) $(OBJECTS_BONUS_PREFIXED) include/libft/libft.a $(MLX)libmlx.a

all: $(NAME) $(BONUS)

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_BONUS_DIR)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all
