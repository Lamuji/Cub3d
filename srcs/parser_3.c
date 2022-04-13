/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:30:17 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/13 04:25:31 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	which_direction(char **str, int angle)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N')
				angle = NORTH;
			if (str[i][j] == 'S')
				angle = SOUTH;
			if (str[i][j] == 'E')
				angle = EAST;
			if (str[i][j] == 'W')
				angle = WEST;
			j++;
		}
		i++;
	}
}

int	check_closed(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[0][j] != '1' && str[0][j] != '*')
				return (0);
			if (str[i + 1] == NULL)
			{
				if (str[i][j] != '1' && str[i][j] != '*')
					return (0);
			}
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
