/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/05 07:40:38 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	ceiling(t_cub *cub, int x)
{
	int i = cub->wall_top;
		while (i > 0)
		{
			my_mlx_pixel_put(&cub->img, x, i, 0x00D1D8FF);
			i--;
		}
}

static	void	ground(t_cub *cub, int x)
{
	int i = cub->wall_bottom;
		while (i < SCR_H - 1)
		{
			my_mlx_pixel_put(&cub->img, x, i, 0x0033407F);
			i++;
		}
}

static	void	walls(t_cub *cub, int x)
{
	int	i = cub->wall_bottom;
	while (i > cub->wall_top)
	{
		my_mlx_pixel_put(&cub->img, x, i, 0x006680FF);
		i--;
	}
}

static	void	find_wall(t_cub *cub)
{
	cub->dy = cub->player_y * 2 + 16;
	cub->dx = cub->player_x * 2 + 16;
	if (cub->ra_angle > 2 * PI)
		cub->ra_angle -= 2 * PI;
	if (cub->ra_angle < 0)
		cub->ra_angle += 2 * PI;
	if (cub->ra_angle != 0 && cub->ra_angle != PI)
	{
		if (cub->ra_angle < PI)
			check_horizontal_up(cub, TRIDPIX);
		else if (cub->ra_angle > PI)
			check_horizontal_down(cub, TRIDPIX);
	}
	if (cub->ra_angle > P2 && cub->ra_angle < P3)
		check_vertical_left(cub, TRIDPIX);
	if (cub->ra_angle < P2 || cub->ra_angle > P3)
		check_vertical_right(cub, TRIDPIX);
	the_right_one(cub);
}

void	cub3d(t_cub *cub, double angle)
{
	int	i;

	i = -1;
	cub->render->ra_angle = convert_ang(angle);
	while (++i < SCR_W)
	{
		find_wall(cub->render);
		cub->slice_height = floor(32 / cub->render->ray_length * cub->render->projected_dist);
		cub->wall_bottom = floor(SCR_H/2 + cub->slice_height/2);
		cub->wall_top =  SCR_H - cub->wall_bottom;
		ceiling(cub, i);
		walls(cub, i);
		ground(cub, i);
		cub->render->ra_angle += 0.0010908;
	}
}
