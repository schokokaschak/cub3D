/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling_rot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:22:52 by akashets          #+#    #+#             */
/*   Updated: 2023/04/25 12:22:56 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	key_left(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(rays->rot_speed) - \
									rays->dir_y * sin(rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(rays->rot_speed) + \
									rays->dir_y * cos(rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(rays->rot_speed) - \
									rays->plane_y * sin(rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(rays->rot_speed) + \
									rays->plane_y * cos(rays->rot_speed);
}

void	key_right(t_game *game)
{
	t_raycast	*rays;

	rays = game->rays;
	rays->old_dir_x = rays->dir_x;
	rays->dir_x = rays->dir_x * cos(-rays->rot_speed) - \
									rays->dir_y * sin(-rays->rot_speed);
	rays->dir_y = rays->old_dir_x * sin(-rays->rot_speed) + \
									rays->dir_y * cos(-rays->rot_speed);
	rays->old_plane_x = rays->plane_x;
	rays->plane_x = rays->plane_x * cos(-rays->rot_speed) - \
									rays->plane_y * sin(-rays->rot_speed);
	rays->plane_y = rays->old_plane_x * sin(-rays->rot_speed) + \
									rays->plane_y * cos(-rays->rot_speed);
}
