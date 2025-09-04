/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:25:27 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/03 16:56:33 by ljeribha         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_cube	cube;

/*	if (ac != 2)
	{
		ft_printf("Usage: %s <map.cub>.\n", av[0]);
		return (1);
	}*/
	init_cube(&cube);
	mlx_hook(cube.win_ptr, 17, 0, close_window, &cube);
	mlx_key_hook(cube.win_ptr, esc_key, &cube);
	mlx_do_key_autorepeatoff(cube.mlx_ptr);
	mlx_loop(cube.mlx_ptr);
	return (0);
}
