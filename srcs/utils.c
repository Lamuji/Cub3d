/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:25:18 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/24 22:15:37 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_value(t_cub *cub)
{
	cub->dx = 0;
	cub->dy = 0;
	cub->fov_lenght = 0;
	cub->fx = 0;
	cub->fy = 0;
	cub->Hx = 0;
	cub->Hy = 0;
	cub->pix_x = 0;
	cub->pix_y = 0;
	cub->player_x = 0;
	cub->player_y = 0;
	cub->Vx = 0;
	cub->Vy = 0;
	cub->slice_height = 0;
	cub->wall_bottom = 0;
	cub->wall_top = 0;
	cub->render.index = 0;
	cub->render.tx = 0;
	cub->render.ty = 0;
}

unsigned long rgb_to_hex(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}