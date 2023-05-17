/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:45 by nradin            #+#    #+#             */
/*   Updated: 2023/04/23 11:35:38 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	key_up(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->imap[(int)rays->pos_y][(int)(rays->pos_x + \
								rays->dir_x * rays->move_speed)] == 0)
		rays->pos_x += rays->dir_x * rays->move_speed;
	if (game->imap[(int)(rays->pos_y + rays->dir_y * \
							rays->move_speed)][(int)rays->pos_x] == 0)
		rays->pos_y += rays->dir_y * rays->move_speed;
}

static void	key_down(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->imap[(int)rays->pos_y][(int)(rays->pos_x - \
								rays->dir_x * rays->move_speed)] == 0)
		rays->pos_x -= rays->dir_x * rays->move_speed;
	if (game->imap[(int)(rays->pos_y - rays->dir_y * \
							rays->move_speed)][(int)rays->pos_x] == 0)
		rays->pos_y -= rays->dir_y * rays->move_speed;
}

static void	key_a(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->imap[(int)rays->pos_y][(int)(rays->pos_x - \
						rays->dir_y * rays->move_speed)] == 0)
	rays->pos_x -= rays->dir_y * rays->move_speed;
	if (game->imap[(int)(rays->pos_y + rays->dir_x * \
				rays->move_speed)][(int)rays->pos_x] == 0)
	rays->pos_y += rays->dir_x * rays->move_speed;
}

static void	key_d(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (game->imap[(int)rays->pos_y][(int)(rays->pos_x + \
					rays->dir_y * rays->move_speed)] == 0)
	rays->pos_x += rays->dir_y * rays->move_speed;
	if (game->imap[(int)(rays->pos_y - rays->dir_x * \
				rays->move_speed)][(int)rays->pos_x] == 0)
	rays->pos_y -= rays->dir_x * rays->move_speed;
}

int	keys(int keycode, t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->oldtime = rays->time;
	rays->time = ft_get_ticks();
	rays->frametime = (rays->time - rays->oldtime) / 1000.0;
	rays->move_speed = rays->frametime * 20.0;
	rays->rot_speed = rays->frametime * 10.0;
	if (keycode == 13)
		key_up(game);
	if (keycode == 1)
		key_down(game);
	if (keycode == 0)
		key_a(game);
	if (keycode == 2)
		key_d(game);
	if (keycode == 124)
		key_right(game);
	if (keycode == 123)
		key_left(game);
	if (keycode == 53)
		close_game(game);
	return (0);
}
