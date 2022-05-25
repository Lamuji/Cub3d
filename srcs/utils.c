/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:25:18 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/25 14:31:49 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	fill_tabs(t_cub *cub, int i, int j, char **tab)
{
	while (++i < 6)
	{
		cub->elem[i] = ft_strdup(tab[i]);
		manager(cub->elem[i]);
	}
	j = 0;
	cub->widthsquare = ft_arrlenmax(&tab[i]);
	while (tab[i])
	{
		cub->map[j] = ft_strdupmap(tab[i], cub->widthsquare);
		manager(cub->map[j]);
		i++;
		j++;
	}
}

void	init_value(t_cub *cub)
{
	cub->dx = 0;
	cub->dy = 0;
	cub->fov_lenght = 0;
	cub->fx = 0;
	cub->fy = 0;
	cub->hx = 0;
	cub->hy = 0;
	cub->pix_x = 0;
	cub->pix_y = 0;
	cub->player_x = 0;
	cub->player_y = 0;
	cub->vx = 0;
	cub->vy = 0;
	cub->slice_height = 0;
	cub->wall_bottom = 0;
	cub->wall_top = 0;
	cub->r.index = 0;
	cub->r.tx = 0;
	cub->r.ty = 0;
}

unsigned	long	rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw(t_cub *cub, double x, double y)
{
	double	xinc;
	double	yinc;
	int		i;

	xinc = 0;
	yinc = 0;
	i = 0;
	if (fabs(x - cub->dx) >= fabs(y - cub->dy))
		cub->step = fabs(x - cub->dx);
	else
		cub->step = fabs(y - cub->dy);
	xinc = (x - cub->dx) / cub->step;
	yinc = (y - cub->dy) / cub->step;
	while (i <= cub->step)
	{
		my_mlx_pixel_put(&cub->img2, cub->dx, cub->dy, 0x000000FF);
		cub->dx += xinc;
		cub->dy += yinc;
		i++;
	}
}

void	vision(t_cub *cub, double angle)
{
	cub->dy = cub->player_y + 4;
	cub->dx = cub->player_x + 4;
	cub->ra_angle = convert_ang(angle);
	if (cub->ra_angle > 6.2831853)
		cub->ra_angle -= 6.2831853;
	if (cub->ra_angle < 0)
		cub->ra_angle += 6.2831853;
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
