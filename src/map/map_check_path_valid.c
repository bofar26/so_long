/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:56:34 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 20:32:21 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map_height(map) || x >= map_width(map))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

static char	**duplicate_map(char **map)
{
	int		height;
	int		i;
	char	**map_copy;

	i = 0;
	height = map_height(map);
	map_copy = malloc(sizeof(char *) * (height + 1));
	if (!map_copy)
		return (NULL);
	map_copy[height] = NULL;
	while (i < height)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			free_all_simple(map_copy);
			return (NULL);
		}
		i ++;
	}
	return (map_copy);
}

static int	is_valid_path(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C' || str[i] == 'E')
			return (0);
		i ++;
	}
	return (1);
}

int	map_check_path_valid(char **map)
{
	int		x;
	int		y;
	int		i;
	char	**map_copy;

	x = 0;
	y = 0;
	i = 0;
	map_copy = duplicate_map(map);
	malloc_error(map_copy);
	find_player_pos(map_copy, &x, &y);
	flood_fill(map_copy, x, y);
	while (map_copy[i])
	{
		if (!is_valid_path(map_copy[i]))
		{
			free_all_simple(map_copy);
			return (0);
		}
		i ++;
	}
	free_all_simple(map_copy);
	return (1);
}
