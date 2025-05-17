/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:25:59 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 20:40:57 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*get_map_by_line(const char *map_filename)
{
	int		fd;
	char	*line;
	char	*line_rmnl;
	t_list	*line_group;

	line_group = NULL;
	fd = open(map_filename, O_RDONLY);
	if (fd < 0)
		map_error();
	line = get_next_line(fd);
	while (line)
	{
		line_rmnl = ft_strtrim(line, "\n");
		ft_lstadd_back(&line_group, ft_lstnew(line_rmnl));
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_group);
}

static void	map_out_protect(char **map_out, int i)
{
	if (!map_out[i])
	{
		free_all_simple(map_out);
		map_error();
	}
}

char	**lst_to_map(const char *map_filename)
{
	t_list	*map_list;
	t_list	*head;
	char	**map_out;
	int		lst_size;
	int		i;

	i = 0;
	map_list = get_map_by_line(map_filename);
	malloc_error(map_list);
	head = map_list;
	lst_size = ft_lstsize(map_list);
	map_out = malloc(sizeof(char *) * (lst_size + 1));
	malloc_error(map_out);
	while (i < lst_size)
	{
		map_out[i] = ft_strdup(map_list -> content);
		map_out_protect(map_out, i);
		i ++;
		map_list = map_list -> next;
	}
	map_out[lst_size] = NULL;
	ft_lstclear(&head, free);
	return (map_out);
}
