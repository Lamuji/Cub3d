/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:47 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/24 20:25:42 by rfkaier          ###   ########.fr       */
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
				cub->player_x = (double)j * 8.0;
				cub->player_y = (double)i * 8.0;
				cub->minimap.plmapx = j * 8;
				cub->minimap.plmapy = i * 8;
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

	start_x = cub->player_x + 3;
	start_y = cub->player_y + 3;
	end_x = cub->player_x + 8 - 3;
	end_y = cub->player_y + 8 - 3;
	while (start_y <= end_y)
	{
		i = start_x;
		while (i <= end_x)
		{
			my_mlx_pixel_put(&cub->img2, i, start_y, 0x50728840);
			i++;
		}
		start_y++;
	}
}

static	void	putminimap(t_data *data, int x, int y, int color)
{
	int tx;
	int ty = y;
	while (ty < y + 8)
	{
		tx = x;
		while (tx < x + 8)
		{
			if (tx == x || ty == y)
				my_mlx_pixel_put(data, tx, ty, 0x509999FF);
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

	cub->pix_y = 0;
	i = 0;
	while (cub->map[i])
	{
	 	j = 0;
		cub->pix_x = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1' || cub->map[i][j] == '*')
				putminimap(&cub->img2, cub->pix_x, cub->pix_y, 0x70ACACAC);
			if (cub->map[i][j] != '1' && cub->map[i][j] != '*')
				putminimap(&cub->img2, cub->pix_x, cub->pix_y, 0x70FFFFFF);
			cub->pix_x += 8;
			j++;
		}
		cub->pix_y += 8;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
