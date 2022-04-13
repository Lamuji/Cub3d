/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/13 04:39:32 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	dda_algo(t_cub *cub, int dx, int dy)
{
	double xinc = 0;
	double yinc = 0;
	int step;
	int i = 1;
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	xinc = (double)dx / step;
	yinc = (double)dy / step;
	while (i <= step)
	{
		my_mlx_pixel_put(&cub->img, floor(cub->player_x), cub->player_y, 0x000000FF);
		cub->player_x = cub->player_x + xinc;
		cub->player_y = cub->player_y + yinc;
		i++;
	}
}

void	vision(t_cub *cub)
{
	which_direction(cub->map, cub->angle);
	int dx = cub->player_x;
	int dy = 0;
	dda_algo(cub, dx, dy);
}

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		
		dda_algo(cub);
	}
	// else if (keycode == D)
	// {
	// 	map->pos = 2;
	// 	move_right(map);
	// }
	// else if (keycode == A)
	// {
	// 	map->pos = 3;
	// 	move_left(map);
	// }
	// else if (keycode == S)
	// {
	// 	move_down(map);
	// 	map->pos = 4;
	// }
	return (0);
}

int	exit_game(void)
{
	exit(0);
}
