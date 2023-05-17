/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_mouse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:37:18 by akashets          #+#    #+#             */
/*   Updated: 2023/04/25 10:57:07 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	mouse_up(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (rays->pitch < 300)
		rays->pitch = rays->pitch + 10;
}

static void	mouse_down(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	if (rays->pitch > -300)
		rays->pitch = rays->pitch - 10;
}

int	mouse_move_handler(int x, int y, t_game *game)
{
	if (y < game->mousey)
		mouse_up(game);
	if (y > game->mousey)
		mouse_down(game);
	if (x > game->mousex)
		key_right(game);
	if (x < game->mousex)
		key_left(game);
	game->mousex = x;
	game->mousey = y;
	return (0);
}
