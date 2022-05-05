/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:55:24 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/05 08:40:09 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	move_backward(t_cub *cub, double Xdis, double Ydis)
{
    cub->set_key = 0;
    cub->player_x += Xdis;
    cub->player_y += Ydis;
}

static	void	move_forward(t_cub *cub, double Xdis, double Ydis)
{
    cub->set_key = 0;
    cub->player_x -= Xdis;
    cub->player_y -= Ydis;
}

void	check_move(t_cub *cub)
{
    double Xdis;
    double Ydis;

    Xdis = cos(convert_ang(cub->angle)) * 5;
    Ydis = sin(convert_ang(cub->angle)) * 5;
    if (cub->set_key == 1)
        move_forward(cub, Xdis, Ydis);
    if (cub->set_key == 2)
        move_backward(cub, Xdis, Ydis);
	// if (cub->set_key == 3)
	// 	move_left(cub, Xdis, Ydis);
}