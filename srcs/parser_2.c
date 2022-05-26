/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:29 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/26 20:52:21 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	int	norm_color(char *str, int *rgb)
{
	int		i;
	int		j;
	char	**spl_color;

	i = -1;
	if (!check_virgule(str))
		return (0);
	spl_color = ft_split(((char *)str + 2), ',');
	manager(spl_color);
	if (ft_arrlen(spl_color) != 3)
		return (0);
	while (spl_color[++i])
	{
		j = 0;
		while (spl_color[i][j])
		{
			if (!ft_isdigit((int)spl_color[i][j]))
				return (0);
			j++;
		}
		rgb[i] = ft_atoi(((char *)spl_color[i]));
		if (rgb[i] > 255 || rgb[i] < 0)
			return (0);
	}
	return (1);
}

static	int	ft_reverse_ch_int(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find == NULL || str == NULL)
		return (0);
	while (to_find[j])
		j++;
	while (str[i])
		i++;
	while (j >= 0)
	{
		if (str[i] == to_find[j])
		{
			i--;
			j--;
		}
		else
			return (0);
	}
	return (1);
}

static	int	check_params(char *str, t_cub *cub)
{
	if (ft_ch_int(str, "NO ") || ft_ch_int(str, "SO ")
		|| ft_ch_int(str, "EA ") || ft_ch_int(str, "WE "))
	{
		if (ft_reverse_ch_int(str, ".xpm"))
		{
			path_to_text(cub, str, path(str));
			return (1);
		}
	}
	else if (ft_ch_int(str, "C "))
	{
		if (norm_color(str, cub->rgbc))
			return (1);
	}
	else if (ft_ch_int(str, "F "))
	{
		if (norm_color(str, cub->rgbf))
			return (1);
	}
	return (0);
}

void	check_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
			|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
				cub->count_pos++;
			j++;
		}
	i++;
	}
}

int	elem_nbr(t_cub *cub)
{
	int	i;

	i = -1;
	if (ft_arrlen(cub->elem) != 6)
		ft_putendl_exit("Wrong nb of elements", STDERR_FILENO);
	while (cub->elem[++i])
	{
		if (!check_params(cub->elem[i], cub))
			return (0);
	}
	return (1);
}
