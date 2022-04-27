/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:47 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/27 09:09:18 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	player_pos(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
			|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player_x = j * 32;
				cub->player_y = i * 32;
			}
			j++;
		}
		i++;
	}
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

	cub->pix_x = 0;
	cub->pix_y = 0;
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
