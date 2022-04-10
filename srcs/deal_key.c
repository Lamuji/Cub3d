/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:24:37 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/10 05:13:25 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	draw_ray(t_cub *cub, int dir)
{
	while ()
}
void	vision(t_cub *cub)
{
		draw_ray(cub, which_direction(cub));
}

// void	go_left(t_cub *cub)
// {
	
// }

int	deal_key(int keycode, t_cub *cub)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == LEFT)
	{
		go_left(cub);
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
