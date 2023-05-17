/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/04/28 11:36:28 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../mlx/mlx.h"

# define PLAYER_NORTH		'N'
# define PLAYER_SOUTH		'S'
# define PLAYER_WEST		'W'
# define PLAYER_EAST		'E'
# define WALL				'1'
# define FLOOR				'0'
# define FREE_SPACE			' '

# define ARGS_ERROR "Wrong amount of arguments!\n"
# define FILE_ERROR "Given file path is invalid!\n"
# define MAP_ARGS_ERROR "There is some problem with arguments in file!"
# define MAP_ARGS_COLOR_ERROR "Color variable has incorect value!"
# define MAP_WALL_ERROR "Map is not surrounded by walls!\n"
# define MAP_EMPTY_LINES_ERROR "Map has some empty lines inside!\n"
# define MAP_EMPTY_ERROR "There is seems to be no map in file!\n"
# define MAP_PATH_ERROR "Map has no valid path!\n"
# define MAP_COMPONENTS_ERROR "Map doesn't have the player starting \
position, has multiple starting positions or has some invalid characters!\n"
# define SPRITE_ERROR "Couldn't find a sprite. Does it exist?\n"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_fl_ce
{
	float		raydirx0;
	float		raydirx1;
	float		raydiry0;
	float		raydiry1;
	int			p;
	float		posz;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	uint32_t	colorr;
}	t_fl_ce;

typedef struct s_raycast
{
	void		*mlx;
	void		*win;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	double		frametime;
	double		time;
	double		oldtime;
	void		*img;
	char		*img_addr;
	int			line_length;
	int			endian;
	int			bits_per_pixel;
	int			texnum;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	uint32_t	colr;
	int			pitch;
}	t_raycast;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_raycast	*rays;
	t_fl_ce		*fc;
	char		**map;
	int			**imap;
	int			screen_width;
	int			screen_height;
	int			tex_width;
	int			tex_height;
	uint32_t	**texture;
	t_image		wall_north;
	t_image		wall_south;
	t_image		wall_west;
	t_image		wall_east;
	int			floor_color;
	int			ceiling_color;
	int			size_line;
	int			mousex;
	int			mousey;
	char		player_direction;
}	t_game;

size_t			ft_strstr_len(char **str);
void			throw_error(t_game *game, char *message);
char			**ft_strstrdup(char **str, int size);
void			ft_strstr_free(char **str);
void			free_game(t_game *game);

char			**ft_split_spaces(char const *s);

char			**get_map(char **file_content);
void			reverse_string(char *str);
int				is_empty_line(char *line);
int				count_lines(int fd);
char			**read_map(t_game *game, char *map);
int				check_walls(char **map);
void			check_map(t_game *game);
void			fill_with_ones(t_game *game);

int				check_if_nums(char *num);

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

void			init_map_data(t_game *game, char *path);
void			init_map(t_game *game, char **file_content);

int				game_loop(t_game *game);
void			game_init(t_game *game);
int				init_images(t_game	*game);
void			init_facing_direction(t_game *game);

t_image			read_xmp_image(void *mlx, char *file);

int				key_hook(int keycode, t_game *game);
int				keys(int keycode, t_game *game);

int				init_game_vars(t_game *game);
void			my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color);
int				init_textures(t_game *game);
void			floor_ceiling(t_game *game);
void			calc_hit(t_game *game);
int				ft_routine(t_game *game);
unsigned int	ft_get_ticks(void);
void			init_wall_casting(t_game *game, int i);
void			calc_side_dist(t_game *game);
int				mouse_move_handler(int x, int y, t_game *game);
void			key_right(t_game *game);
void			key_left(t_game *game);

int				close_game(t_game *game);

void			draw_minimap(t_game *game, int i, int j);

#endif
