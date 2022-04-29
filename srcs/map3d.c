/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:12:30 by ramzi             #+#    #+#             */
/*   Updated: 2022/04/29 05:48:26 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	cub3d(t_cub *cub, double angle)
{
	int i;
	int j = 0;
	// double	beta = cub->angle - 30;
	// double corr_dist = 

	double slice_height = cub->projected_dist * (cub->ray_length) * 4;
	i = SCR_H - slice_height;
	int begin = 100 - slice_height /2;
	int end = 100 + slice_height/2;
	while (j < SCR_W)
	{
		begin = 100 - slice_height/2;
		while (begin < end)
		{
			printf("%d\n%f\n", i, slice_height );
			my_mlx_pixel_put(&cub->img, j, begin, 0x00FF0000);
			begin++;
		}
		j++;
	}
}


// distance from player to project plane = 640/tan(30);