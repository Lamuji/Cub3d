/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/23 18:28:40 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

double convert_ang(double angle)
{
	return (angle * (3.14159 / 180));
}

int	deal_mouse(int x, int y, t_cub *cub)
{
	(void)y;
	if (x < cursor)
	{
		if (cub->angle <= 0)
			cub->angle = 360;
		cub->angle -= 4;
	}
	if (x > cursor)
	{
		if (cub->angle >= 360)
			cub->angle = 0;
		cub->angle += 4;
	}
	cursor = x;
	return 0;
}

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		if (cub->angle <= 0)
			cub->angle = 360;
		cub->angle -= 3;
	}
	else if (keycode == RIGHT)
	{
		if (cub->angle >= 360)
			cub->angle = 0;
		cub->angle += 3;
	}
	else if (keycode == W)
		cub->set_key = 1;
	else if (keycode == A)
	 	cub->set_key = 3;
	else if (keycode == D)
	 	cub->set_key = 4;
	else if (keycode == S)
		cub->set_key = 2;
	return (0);
}

int	exit_game(void)
{
	exit(0);
}
