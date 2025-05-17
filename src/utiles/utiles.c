/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:53:52 by mipang            #+#    #+#             */
/*   Updated: 2025/05/15 20:33:59 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	malloc_error(void *ptr)
{
	if (!ptr)
		map_error();
}

int	handle_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	free_all_simple(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i ++;
	}
	free(ptr);
}
