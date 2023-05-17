/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:10:12 by nradin            #+#    #+#             */
/*   Updated: 2023/04/27 11:30:18 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	draw_square(t_game *game, int x, int y, uint32_t color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_back_bord(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			if (i < 20 || j < 20 || i > 179 || j > 179)
				my_mlx_pixel_put(game, i, j + 400, \
					create_trgb(255, 255, 255, 255));
			else
				my_mlx_pixel_put(game, i, j + 400, \
					create_trgb(0, 255, 255, 255));
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game, int i, int j)
{
	draw_back_bord(game);
	draw_square(game, 100, 500, create_trgb(0, 0, 255, 0));
	i = 0;
	while (i < (int)ft_strstr_len(game->map))
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]) - 1)
		{
			if ((int)game->rays->pos_x - j < 5 \
				&& (int)game->rays->pos_x - j > -4 && \
					(int)game->rays->pos_y - i < 5 \
						&& (int)game->rays->pos_y - i > -4)
			{
				if (game->imap[i][j] == 1)
				{
					draw_square(game, 100 - ((int)game->rays->pos_y - i) * 20, \
								500 - ((int)game->rays->pos_x - j) * 20, \
												create_trgb(0, 255, 0, 0));
				}
			}
			j++;
		}
		i++;
	}
}
