/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:02:52 by akashets          #+#    #+#             */
/*   Updated: 2023/04/25 10:57:05 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	init_facing_direction(t_game *game)
{
	if (game->player_direction == 'E')
	{
		game->rays->dir_x = -1;
		game->rays->plane_y = 0.66;
	}
	if (game->player_direction == 'N')
	{
		game->rays->dir_y = -1;
		game->rays->plane_x = -0.66;
	}
	if (game->player_direction == 'W')
	{
		game->rays->dir_x = 1;
		game->rays->plane_y = -0.66;
	}
	if (game->player_direction == 'S')
	{
		game->rays->dir_y = 1;
		game->rays->plane_x = 0.66;
	}
}

int	init_game_vars(t_game *game)
{
	game->rays = ft_calloc(sizeof(t_raycast), 1);
	if (game->rays == NULL)
		return (0);
	game->mlx = mlx_init();
	game->rays->mlx = game->mlx;
	game->screen_width = 1200;
	game->screen_height = 900;
	game->tex_width = 64;
	game->tex_height = 64;
	game->win = mlx_new_window(game->mlx, game->screen_width, \
									game->screen_height, "Game");
	game->rays->win = game->win;
	game->texture = (uint32_t **) ft_calloc(sizeof(uint32_t *), 4);
	if (game->texture == NULL)
		return (0);
	return (1);
}

int	*convert(unsigned char *img_data, int img_width, int img_height)
{
	int	*int_array;
	int	i;
	int	j;
	int	k;

	int_array = (int *) malloc(img_width * img_height * sizeof(int));
	if (int_array == NULL)
		return (NULL);
	i = -1;
	while (++i < img_height)
	{
		j = -1;
		while (++j < img_width)
		{
			k = (i * img_width + j) * 4;
			int_array[i * img_width + j] = (img_data[k + 3] << 24) | \
			(img_data[k + 2] << 16) | (img_data[k + 1] << 8) | img_data[k];
		}
	}
	return (int_array);
}

int	init_textures(t_game *g)
{
	unsigned char	*img_data;
	int				bpp;

	bpp = 0;
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_east.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[0] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[0] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_north.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[1] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[1] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_west.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[2] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[2] == NULL)
		return (0);
	img_data = (unsigned char *)mlx_get_data_addr(g->wall_south.xpm_ptr, &bpp, \
											&g->size_line, &g->rays->endian);
	g->texture[3] = (uint32_t *)convert(img_data, g->tex_width, g->tex_height);
	if (g->texture[3] == NULL)
		return (0);
	return (1);
}
