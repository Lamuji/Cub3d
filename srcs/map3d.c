/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/04 15:09:06 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	ceiling(t_cub *cub, int x, double j)
{
	double i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img2, x, (int)j, 0x00D1D8FF);
		i++;
	}
}

static	void	ground(t_cub *cub, int x, double j)
{
	double i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img2, x, (int)j, 0x0033407F);
		i++;
	}
}

void	walls(t_cub *cub, int x, double j)
{
	double i;

	i = 0;
	while (i < j)
	{
		my_mlx_pixel_put(&cub->img2, x, (int)j, 0x006680FF);
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
	int i = -1;
	double j;
	double wall_bottom;
	double wall_top;
	double slice_height;
//	double *ray_lenght;

	cub->render->ra_angle = convert_ang(angle);
	printf("debut==============\n");
	while (++i < SCR_W)
	{
		find_wall(cub->render);
		//ub->render->ray_length =   
		slice_height = floor(32 / cub->render->ray_length * cub->render->projected_dist);
		wall_bottom = floor(400.00 + slice_height/2);
		wall_top =  SCR_H - wall_bottom;
		j = -1;
		while (++j < SCR_H)
		{
			if (j < wall_top)
				ceiling(cub, i, j);
			else if (j >= wall_top && j <= wall_bottom)
				walls(cub, i, j);
			else if (j > wall_bottom)
				ground(cub, i, j);
		}
		cub->render->ra_angle += 0.0010908;
	}
}

// distance from player to project plane = 640/tan(30); angle incrementation 60/1080 = 0.05555 