/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_floor_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:15:41 by akashets          #+#    #+#             */
/*   Updated: 2023/04/25 11:11:19 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	floor_ceiling(t_game *game)
{
	int		y;
	int		x;
	int		w;

	y = -1;
	while (++y < game->screen_width)
	{
		x = -1;
		while (++x < game->screen_height / 2)
			my_mlx_pixel_put(game, y, game->screen_height \
									- x - 1, game->floor_color);
		w = -1;
		while (++w < game->screen_height / 2)
			my_mlx_pixel_put(game, y, w, game->ceiling_color);
	}
}
