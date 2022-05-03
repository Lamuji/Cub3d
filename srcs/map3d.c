/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/03 12:17:45 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	ceiling(t_cub *cub, int x, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img, x, j, 0x000E05FF);
		i++;
	}
}

static	void	ground(t_cub *cub, int x, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img, x, j, 0x0033407F);
		i++;
	}
}

static	void	walls(t_cub *cub, int x, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img, x, j, 0x006680FF);
		i++;
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
	int i = 0;
	int j;
	double wall_bottom;
	double wall_top;
	double slice_height;

	//printf("%f-%f\n", cub->player_x, cub->player_y);
	cub->ra_angle = convert_ang(angle);
	while (i < SCR_W)
	{
		find_wall(cub);
		slice_height = floor(32 / cub->ray_length * (590/tan(convert_ang(30))));
		wall_bottom = 460 + slice_height/2;
		wall_top =  460 - slice_height/2;
		j = 0;
		while (j < SCR_H)
		{
			if (j < wall_top)
				ceiling(cub, i, j);
			if (j >= wall_top && j <= wall_bottom)
				walls(cub, i, j);
			if (j > wall_bottom)
				ground(cub, i, j);
			j++;
		}
		cub->ra_angle += convert_ang(0.055555);
	 	i++;
	}
}

// distance from player to project plane = 640/tan(30); angle incrementation 60/1080 = 0.05555 