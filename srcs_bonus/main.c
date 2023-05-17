/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:30:46 by nradin            #+#    #+#             */
/*   Updated: 2023/04/25 10:57:12 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	fill_map_int(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		game->imap[i] = malloc(sizeof(int) * ft_strlen(game->map[i]));
		if (!game->imap[i])
		{
			perror("malloc int map");
			close_game(game);
		}
		j = 0;
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			game->imap[i][j] = game->map[i][j] - 48;
			j++;
		}
		i++;
	}
}

int	init_map_int(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->imap = malloc(sizeof(int *) * i);
	if (!game->imap)
	{
		perror("malloc int map");
		close_game(game);
		return (0);
	}
	fill_map_int(game);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	(void)argv;
	game = ft_calloc(sizeof(t_game), 1);
	if (game == NULL)
		throw_error(game, "Memory allocation!");
	if (argc != 2)
		throw_error(game, ARGS_ERROR);
	if (!init_game_vars(game))
		throw_error(game, "Memory allocation!");
	init_map_data(game, argv[1]);
	init_facing_direction(game);
	if (!init_textures(game))
		throw_error(game, "Memory allocation!");
	if (!init_map_int(game))
		return (0);
	mlx_hook(game->win, 17, 1L << 0, close_game, game);
	mlx_key_hook(game->win, keys, game);
	mlx_loop_hook(game->mlx, ft_routine, game);
	mlx_loop(game->mlx);
	return (0);
}
