/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:45:06 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/04 17:54:41 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_cube(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
	cube->img = mlx_new_image(cube->mlx_ptr, WIDTH, HEIGHT);
	cube->addr = mlx_get_data_addr(cube->img, &cube->bpp, &cube->len, &cube->en);
}

void	init_map(t_map *map)
{
	static char	*default_map[] = {
		"1111111",
		"1000001",
		"1000N01",
		"1000001",
		"1000001",
		"1000001",
		"1111111",
		NULL
	};
	int	i;
	int	map_size;

	map_size = 7;
	i = 0;
	map->map = malloc(sizeof(char *) * (map_size + 1));
	if (!map->map)
		return ;
	while (default_map[i])
	{
		map->map = ft_strdup(default_map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->x = 0;
	map->y = 0;
	map->size = 20; //tile size for rendering
	map->color = 0x000000; //default colour
}
