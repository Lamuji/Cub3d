/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:28:59 by ramzi             #+#    #+#             */
/*   Updated: 2022/05/17 16:59:58 by rfkaier          ###   ########.fr       */
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
		cub->render.color_v = (int*)mlx_get_data_addr(cub->render.no, &a, &b, &c);}
	else if (ft_ch_int(str, "SO"))
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	else if (ft_ch_int(str, "WE"))
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	else if (ft_ch_int(str, "EA"))
		cub->render.so = mlx_xpm_file_to_image(cub->mlx, path, &width, &height);
	printf("%d\n", cub->render.color_v[0]);
}
