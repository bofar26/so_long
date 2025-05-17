/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:02:32 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 19:53:07 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_width(char **map)
{
	int	width;

	width = ft_strlen(map[0]);
	return (width);
}

int	count_eles(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{	
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count ++;
			j ++;
		}
		i ++;
	}
	return (count);
}

void	find_player_pos(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j ++;
		}
		i ++;
	}
}
