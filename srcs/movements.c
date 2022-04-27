/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:55:24 by ramzi             #+#    #+#             */
/*   Updated: 2022/04/27 08:22:57 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void    move_forward(t_cub *cub)
{
    double Xdis;
    double Ydis;
    Xdis = cos(convert_ang(cub->angle)) * SPEED;
    Ydis = sin(convert_ang(cub->angle)) * SPEED;
    cub->player_x -= Xdis;
    cub->player_y -= Ydis; 
}