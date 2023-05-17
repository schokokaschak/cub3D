/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/04/28 13:01:47 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_components(t_game *game, char **map, int i)
{
	int	j;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' \
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				if (game->player_direction != 0)
					return (0);
				else
				{
					game->player_direction = map[i][j];
					game->rays->pos_x = j;
					game->rays->pos_y = i;
					map[i][j] = '0';
				}
			}
			else if (map[i][j] != ' ' && map[i][j] != '1' && map[i][j] != '0')
				return (0);
		}
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
									|| map[i][j] == 'S' || map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == (int)ft_strstr_len(map) - 1 \
										|| j == (int)ft_strlen(map[i]) - 2)
					return (0);
				else if (((int)ft_strlen(map[i - 1]) < j + 2 \
				|| map[i - 1][j] == ' ') || ((int)ft_strlen(map[i + 1]) < j + 1 \
				|| map[i + 1][j] == '\n' || map[i + 1][j] == ' ') \
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
					return (0);
			}
		}
	}
	return (1);
}

int	check_empty(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty_line(map[i]))
			break ;
		i++;
	}
	while (map[i])
	{
		if (!is_empty_line(map[i]))
			return (0);
		i++;
	}
	return (1);
}

void	map_check_errors(t_game *game, char **file_content)
{
	if (!check_empty(game->map))
	{
		ft_strstr_free(file_content);
		throw_error(game, MAP_EMPTY_LINES_ERROR);
	}
	if (!check_walls(game->map))
	{
		ft_strstr_free(file_content);
		throw_error(game, MAP_WALL_ERROR);
	}
}

void	init_map(t_game *game, char **file_content)
{
	int	i;

	game->map = get_map(file_content);
	if (!game->map)
	{
		ft_strstr_free(file_content);
		throw_error(game, MAP_EMPTY_ERROR);
	}
	map_check_errors(game, file_content);
	fill_with_ones(game);
	i = 0;
	while (game->map[i])
	{
		reverse_string(game->map[i]);
		i++;
	}
	i = -1;
	if (!check_components(game, game->map, i) || !game->player_direction)
	{
		ft_strstr_free(file_content);
		throw_error(game, MAP_COMPONENTS_ERROR);
	}
}
