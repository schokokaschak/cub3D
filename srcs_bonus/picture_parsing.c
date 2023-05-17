/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:02:57 by nradin            #+#    #+#             */
/*   Updated: 2023/04/25 10:57:24 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

t_image	read_xmp_image(void *mlx, char *file)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, file, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		write(2, SPRITE_ERROR, ft_strlen(SPRITE_ERROR));
	return (sprite);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color)
{
	char	*dst;

	dst = game->rays->img_addr + (y * game->rays->line_length + \
		x * (game->rays->bits_per_pixel / 8));
	*(int *)dst = color;
}

unsigned int	ft_get_ticks(void)
{
	struct timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	return ((now.tv_sec * 1000) + (now.tv_nsec / 1000000));
}
