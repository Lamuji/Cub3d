/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:47 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/26 17:29:01 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static void	the_right_one(t_cub *cub)
{
	double	h;
	double	v;

	h = sqrt(pow(cub->player_x - cub->Hx, 2)
		+ pow(cub->player_y - cub->Hy, 2));
	v = sqrt(pow(cub->player_x - cub->Vx, 2)
		+ pow(cub->player_y - cub->Vy, 2));
	if (h < v)
	{
		cub->fx = cub->Hx;
		cub->fy = cub->Hy;
	}
	else
	{
		cub->fx = cub->Vx;
		cub->fy = cub->Vy;
	}
}

static	void	check_vertical(t_cub *cub)
{
	double Ya;
	double Xa;

	if (convert_ang(cub->angle) > P2 && convert_ang(cub->angle) < P3)
	{
		Xa = 32;
		cub->Vx = floor((int)cub->player_x/32) * 32 + 32;
		cub->Vy = (cub->player_x - cub->Vx) * (-tan(convert_ang(cub->angle))) + cub->player_y;
		Ya = -Xa * (-tan(convert_ang(cub->angle)));
	}
	else if (convert_ang(cub->angle) < P2 || convert_ang(cub->angle) > P3)
	{
		Xa = -32;
		cub->Vx = floor(cub->player_y/32) * 32 - 0.0001;
		cub->Vy = (cub->player_x - cub->Vx) * (-tan(convert_ang(cub->angle))) + cub->player_y;
		Ya = -Xa * (-tan(convert_ang(cub->angle)));
	}
	else if (convert_ang(cub->angle) == 0 || convert_ang(cub->angle) == PI)
	{
		cub->Vx = cub->player_x;
		cub->Vy = cub->player_y;
	}
	while ((((int)cub->Vy/32) > 0 && ((int)cub->Vy/32) < cub->height
		&& ((int)cub->Vx/32) > 0 && ((int)cub->Vx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Vy/32][(int)cub->Vx/32] == '0')
	{
		cub->Vx += Xa;
		cub->Vy += Ya;
	}
}

static	void	check_horizontal(t_cub *cub)
{
	double Ya;
	double Xa;

	if (convert_ang(cub->angle) < PI)
	{
		Ya = -32;
		cub->Hy = floor((int)cub->player_y/32) * 32 - 0.0001;
		cub->Hx = (cub->player_y - cub->Hy) * (-1 /tan(convert_ang(cub->angle))) + cub->player_x;
		Xa = -Ya * (-1 / tan(convert_ang(cub->angle)));
	}
	else if (convert_ang(cub->angle) > PI)
	{
		Ya = 32;
		cub->Hy = floor(cub->player_y/32) * 32 + 32;
		cub->Hx = (cub->player_y - cub->Hy) * (-1 /tan(convert_ang(cub->angle))) + cub->player_x;
		Xa = -Ya * (-1 / tan(convert_ang(cub->angle)));
	}
	else if (convert_ang(cub->angle) == 0 || convert_ang(cub->angle) == PI)
	{
		cub->Hx = cub->player_x;
		cub->Hy = cub->player_y;
	}
	while ((((int)cub->Hy/32) > 0 && ((int)cub->Hy/32) < cub->height)
		&& (((int)cub->Hx/32) > 0 && ((int)cub->Hx/32) < cub->widthsquare)
		&& cub->map[(int)cub->Hy/32][(int)cub->Hx/32] == '0')
	{
		cub->Hx += Xa;
		cub->Hy += Ya;
	}
}

int	find_walls(t_cub *cub)
{
	check_horizontal(cub);
	check_vertical(cub);
	the_right_one(cub);
	draw(cub, cub->fx, cub->fy);
}

void	draw_player(t_cub *cub)
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int i;

	start_x = cub->player_x + 12;
	start_y = cub->player_y + 12;
	end_x = cub->player_x + 32 - 12;
	end_y = cub->player_y + 32 - 12;
	while (start_y <= end_y)
	{
		i = start_x;
		while (i <= end_x)
		{
			my_mlx_pixel_put(&cub->img, i, start_y, 0x00728840);
			i++;
		}
		start_y++;
	}
}

static	void	putminimap(t_data *data, int x, int y, int color)
{
	int tx;
	int ty = y;
	while (ty < y + 32)
	{
		tx = x;
		while (tx < x + 32)
		{
			if (tx == x || ty == y)
				my_mlx_pixel_put(data, tx, ty, 0x009999FF);
			else
				my_mlx_pixel_put(data, tx, ty, color);
			tx++;
		}
		ty++;
	}
}

void	draw_minimap(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		cub->pix_x = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				putminimap(&cub->img, cub->pix_x, cub->pix_y, 0x00ACACAC);
			if (cub->map[i][j] != '1' && cub->map[i][j] != '*')
				putminimap(&cub->img, cub->pix_x, cub->pix_y, 0x00FFFFFF);
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player_x = cub->pix_x;
				cub->player_y = cub->pix_y;
			}
			cub->pix_x += 32;
			j++;
		}
		cub->pix_y += 32;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
