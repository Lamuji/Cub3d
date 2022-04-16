/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/16 04:35:51 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	dda_algo(t_cub *cub)
{
	double xinc = 0;
	double yinc = 0;
	double x;
	double y;
	double step;
	int i = 1;
	if (fabs(cub->dx - cub->player_x) >= fabs(cub->dy - cub->player_y))
		step = (cub->dx - cub->player_x);
	else
		step = (cub->dy - cub->player_y);
	xinc = floor(cub->dx - cub->player_x) / step;
	yinc = floor(cub->dy - cub->player_y) / step;
	x = cub->player_x;
	y = cub->player_y;
	while (i <= step)
	{
		my_mlx_pixel_put(&cub->img, floor(x), floor(y), 0x000000FF);
		x = x + xinc;
		y = y + yinc;
		printf("%f-%f\n", x, y);
		i++;
	}
}

void	vision(t_cub *cub)
{
	cub->angle = 0;
	which_direction(cub);
	printf("%f\n", cub->angle);
	define_starting_dydx(cub);
	dda_algo(cub);
}

int	define_tan(t_cub *cub)
{
	double Ya = 32;
	double Xa = cub->player_x;
}