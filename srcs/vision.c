/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/26 16:15:23 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

double convert_ang(double angle)
{
	return (angle * (3.14159 / 180));
}

// void	define_starting_dydx(t_cub *cub)
// {
// 	if (cub->start_angle == NORTH)
// 	{
// 		cub->set_x = cos(convert_ang(cub->angle)) * -16;
// 		cub->set_y = sin(convert_ang(cub->angle)) * -16;
// 	}
// 	else if (cub->start_angle == SOUTH)
// 	{
// 		cub->set_x = cos(convert_ang(cub->angle)) * -16;
// 		cub->set_y = sin(convert_ang(cub->angle)) * -16;
// 	}
// 	else if (cub->start_angle == EAST)
// 	{
// 		cub->set_x = cos(convert_ang(cub->angle)) * 16;
// 		cub->set_y = sin(convert_ang(cub->angle)) * 16;
// 	}
// 	else if (cub->start_angle == WEST)
// 	{
// 		cub->set_x = cos(convert_ang(cub->angle)) * 16;
// 		cub->set_y = sin(convert_ang(cub->angle)) * 16;
// 	}
// }

void	draw(t_cub *cub, double x, double y)
{
	double xinc = 0;
	double yinc = 0;
	int i = 1;
	if (fabs(x - cub->player_x) >= fabs(y - cub->player_y))
		cub->step = fabs(x - cub->player_x);
	else
		cub->step = fabs(y - cub->player_y);
	xinc = (x - cub->player_x) / cub->step;
	yinc = (y - cub->player_y) / cub->step;
	while (i <= cub->step)
	{
		my_mlx_pixel_put(&cub->img, cub->player_x, cub->player_y, 0x000000FF);
		cub->player_x += xinc;
		cub->player_y += yinc;
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
}

// void	dda_algo(t_cub *cub)
// {
// 	double xinc = 0;
// 	double yinc = 0;
// 	int i = 1;
// 	if (fabs(cub->set_x) >= fabs(cub->set_y))
// 		cub->step = fabs(cub->set_x);
// 	else
// 		cub->step = fabs(cub->set_y);
// 	xinc = (double)cub->set_x / cub->step;
// 	yinc = (double)cub->set_y / cub->step;
// 	while (i <= cub->step)
// 	{
// 		my_mlx_pixel_put(&cub->img, cub->player_x, cub->player_y, 0x000000FF);
// 		cub->player_x += xinc;
// 		cub->player_y += yinc;
// 		i++;
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
// }

void	vision(t_cub *cub)
{
	cub->player_x += 16;
	cub->player_y += 16;
	find_walls(cub);
}