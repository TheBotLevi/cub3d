/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:57:37 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/04 18:38:26 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	put_pixel_mlx(t_cube *cube, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = cube->addr + (y * cube->len + x * (cube->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_tile(t_cube *cube, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->size)
	{
		while (j < map->size)
		{
			put_pixel_mlx(cube, map->x, map->y, map->color);
			j++;
		}
		i++;
	}
}
