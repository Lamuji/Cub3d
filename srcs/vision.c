/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/19 04:38:20 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	double convert_ang(double angle)
{
	return (angle * (180 / 3.14159));
}

static	void	dda_algo(t_cub *cub, double x, double y)
{
	double xinc = 0;
	double yinc = 0;
	int i = 1;
	if (fabs(cub->dx) >= fabs(cub->dy))
		cub->step = fabs(cub->dx);
	else
		cub->step = fabs(cub->dy);
	xinc = (double)cub->dx / cub->step;
	yinc = (double)cub->dy / cub->step;
	while (i <= cub->step)
	{
		my_mlx_pixel_put(&cub->img, x, y, 0x000000FF);
		x = x + xinc;
		y = y + yinc;
		i++;
	}
}

void	vision(t_cub *cub)
{
	double x = cub->player_x;
	double y = cub->player_y;
	define_starting_dydx(cub);
	dda_algo(cub, x, y);
}