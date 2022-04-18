/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/18 02:49:09 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		cub->angle--;
		vision(cub);
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
