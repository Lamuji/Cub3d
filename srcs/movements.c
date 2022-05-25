/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:55:24 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/25 13:36:22 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	move_right(t_cub *cub, double xdis, double ydis)
{
	cub->set_key = 0;
	xdis = cos(convert_ang(cub->angle - 90.0)) * 1.0;
	ydis = sin(convert_ang(cub->angle - 90.0)) * 1.0;
	if (cub->map[(int)round(((cub->player_y + ydis) / 8.0))]
		[(int)round(((cub->player_x + xdis) / 8.0))] != '1')
	{
		cub->player_x += xdis;
		cub->player_y += ydis;
	}
}

static	void	move_left(t_cub *cub, double xdis, double ydis)
{
	cub->set_key = 0;
	xdis = cos(convert_ang(cub->angle + 90.0)) * 1;
	ydis = sin(convert_ang(cub->angle + 90.0)) * 1;
	if (cub->map[(int)round(((cub->player_y + ydis) / 8.0))]
		[(int)round(((cub->player_x + xdis) / 8.0))] != '1')
	{
		cub->player_x += xdis;
		cub->player_y += ydis;
	}
}

static	void	move_backward(t_cub *cub, double xdis, double ydis)
{
	cub->set_key = 0;
	if (cub->map[(int)round(((cub->player_y + ydis) / 8.0))]
		[(int)round(((cub->player_x + xdis) / 8.0))] != '1')
	{
		cub->player_x += xdis;
		cub->player_y += ydis;
	}
}

static	void	move_forward(t_cub *cub, double xdis, double ydis)
{
	cub->set_key = 0;
	if (cub->map[(int)round(((cub->player_y - ydis) / 8.0))]
		[(int)round(((cub->player_x - xdis) / 8.0))] != '1')
	{
		cub->player_x -= xdis;
		cub->player_y -= ydis;
	}
}

void	check_move(t_cub *cub)
{
	double	xdis;
	double	ydis;

	xdis = cos(convert_ang(cub->angle)) * 2.0;
	ydis = sin(convert_ang(cub->angle)) * 2.0;
	if (cub->set_key == 1)
		move_forward(cub, xdis, ydis);
	if (cub->set_key == 2)
		move_backward(cub, xdis, ydis);
	if (cub->set_key == 3)
		move_left(cub, xdis, ydis);
	if (cub->set_key == 4)
		move_right(cub, xdis, ydis);
}
