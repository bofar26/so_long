/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:41:06 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 20:02:37 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	parameter_check(int argc, char **str)
{
	int	len;

	if (argc != 2)
		map_error();
	len = ft_strlen(str[1]);
	if (len < 5)
		map_error();
	if (ft_strncmp(str[1] + len - 4, ".ber", 4) != 0)
		map_error();
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;
	t_game	g;

	parameter_check(argc, argv);
	g.map = read_map(argv[1]);
	mlx = mlx_init();
	window = mlx_new_window(mlx, g.map.width * 32,
			g.map.height * 32, "so long");
	g.mlx = mlx;
	g.window = window;
	g.move = 0;
	ft_printf("how many collects: %d\n", g.map.collects);
	load_map(&g);
	render_map(&g);
	mlx_hook(window, 17, 0, handle_exit, &g);
	mlx_key_hook(window, handle_key_move, &g);
	mlx_loop(mlx);
	return (0);
}
