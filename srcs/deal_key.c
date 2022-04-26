/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/26 20:29:12 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		if (cub->angle < 0)
			cub->angle = 360;
		cub->angle--;
	}
	else if (keycode == RIGHT)
	{
		if (cub->angle > 360)
			cub->angle = 0;
		cub->angle++;
	}
	else if (keycode == W)
		cub->player_y+= 5;
	else if (keycode == A)
		cub->player_x-= 5;
	else if (keycode == D)
		cub->player_x-= 5;
	else if (keycode == S)
		cub->player_y-= 5;
	return (0);
}

int	exit_game(void)
{
	exit(0);
}
