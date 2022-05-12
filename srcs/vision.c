/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/06 16:31:04 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	the_right_one(t_cub *cub)
{
	double	h;
	double	v;

	h = sqrt(pow(cub->dx - cub->Hx, 2)
		+ pow(cub->dy - cub->Hy, 2));
	v = sqrt(pow(cub->dx - cub->Vx, 2)
		+ pow(cub->dy - cub->Vy, 2));
	if (h < v)
	{
		cub->fx = cub->Hx;
		cub->fy = cub->Hy;
		cub->ray_length = h;
		cub->render.color_h = 0x006680FF;
	}
	else if (h > v)
	{
		cub->fx = cub->Vx;
		cub->fy = cub->Vy;
		cub->ray_length = v;
		cub->render.color_h = 0x008095FF;
	}
}

void	check_vertical_right(t_cub *cub, int size)
{
	double Ya;
	double Xa;

	Xa = -size;
	cub->Vx = floor(cub->dx/size) * size - 0.000001;
	cub->Vy = (cub->dx - cub->Vx) * (-tan(cub->ra_angle)) + cub->dy;
	Ya = -Xa * (-tan(cub->ra_angle));
	while ((((int)cub->Vy/size) > 0 && ((int)cub->Vy/size) < cub->height
		&& ((int)cub->Vx/size) > 0 && ((int)cub->Vx/size) < cub->widthsquare)
		&& cub->map[(int)cub->Vy/size][(int)cub->Vx/size] != '1')
	{
		cub->Vx += Xa;
		cub->Vy += Ya;
	}
}

void	check_vertical_left(t_cub *cub, int size)
{
	double Ya;
	double Xa;

	Xa = size;
	cub->Vx = floor((int)cub->dx/size) * size + size;
	cub->Vy = (cub->dx - cub->Vx) * (-tan(cub->ra_angle)) + cub->dy;
	Ya = -Xa * (-tan(cub->ra_angle));
	while ((((int)cub->Vy/size) > 0 && ((int)cub->Vy/size) < cub->height
		&& ((int)cub->Vx/size) > 0 && ((int)cub->Vx/size) < cub->widthsquare)
		&& cub->map[(int)cub->Vy/size][(int)cub->Vx/size] != '1')
	{
		cub->Vx += Xa;
		cub->Vy += Ya;
	}
}

void	check_horizontal_down(t_cub *cub, int size)
{
	double Ya;
	double Xa;

	Ya = size;
	cub->Hy = floor(cub->dy/size) * size + size;
	cub->Hx = (cub->dy - cub->Hy) * (-1 /tan(cub->ra_angle)) + cub->dx;
	Xa = -Ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->Hy/size) > 0 && ((int)cub->Hy/size) < cub->height)
		&& (((int)cub->Hx/size) > 0 && ((int)cub->Hx/size) < cub->widthsquare)
		&& cub->map[(int)cub->Hy/size][(int)cub->Hx/size] != '1')
	{
		cub->Hx += Xa;
		cub->Hy += Ya;
	}
}

void	check_horizontal_up(t_cub *cub, int size)
{
	double Ya;
	double Xa;


	Ya = -size;
	cub->Hy = floor((int)cub->dy/size) * size - 0.000001;
	cub->Hx = (cub->dy - cub->Hy) * (-1 /tan(cub->ra_angle)) + cub->dx;
	Xa = -Ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->Hy/size) > 0 && ((int)cub->Hy/size) < cub->height)
		&& (((int)cub->Hx/size) > 0 && ((int)cub->Hx/size) < cub->widthsquare)
		&& cub->map[(int)cub->Hy/size][(int)cub->Hx/size] != '1')
	{
		cub->Hx += Xa;
		cub->Hy += Ya;
	}
}

void	draw(t_cub *cub, double x, double y)
{
	double xinc = 0;
	double yinc = 0;
	int i = 1;
	if (fabs(x - cub->dx) >= fabs(y - cub->dy))
		cub->step = fabs(x - cub->dx);
	else
		cub->step = fabs(y - cub->dy);
	xinc = (x - cub->dx) / cub->step;
	yinc = (y - cub->dy) / cub->step;
	while (i <= cub->step)
	{
		my_mlx_pixel_put(&cub->img, cub->dx, cub->dy, 0x000000FF);
		cub->dx += xinc;
		cub->dy += yinc;
		i++;
	}
}

void	vision(t_cub *cub, double angle)
{
	cub->dy = cub->player_y + 8;
	cub->dx = cub->player_x + 8;
	cub->ra_angle = convert_ang(angle);
	if (cub->ra_angle > 2 * PI)
		cub->ra_angle -= 2 * PI;
	if (cub->ra_angle < 0)
		cub->ra_angle += 2 * PI;
	if (cub->ra_angle != 0 && cub->ra_angle != PI)
	{
		if (cub->ra_angle < PI)
			check_horizontal_up(cub, MINIPIX);
		if (cub->ra_angle > PI)
			check_horizontal_down(cub, MINIPIX);
	}
	if (cub->ra_angle > P2 && cub->ra_angle < P3)
		check_vertical_left(cub, MINIPIX);
	if (cub->ra_angle < P2 || cub->ra_angle > P3)
		check_vertical_right(cub, MINIPIX);
	the_right_one(cub);
	draw(cub, cub->fx, cub->fy);
}