/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:28:59 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/25 14:20:51 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	void	east_west(t_cub *cub, char *str, char *path)
{
	if (ft_ch_int(str, "WE"))
	{
		cub->r.we = mlx_xpm_file_to_image(cub->mlx, path,
				&cub->r.width, &cub->r.height);
		cub->r.we_color = (int *)mlx_get_data_addr
			(cub->r.we, &cub->r.a, &cub->r.b, &cub->r.c);
	}
	else if (ft_ch_int(str, "EA"))
	{
		cub->r.ea = mlx_xpm_file_to_image(cub->mlx, path,
				&cub->r.width, &cub->r.height);
		cub->r.ea_color = (int *)mlx_get_data_addr
			(cub->r.ea, &cub->r.a, &cub->r.b, &cub->r.c);
	}
}

void	path_to_text(t_cub *cub, char *str, char *path)
{
	if (ft_ch_int(str, "NO"))
	{
		cub->r.no = mlx_xpm_file_to_image(cub->mlx, path,
				&cub->r.width, &cub->r.height);
		cub->r.no_color = (int *)mlx_get_data_addr
			(cub->r.no, &cub->r.a, &cub->r.b, &cub->r.c);
	}
	else if (ft_ch_int(str, "SO"))
	{
		cub->r.so = mlx_xpm_file_to_image(cub->mlx, path,
				&cub->r.width, &cub->r.height);
		cub->r.so_color = (int *)mlx_get_data_addr
			(cub->r.so, &cub->r.a, &cub->r.b, &cub->r.c);
	}
	east_west(cub, str, path);
}

int	find_pixel(t_cub *cub, int i)
{
	int	color;

	color = 0;
	if (cub->r.type == 1)
		cub->r.tx = fmod(cub->fx / 64.0, 1.0) * 200.0;
	else if (cub->r.type == 2)
		cub->r.tx = fmod(cub->fy / 64.0, 1.0) * 200.0;
	cub->r.ty = (1.0 - ((320.0 + cub->slice_height) - i)
			/ (cub->slice_height * 2.0)) * 200.0;
	cub->r.index = cub->r.tx + (cub->r.ty * 200.0);
	color = cub->r.index;
	return (color);
}
