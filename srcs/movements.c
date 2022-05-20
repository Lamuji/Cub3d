/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:55:24 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/20 15:00:22 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	move_right(t_cub *cub, double Xdis, double Ydis)
{
	cub->set_key = 0;
	Xdis = cos(convert_ang(cub->angle - 90)) * 1;
	Ydis = sin(convert_ang(cub->angle - 90)) * 1;
	if (cub->map[(int)round((cub->player_y + Ydis)/8)][(int)round((cub->player_x + Xdis)/8)] != '1')
	{
		cub->player_x += Xdis;
		cub->player_y += Ydis;
	}
}

static	void	move_left(t_cub *cub, double Xdis, double Ydis)
{
	cub->set_key = 0;
	Xdis = cos(convert_ang(cub->angle + 90)) * 1;
	Ydis = sin(convert_ang(cub->angle + 90)) * 1;
	if (cub->map[(int)round((cub->player_y + Ydis)/8)][(int)round((cub->player_x + Xdis)/8)] != '1')
	{
		cub->player_x += Xdis;
		cub->player_y += Ydis;
	}
}

static	void	move_backward(t_cub *cub, double Xdis, double Ydis)
{
	cub->set_key = 0;
	if (cub->map[(int)round((cub->player_y + Ydis)/8)][(int)round((cub->player_x + Xdis)/8)] != '1')
	{
		cub->player_x += Xdis;
		cub->player_y += Ydis;
	}
}

static	void	move_forward(t_cub *cub, double Xdis, double Ydis)
{
	cub->set_key = 0;
	if (cub->map[(int)round((cub->player_y - Ydis)/8)][((int)round(cub->player_x - Xdis)/8)] != '1')
	{	
		cub->player_x -= Xdis;
		cub->player_y -= Ydis;
	}
}

void	check_move(t_cub *cub)
{
    double Xdis;
    double Ydis;

    Xdis = cos(convert_ang(cub->angle)) * 2;
    Ydis = sin(convert_ang(cub->angle)) * 2;
    if (cub->set_key == 1)
        move_forward(cub, Xdis, Ydis);
    if (cub->set_key == 2)
        move_backward(cub, Xdis, Ydis);
	if (cub->set_key == 3)
		move_left(cub, Xdis, Ydis);
	if (cub->set_key == 4)
		move_right(cub, Xdis, Ydis);
}