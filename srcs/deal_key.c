/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/20 03:06:09 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
		cub->angle--;
	else if (keycode == RIGHT)
		cub->angle++;
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
	//vision(cub);
	return (0);
}

int	exit_game(void)
{
	exit(0);
}
