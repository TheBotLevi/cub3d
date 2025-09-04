/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:21:01 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/03 16:40:16 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_up(t_cube *cube)
{
	if (cube->img)
	{
		mlx_destroy_image(cube->mlx_ptr, cube->img);
		cube->img = NULL;
	}
	if (cube->mlx_ptr)
	{
		if (cube->win_ptr)
		{
			mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
			cube->win_ptr = NULL;
		}
		mlx_destroy_display(cube->mlx_ptr);
		cube->mlx_ptr = NULL;
	}
}

int	close_window(t_cube *cube)
{
	clean_up(cube);
	exit(0);
}
