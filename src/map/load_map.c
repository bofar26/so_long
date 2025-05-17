/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:15:09 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 19:58:25 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	read_map(const char *map_filename)
{
	char	**map_contenu;
	int		fd;
	int		x;
	int		y;
	t_map	map_to_play;

	x = 0;
	y = 0;
	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		map_error();
	map_contenu = lst_to_map(map_filename);
	malloc_error(map_contenu);
	if (!map_input_check(map_contenu))
		map_error();
	find_player_pos(map_contenu, &x, &y);
	map_to_play.map = map_contenu;
	map_to_play.height = map_height(map_contenu);
	map_to_play.width = map_width(map_contenu);
	map_to_play.py_x = x;
	map_to_play.py_y = y;
	map_to_play.collects = count_eles(map_contenu, 'C');
	return (map_to_play);
}

void	load_map(t_game *g)
{
	g->tex.player.img = mlx_xpm_file_to_image(g->mlx, "./src/xpm/player.xpm",
			&g->tex.player.width, &g->tex.player.height);
	g->tex.wall.img = mlx_xpm_file_to_image(g->mlx, "./src/xpm/wall.xpm",
			&g->tex.wall.width, &g->tex.wall.height);
	g->tex.path.img = mlx_xpm_file_to_image(g->mlx, "./src/xpm/path.xpm",
			&g->tex.path.width, &g->tex.path.height);
	g->tex.collectible.img = mlx_xpm_file_to_image(g->mlx,
			"./src/xpm/collectible.xpm", &g->tex.collectible.width,
			&g->tex.collectible.height);
	g->tex.exit.img = mlx_xpm_file_to_image(g->mlx, "./src/xpm/exit.xpm",
			&g->tex.exit.width, &g->tex.exit.height);
}

static void	draw_map(t_game *g, char c, int x, int y)
{
	t_img	*pic;

	if (c == '0')
		pic = &g->tex.path;
	else if (c == '1')
		pic = &g->tex.wall;
	else if (c == 'C')
		pic = &g->tex.collectible;
	else if (c == 'E')
		pic = &g->tex.exit;
	else if (c == 'P')
		pic = &g->tex.player;
	else
		return ;
	mlx_put_image_to_window(g->mlx, g->window, pic->img,
		x * pic->width, y * pic->height);
}

void	render_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			draw_map(g, g->map.map[y][x], x, y);
			x ++;
		}
		y ++;
	}
}
