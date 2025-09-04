/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:43:43 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/03 18:50:06 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "../miniLibX/minilibx-linux/mlx.h"
#include "../libft/libft.h"

# define WIDTH 1080
# define HEIGHT 800

typedef struct s_cube
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		bpp; //bits per pixel
	int		len; //line length
	int		en; //endian
	double		*move_speed;
}	t_cube;

typedef struct s_map
{
	char	**map;
	double		y;
	double		x;
}	t_map;

typedef struct s_player
{
	int	y;
	int	x;
	int	angle;
}	t_player;

// cub_utils
int	close_window(t_cube *cube);
void	clean_up(t_cube *cube);

// cub_hooks
int	esc_key(int keycode, t_cube *cube);

#endif