/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/27 20:18:04 by ramzi            ###   ########.fr       */
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
	}
	else if (h > v)
	{
		cub->fx = cub->Vx;
		cub->fy = cub->Vy;
	}
}

void	check_vertical_right(t_cub *cub)
{
	double Ya;
	double Xa;

	Xa = -32;
	cub->Vx = floor(cub->dy/32) * 32 - 0.000001;
	cub->Vy = (cub->dx - cub->Vx) * (-tan(cub->ra_angle)) + cub->dy;
	Ya = -Xa * (-tan(cub->ra_angle));
	while ((((int)cub->Vy/32) > 0 && ((int)cub->Vy/32) < cub->height
		&& ((int)cub->Vx/32) > 0 && ((int)cub->Vx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Vy/32][(int)cub->Vx/32] != '1')
	{
		cub->Vx += Xa;
		cub->Vy += Ya;
	}
}

void	check_vertical_left(t_cub *cub)
{
	double Ya;
	double Xa;

	Xa = 32;
	cub->Vx = floor((int)cub->dx/32) * 32 + 32;
	cub->Vy = (cub->dx - cub->Vx) * (-tan(cub->ra_angle)) + cub->dy;
	Ya = -Xa * (-tan(cub->ra_angle));
	while ((((int)cub->Vy/32) > 0 && ((int)cub->Vy/32) < cub->height
		&& ((int)cub->Vx/32) > 0 && ((int)cub->Vx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Vy/32][(int)cub->Vx/32] != '1')
	{
		cub->Vx += Xa;
		cub->Vy += Ya;
	}
}

void	check_horizontal_down(t_cub *cub)
{
	double Ya;
	double Xa;

	Ya = 32;
	cub->Hy = floor(cub->dy/32) * 32 + 32;
	cub->Hx = (cub->dy - cub->Hy) * (-1 /tan(cub->ra_angle)) + cub->dx;
	Xa = -Ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->Hy/32) > 0 && ((int)cub->Hy/32) < cub->height)
		&& (((int)cub->Hx/32) > 0 && ((int)cub->Hx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Hy/32][(int)cub->Hx/32] != '1')
	{
		cub->Hx += Xa;
		cub->Hy += Ya;
	}
}

void	check_horizontal_up(t_cub *cub)
{
	double Ya;
	double Xa;


	Ya = -32;
	cub->Hy = floor((int)cub->dy/32) * 32 - 0.000001;
	cub->Hx = (cub->dy - cub->Hy) * (-1 /tan(cub->ra_angle)) + cub->dx;
	Xa = -Ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->Hy/32) > 0 && ((int)cub->Hy/32) < cub->height)
		&& (((int)cub->Hx/32) > 0 && ((int)cub->Hx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Hy/32][(int)cub->Hx/32] != '1')
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
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}

void	vision(t_cub *cub)
{
		cub->dy = cub->player_y + 16;
		cub->dx = cub->player_x + 16;
		cub->ra_angle = convert_ang(cub->angle);
		if (cub->ra_angle != 0 && cub->ra_angle != PI)
		{
			if (cub->ra_angle < PI)
				check_horizontal_up(cub);
			else if (cub->ra_angle > PI)
				check_horizontal_down(cub);
		}
		if (cub->ra_angle > P2 && cub->ra_angle < P3)
			check_vertical_left(cub);
		if (cub->ra_angle < P2 || cub->ra_angle > P3)
			check_vertical_right(cub);
		the_right_one(cub);
		draw(cub, cub->fx, cub->fy);
}