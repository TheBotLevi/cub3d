/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:43:43 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/04 18:38:18 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <fcntl.h>
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
	int		size;
	int		color;
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

//cub_drawing
void	draw_tile(t_cube *cube, t_map *map);

//cub_init
void	init_cube(t_cube *cube);
void	init_map(t_map *map);

//cub_player
void	find_player(t_map *map, t_player *player);

#endif