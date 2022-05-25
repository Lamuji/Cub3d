/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:30:17 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/25 13:47:46 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static	int	mago_kun(char **str, int i, int j)
{
	if (str[0][j] != '1' && str[0][j] != '*')
		return (0);
	if (str[i + 1] == NULL || str[i][j + 1] == '\0')
	{
		if (str[i][j] != '1' && str[i][j] != '*')
			return (0);
	}
	if (!str[i][j + 1])
	{
		if (str[i][j] != '1' && str[i][j] != '*')
			return (0);
	}
	if (str[i][j] == '*')
	{
		if (!schr(CLOSE, str[i][j - 1]))
			return (0);
	}
	return (1);
}

void	which_direction(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N')
				cub->angle = NORTH;
			if (cub->map[i][j] == 'S')
				cub->angle = SOUTH;
			if (cub->map[i][j] == 'E')
				cub->angle = EAST;
			if (cub->map[i][j] == 'W')
				cub->angle = WEST;
			j++;
		}
		i++;
	}
}

int	check_closed(char **str, int width)
{
	int	i;
	int	j;

	(void)width;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!mago_kun(str, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double(char **str)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[j] && i < 4)
		{
			if (i == j)
				j++;
			if (str[i][0] == str[j][0])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
