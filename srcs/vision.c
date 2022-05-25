/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/25 14:32:08 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	the_right_one(t_cub *cub)
{
	double	h;
	double	v;

	h = sqrt(pow(cub->dx - cub->hx, 2)
			+ pow(cub->dy - cub->hy, 2));
	v = sqrt(pow(cub->dx - cub->vx, 2)
			+ pow(cub->dy - cub->vy, 2));
	if (h <= v)
	{
		cub->r.type = 1;
		cub->fx = cub->hx;
		cub->fy = cub->hy;
		cub->ray_length = h;
	}
	else
	{
		cub->r.type = 2;
		cub->fx = cub->vx;
		cub->fy = cub->vy;
		cub->ray_length = v;
	}
}

void	check_vertical_right(t_cub *cub, int size)
{
	double	ya;
	double	xa;

	xa = -size;
	cub->vx = floor(cub->dx / size) * size - 0.000001;
	cub->vy = (cub->dx - cub->vx) * (-tan(cub->ra_angle)) + cub->dy;
	ya = -xa * (-tan(cub->ra_angle));
	while ((((int)cub->vy / size) > 0 && ((int)cub->vy / size) < cub->height
			&& ((int)cub->vx / size) > 0
			&& ((int)cub->vx / size) < cub->widthsquare)
		&& cub->map[(int)cub->vy / size][(int)cub->vx / size] != '1')
	{
		cub->vx += xa;
		cub->vy += ya;
	}
}

void	check_vertical_left(t_cub *cub, int size)
{
	double	ya;
	double	xa;

	xa = size;
	cub->vx = floor((int)cub->dx / size) * size + size;
	cub->vy = (cub->dx - cub->vx) * (-tan(cub->ra_angle)) + cub->dy;
	ya = -xa * (-tan(cub->ra_angle));
	while ((((int)cub->vy / size) > 0 && ((int)cub->vy / size) < cub->height
			&& ((int)cub->vx / size) > 0
			&& ((int)cub->vx / size) < cub->widthsquare)
		&& cub->map[(int)cub->vy / size][(int)cub->vx / size] != '1')
	{
		cub->vx += xa;
		cub->vy += ya;
	}
}

void	check_horizontal_down(t_cub *cub, int size)
{
	double	ya;
	double	xa;

	ya = size;
	cub->hy = floor(cub->dy / size) * size + size;
	cub->hx = (cub->dy - cub->hy) * (-1 / tan(cub->ra_angle)) + cub->dx;
	xa = -ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->hy / size) > 0 && ((int)cub->hy / size) < cub->height)
		&& (((int)cub->hx / size) > 0
			&& ((int)cub->hx / size) < cub->widthsquare)
		&& cub->map[(int)cub->hy / size][(int)cub->hx / size] != '1')
	{
		cub->hx += xa;
		cub->hy += ya;
	}
}

void	check_horizontal_up(t_cub *cub, int size)
{
	double	ya;
	double	xa;

	ya = -size;
	cub->hy = floor((int)cub->dy / size) * size - 0.000001;
	cub->hx = (cub->dy - cub->hy) * (-1 / tan(cub->ra_angle)) + cub->dx;
	xa = -ya * (-1 / tan(cub->ra_angle));
	while ((((int)cub->hy / size) > 0 && ((int)cub->hy / size) < cub->height)
		&& (((int)cub->hx / size) > 0
			&& ((int)cub->hx / size) < cub->widthsquare)
		&& cub->map[(int)cub->hy / size][(int)cub->hx / size] != '1')
	{
		cub->hx += xa;
		cub->hy += ya;
	}
}
