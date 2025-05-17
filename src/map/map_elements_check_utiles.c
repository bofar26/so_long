/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check_utiles.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:12:21 by mipang            #+#    #+#             */
/*   Updated: 2025/05/16 16:24:23 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid(char c)
{
	return (c == '0' || c == '1' || c == 'E' || c == 'P' || c == 'C');
}

static int	count_char(char **str, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				count ++;
			j ++;
		}
		i ++;
	}
	return (count);
}

static int	is_char_in(char **str, int *ascii)
{
	int	i;

	i = 0;
	if (ascii['C'] == 0 || ascii['1'] == 0
		|| ascii['P'] == 0 || ascii['E'] == 0)
		return (0);
	while (i < 256)
	{
		if (ascii[i])
		{
			if (i != 'C' && i != '0' && i != '1' && i != 'P' && i != 'E')
				return (0);
		}
		i ++;
	}
	if (count_char(str, 'P') > 1 || count_char(str, 'E') > 1)
		return (0);
	return (1);
}

int	map_element_check(char **map)
{
	int	i;
	int	j;
	int	ascii[256];

	i = 0;
	while (i < 256)
		ascii[i ++] = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid(map[i][j] == 0))
				return (0);
			if (ascii[(int)map[i][j]] == 0)
				ascii[(int)map[i][j]] = 1;
			j++;
		}
		i ++;
	}
	if (!is_char_in(map, ascii))
		return (0);
	return (1);
}
