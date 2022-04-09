/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:07:47 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/09 16:44:34 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	draw_minimap(t_cub *cub)
{
	t_data	img;
	int		i;
	int		j;
	int x = 0;
	int y = 0;
	

	img.img = mlx_new_image(cub->mlx, 1080, 1020);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	i = 0;
	putzero()
	while (y < 50)
	{
		x = 0;
		while (x < 50)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	
	mlx_put_image_to_window(cub->mlx, cub->win, img.img, 0, 0);
}



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x *(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
