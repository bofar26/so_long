/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:26:21 by mipang            #+#    #+#             */
/*   Updated: 2025/05/16 16:17:22 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_map{
	char	**map;
	int	width;
	int	height;
	int	py_x;
	int	py_y;
	int	collects;
} t_map;

typedef struct t_img{
	void *img;
	int height;
	int width;
} t_img;

typedef struct t_tex{
	t_img player;
	t_img wall;
	t_img path;
	t_img collectible;
	t_img exit;
} t_tex;

typedef struct t_game{
	void *mlx;
	void *window;
	t_tex tex;
	t_map map;
	int move;
} t_game;

void	load_map(t_game *g);
void	render_map(t_game *g);
void	map_error();
void	find_player_pos(char **map, int *x, int *y);
void	free_all_simple(char **ptr);
void	malloc_error(void *ptr);
char	**lst_to_map(const char *map_filename);
int	handle_exit(void *param);
int	map_check_path_valid(char **map);
int	map_input_check(char **map);
int	map_height(char **map);
int	map_width(char **map);
int	count_eles(char **map, char c);
int	map_element_check(char **map);
int handle_key_move(int keycode, t_game *g);
t_map	read_map(const char *map_filename);

#endif

