/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:18:22 by nradin            #+#    #+#             */
/*   Updated: 2023/04/23 12:21:57 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	add_color_variable(int *color, char *rgb)
{
	char	**colors;
	int		i;

	colors = ft_split(rgb, ',');
	i = 0;
	while (colors[i])
	{
		if (*color != 0 || (i == 3 || (i < 2 && !colors[i + 1])) \
			|| !check_if_nums(colors[i]) || ft_atoi(colors[i]) > 255)
		{
			write(2, MAP_ARGS_COLOR_ERROR, ft_strlen(MAP_ARGS_COLOR_ERROR));
			ft_strstr_free(colors);
			return (1);
		}
		i++;
	}
	*color = create_trgb(0, ft_atoi(colors[0]), \
		ft_atoi(colors[1]), ft_atoi(colors[2]));
	ft_strstr_free(colors);
	return (0);
}

int	add_path_variable(t_game *game, t_image *image, char *path)
{
	if ((*image).xpm_ptr != NULL)
		return (1);
	*image = read_xmp_image(game->mlx, path);
	if ((*image).xpm_ptr == NULL)
		return (1);
	return (0);
}

int	pick_variable(t_game *game, char **var)
{
	if (!ft_strncmp(var[0], "NO", 3))
		return (add_path_variable(game, &game->wall_north, var[1]));
	if (!ft_strncmp(var[0], "SO", 3))
		return (add_path_variable(game, &game->wall_south, var[1]));
	if (!ft_strncmp(var[0], "WE", 3))
		return (add_path_variable(game, &game->wall_west, var[1]));
	if (!ft_strncmp(var[0], "EA", 3))
		return (add_path_variable(game, &game->wall_east, var[1]));
	if (!ft_strncmp(var[0], "F", 2))
		return (add_color_variable(&game->floor_color, var[1]));
	if (!ft_strncmp(var[0], "C", 2))
		return (add_color_variable(&game->ceiling_color, var[1]));
	return (1);
}

void	init_map_variables(t_game *game, char **file_content)
{
	int		i;
	int		var_count;
	char	**var;

	i = 0;
	var_count = 0;
	while (file_content[i])
	{
		var = ft_split_spaces(file_content[i]);
		if (*var != NULL)
		{
			if (ft_strstr_len(var) != 2 || pick_variable(game, var))
			{
				ft_strstr_free(file_content);
				ft_strstr_free(var);
				throw_error(game, MAP_ARGS_ERROR);
			}
			else
				var_count++;
		}
		ft_strstr_free(var);
		if (var_count == 6)
			break ;
		i++;
	}
}

void	init_map_data(t_game *game, char *path)
{
	char	**file_content;

	file_content = read_map(game, path);
	init_map_variables(game, file_content);
	init_map(game, file_content);
	ft_strstr_free(file_content);
}
