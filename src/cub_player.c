/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:00:50 by ljeribha          #+#    #+#             */
/*   Updated: 2025/09/04 18:11:05 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_player(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' ||
				map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				player->x = j;
				player->y = i;
				if (map->map[i][j] == 'N')
					player->angle = 270;
				else if (map->map[i][j] == 'S')
					player->angle = 90;
				else if (map->map[i][j] == 'E')
					player->angle = 0;
				else if (map->map[i][j] == 'W')
					player->angle = 180;
				return ;
			}
			j++;
		}
		i++;
	}
}
