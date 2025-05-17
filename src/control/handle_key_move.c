/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:28:43 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 21:30:16 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

static void	keep_loop(t_game *g, int mv_x, int mv_y)
{
	g->map.py_x += mv_x;
	g->map.py_y += mv_y;
	ft_printf("the move is : %d\n", g->move);
	render_map(g);
}

static void	exit_with_e(t_game *g, int x, int y)
{
	g->move ++;
	g->map.map[y][x] = 'P';
	ft_printf("You WIN!!\n");
	exit(EXIT_SUCCESS);
}

static void	player_move(t_game *g, int mv_x, int mv_y)
{
	char	heading;
	int		new_x;
	int		new_y;

	new_x = g->map.py_x + mv_x;
	new_y = g->map.py_y + mv_y;
	heading = g->map.map[new_y][new_x];
	if (heading == '1')
		return ;
	else if (heading == 'C' || heading == '0')
	{
		g->map.map[g->map.py_y][g->map.py_x] = '0';
		g->map.map[new_y][new_x] = 'P';
		g->move ++;
		if (heading == 'C')
			g->map.collects --;
	}
	else if (heading == 'E')
	{
		if (g->map.collects == 0)
			exit_with_e(g, new_x, new_y);
		else
			return ;
	}
	keep_loop(g, mv_x, mv_y);
}

int	handle_key_move(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		player_move(g, 0, -1);
	else if (keycode == KEY_A)
		player_move(g, -1, 0);
	else if (keycode == KEY_S)
		player_move(g, 0, 1);
	else if (keycode == KEY_D)
		player_move(g, 1, 0);
	else if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
