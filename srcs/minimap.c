/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:47 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/20 09:06:01 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

// int	find_walls(t_cub *cub)
// {
// 	double Py;
// 	double Px;
// 	while (cub->map[Py][Px] != '1')
// 	double Xa = 32/tan(cub->angle);
// 	double Ya = 32;
// 	double Py = floor(cub->player_y/32) * 32 - 1;
// 	double Px = (cub->player_x + (cub->player_y - Py)/tan(cub->angle));
// 	printf("%f\n%f\n%c\n", Py/32, floor(Px/32), cub->map[12][26]);
// }

void	draw_player(t_cub *cub)
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	int i;

	start_x = (int)cub->player_x - (32 / 10);
	start_y = (int)cub->player_y - (32 / 10);
	end_x = (int)cub->player_x  + (32 / 10);
	end_y = (int)cub->player_y  + (32 / 10);
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
