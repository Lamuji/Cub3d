/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/18 01:24:32 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	double convert_ang(double angle)
{
	return (angle * (180 / 3.14159));
}

static	void	dda_algo(t_cub *cub)
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
		my_mlx_pixel_put(&cub->img, cub->player_x, cub->player_y, 0x000000FF);
		cub->player_x = cub->player_x + xinc;
		cub->player_y = cub->player_y + yinc;
		i++;
	}
}

void	vision(t_cub *cub)
{
	printf("%f\n", cub->angle);
	define_starting_dydx(cub);
	dda_algo(cub);
}

int	define_tan(t_cub *cub)
{
	double Ya = 32;
	double Xa = cub->player_x;
}