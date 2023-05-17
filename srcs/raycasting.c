/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:14:47 by akashets          #+#    #+#             */
/*   Updated: 2023/04/26 11:19:59 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	calc_draw(t_game *game)
{
	t_raycast	*r;

	r = game->rays;
	r->line_height = (int)(game->screen_height / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + game->screen_height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + game->screen_height / 2;
	if (r->draw_end >= game->screen_height)
		r->draw_end = game->screen_height - 1;
	r->texnum = game->imap[r->map_y][r->map_x];
	if (r->side % 2 == 0)
		r->wallx = r->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wallx = r->pos_x + r->perp_wall_dist * r->ray_dir_x;
	r->wallx -= floor((r->wallx));
	r->texx = (int)(r->wallx * (double)game->tex_width);
}

static void	draw_walls(t_game *game, int i)
{
	int			j;
	t_raycast	*rays;

	rays = game->rays;
	if (rays->side % 2 == 0 && rays->ray_dir_x > 0)
		rays->texx = game->tex_width - rays->texx - 1;
	if (rays->side % 2 == 1 && rays->ray_dir_y < 0)
		rays->texx = game->tex_width - rays->texx - 1;
	rays->step = 1.0 * game->tex_height / rays->line_height;
	rays->texpos = (rays->draw_start - game->screen_height / 2 + \
								rays->line_height / 2) * rays->step;
	j = rays->draw_start;
	while (j < rays->draw_end)
	{
		rays->texy = (int)rays->texpos & (game->tex_height - 1);
		rays->texpos += rays->step;
		rays->colr = game->texture[rays->texnum + rays->side - 1] \
		[game->tex_height * rays->texy + rays->texx];
		if (rays->side % 2 == 1)
			rays->colr = rays->colr / 2;
		my_mlx_pixel_put(game, i, j, rays->colr);
		j++;
	}
}

static void	wall_casting(t_game *game)
{
	int			i;
	t_raycast	*rays;

	rays = game->rays;
	i = 0;
	while (i < game->screen_width)
	{
		init_wall_casting(game, i);
		calc_side_dist(game);
		calc_hit(game);
		calc_draw(game);
		draw_walls(game, i);
		i++;
	}
}

int	ft_routine(t_game *game)
{
	t_raycast	*rays;

	mlx_clear_window(game->mlx, game->win);
	game->rays->time = ft_get_ticks();
	rays = game->rays;
	rays->img = mlx_new_image(game->mlx, game->screen_width, \
													game->screen_height);
	rays->img_addr = mlx_get_data_addr(rays->img, &rays->bits_per_pixel, \
	&rays->line_length, &rays->endian);
	mlx_hook(game->win, 2, 1L << 0, keys, game);
	floor_ceiling(game);
	wall_casting(game);
	mlx_put_image_to_window(game->mlx, game->win, rays->img, 0, 0);
	return (0);
}
