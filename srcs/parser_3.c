/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:30:17 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/24 18:12:26 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

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
			if (cub->map[i][j] == 'W'){
				cub->angle = WEST;
			}
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


// erreur a gerer : Joueur est en bord de map a la place d'un mur 
// joueur est entoure de mur 