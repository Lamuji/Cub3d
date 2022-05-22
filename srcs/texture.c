/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:28:59 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/21 23:51:53 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	path_to_text(t_cub *cub, char *str, char *path)
{
	int	width;
	int	height;
	int a, b, c;

	if (ft_ch_int(str, "NO")){
		cub->render.no = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
		cub->render.color = (int*)mlx_get_data_addr(cub->render.no, &a, &b, &c);}
	else if (ft_ch_int(str, "SO")){
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	//	cub->render.color = (int*)mlx_get_data_addr(cub->render.so, &a, &b, &c);
	}
	else if (ft_ch_int(str, "WE")){
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
		//cub->render.color = (int*)mlx_get_data_addr(cub->render.we, &a, &b, &c);
		}
	else if (ft_ch_int(str, "EA")){
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
		//cub->render.color = (int*)mlx_get_data_addr(cub->render.ea, &a, &b, &c);
		}
}

int	find_pixel(t_cub *cub, int i)
{
	int	color;

	color = 0;
	if (cub->render.type == 1)
		cub->render.tx = fmod(cub->fy / cub->slice_height, 1.0) * 64.0;
	else if (cub->render.type == 2)
		cub->render.tx = fmod(cub->fx / cub->slice_height, 1.0) * 64.0;
	cub->render.ty = (1.0 - (cub->wall_bottom - i) / cub->slice_height) * 64.0;
	cub->render.index = (int)(cub->render.tx + (cub->render.ty * 64.0));
	color = cub->render.color[cub->render.index];
	return (color);
}

