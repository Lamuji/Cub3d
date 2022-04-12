/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/12 04:02:05 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	dda_algo(t_cub *cub, int dx, int dy)
{
	double xinc;
	double yinc;
	int step;
	int i = 1;
	if (abs(dx) > abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	xinc = floor(dx/step);
	yinc = floor(dy/step);
	while (i <= step)
	{
		my_mlx_pixel_put(&cub->img, cub->player_x, cub->player_y, 0x000000FF);
		cub->player_x += xinc;
		cub->player_y += yinc;
		i++;
	}
}

void	vision(t_cub *cub, int dx, int dy)
{
	// int dx = cub->widthsquare - cub->player_x;
	// int dy = cub->height - cub->player_y;
	dda_algo(cub, dx, dy);
}

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		vision(cub, (cub->widthsquare - 1) - cub->player_x, (cub->height - 1))
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
