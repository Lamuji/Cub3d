/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/23 00:56:17 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	ceiling(t_cub *cub, int x)
{
	int i = cub->wall_top;
	while (i >= 0)
	{
		my_mlx_pixel_put(&cub->img, x, i, rgb_to_hex(cub->rgbC[0], cub->rgbC[1], cub->rgbC[2]));
		i--;
	}
}

static	void	ground(t_cub *cub, int x)
{
	int i = cub->wall_bottom;
	while (i < SCR_H)
	{
		my_mlx_pixel_put(&cub->img, x, i, rgb_to_hex(cub->rgbF[0], cub->rgbF[1], cub->rgbF[2]));
		i++;
	}
}

static	void	walls(t_cub *cub, int x)
{
	int	i = cub->wall_bottom - 1;
	int	color;

	while (i >= cub->wall_top)
	{
		if (cub->render.type == 1)
		{
			if (cub->angle < 90 || cub->angle > 270)
			{
				if (cub->ra_angle < PI)
					my_mlx_pixel_put(&cub->img, x, i, cub->render.we_color[find_pixel(cub, i)]);
				else
					my_mlx_pixel_put(&cub->img, x, i, cub->render.ea_color[find_pixel(cub, i)]);
			}
		}
		else
		{
			if (cub->angle < 180 || cub->angle > 0)
				my_mlx_pixel_put(&cub->img, x, i, cub->render.no_color[find_pixel(cub, i)]);
			else
				my_mlx_pixel_put(&cub->img, x, i, cub->render.so_color[find_pixel(cub, i)]);
		}
		i--;
	}
}

static	void	find_wall(t_cub *cub)
{
	cub->dy = cub->player_y * 8 + 32;
	cub->dx = cub->player_x * 8 + 32;
	if (cub->ra_angle > 6.2831853)
		cub->ra_angle -= 6.2831853;
	if (cub->ra_angle < 0)
		cub->ra_angle += 6.2831853;
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
	int		i;
	double	beta;

	i = 0;
	cub->ra_angle = convert_ang(angle);
	while (i < SCR_W)
	{
		find_wall(cub);
		beta = fabs(convert_ang(cub->angle) - cub->ra_angle);
		cub->ray_length = cub->ray_length * cos(beta);
		cub->slice_height = floor(64 / cub->ray_length * cub->projected_dist);
		if (cub->slice_height > SCR_H)
			cub->slice_height = SCR_H;
		cub->wall_bottom = MID_H + cub->slice_height/2;
		if (cub->wall_bottom > SCR_H)
			cub->wall_bottom = SCR_H;
		cub->wall_top =  SCR_H - cub->wall_bottom;
		if (cub->wall_top < 0)
			cub->wall_top = 0;
		ceiling(cub, i);
		walls(cub, i);
		ground(cub, i);
		cub->ra_angle += 0.0010908;
		i++;
	}
}
