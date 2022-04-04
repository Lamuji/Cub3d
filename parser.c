/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:28:53 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/04 18:45:23 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_invalid_char(char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' || str[i][j] != '0' || (str[i][j] != 'N'
				|| str[i][j] != 'S' || str[i][j] != 'E' || str[i][j] != 'W'))
				return (1);
		j++;
		}
	i++;
	}
	return (0);
}

int	check_wall(char **tab, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < width)
		{
			if (i == '0' || j == '0' || i == height - 1 || j == width - 1)
			{
				if (tab[i][j] != '1')
					return (1);
			}
		j++;
		}
	i++;
	}
	return (0);
}

int	arg_is_correct(int ac, char *str)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (str[i])
		{
			if (str[i] == '.')
			{
				if (str[i + 1] == 'c' && str[i + 2] == 'u'
					&& str[i + 3] == 'b' && !(str[i + 4]))
					return (1);
			}
			i++;
		}
	}
	return (0);
}

int		parser(t_cub *map, int ac, char **av)
{
	map->width = ft_strlen()
	if (!arg_is_correct(ac, av[1]))
		ft_putendl_fd("Error. Bad extension", STDERR_FILENO);
	else if ()
}

// mauvais nb d'arguments
// pas un fichier .cub
// dossier envoyé
// un paramètre (texture/couleur) est défini 2 fois
// un paramètre n'a pas été décrit ou est décrit après la map
// fichier de texture existe pas
// fichier de texture qui est un dossier
// fichier de texture qui finit pas par .xpm
// couleur contient pas 3 nombres
// que des nombres pour les couleurs (is digit)
// un nombre est plus petit que 0 ou plus grand que 255
// un paramètre est mal décrit (exemple: la ligne du nord commence par NOO et pas NO)
// mauvais caractère dans la map
// pas de map
// espace pas entouré par des murs ou par un autre espace
// trop de positions de départ
// aucune position de départ
// map pas entouré de mur / les 0 sont entourés de 0 ou de 1