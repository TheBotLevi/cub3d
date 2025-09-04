/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:09:44 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/03 16:39:43 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	esc_key(int keycode, t_cube *cube)
{
	if (keycode == 65307)
	{
		ft_printf("Exiting Program!\n");
		close_window(cube);
	}
	return (0);
}
