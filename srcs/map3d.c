/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/05 10:08:36 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	ceiling(t_cub *cub, int x)
{
	int i = cub->wall_top;
		while (i >= 0)
		{
			my_mlx_pixel_put(&cub->img, x, i, 0x00D1D8FF);
			i--;
		}
}

static	void	ground(t_cub *cub, int x)
{
	int i = cub->wall_bottom;
		while (i < SCR_H)
		{
			my_mlx_pixel_put(&cub->img, x, i, 0x0033407F);
			i++;
		}
}

static	void	walls(t_cub *cub, int x)
{
	int	i = cub->wall_bottom - 1;
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
	double incr = 0.0010908;
	double	saved_lenght;
	double	corrected;
	double	beta;
	i = -1;
	//cub->ra_angle = convert_ang(cub->angle);
	//find_wall(cub);
	cub->ra_angle = convert_ang(angle);
	while (++i < SCR_W)
	{
		find_wall(cub);
		beta = fabs(convert_ang(cub->angle) - cub->ra_angle);
		cub->ray_length = cub->ray_length * cos(beta);
		cub->slice_height = floor(32 / cub->ray_length * cub->projected_dist);
		if (cub->slice_height > SCR_H)
			cub->slice_height = SCR_H;
		cub->wall_bottom = floor(SCR_H/2 + cub->slice_height/2);
		if (cub->wall_bottom > SCR_H)
			cub->wall_bottom = SCR_H;
		cub->wall_top =  SCR_H - cub->wall_bottom;
		if (cub->wall_top < 0)
			cub->wall_top = 0;
		ceiling(cub, i);
		walls(cub, i);
		ground(cub, i);
		cub->ra_angle += 0.0010908;
		saved_lenght += 0.0010908;
		//incr +=;
	}
}
