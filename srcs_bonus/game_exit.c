/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:06:08 by nradin            #+#    #+#             */
/*   Updated: 2023/04/25 10:57:01 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	free_textures(t_game *game)
{
	int	i;

	if (game->texture)
	{
		i = 0;
		while (i < 4)
		{
			if (game->texture[i] != NULL)
				free(game->texture[i]);
			i++;
		}
		free(game->texture);
	}
	if (game->wall_north.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_north.xpm_ptr);
	if (game->wall_south.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_south.xpm_ptr);
	if (game->wall_west.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_west.xpm_ptr);
	if (game->wall_east.xpm_ptr)
		mlx_destroy_image(game->mlx, game->wall_east.xpm_ptr);
}

void	free_game(t_game *game)
{
	int	i;

	if (game->imap != NULL)
	{
		i = 0;
		while (i < (int)ft_strstr_len(game->map))
		{
			free(game->imap[i]);
			i++;
		}
		free(game->imap);
	}
	free_textures(game);
	if (game->map)
		ft_strstr_free(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->rays)
		free(game->rays);
	if (game->fc)
		free(game->fc);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit (0);
}
