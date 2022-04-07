/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:29 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/07 19:16:38 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	norm_color(char *str, int *rgb)
{
	int	i = -1;
	int j;
	char **spl_color;

	spl_color = ft_split(((char *)str + 2),',');
	manager(spl_color);
	if (ft_arrlen(spl_color) != 3)
		return (0);
	while (spl_color[++i])
	{
		rgb[i] = ft_atoi(((char *)spl_color[i]));
		if (rgb[i] > 255 || rgb[i] < 0)
			return (0);
	}
	return (1);
}

static	int	ft_reverse_ch_int(char *str, char *to_find)
{
	int	i;
	int j;

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
			return(1);
	}
	else if (ft_ch_int(str, "C ") || ft_ch_int(str, "F "))
	{
		if (norm_color(str, cub->rgb))
			return (1);
	}
	return (0);
}

void	check_pos(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N'|| cub->map[i][j] == 'S'
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

// mauvais nb d'arguments OK
// pas un fichier .cub OK
// dossier envoyé 
// un paramètre (texture/couleur) est défini 2 fois 
// un paramètre n'a pas été décrit ou est décrit après la map
// fichier de texture qui finit pas par .xpm OK
// couleur contient pas 3 nombres
// que des nombres pour les couleurs (is digit) 
// un nombre est plus petit que 0 ou plus grand que 255 OK
// un paramètre est mal décrit (exemple: la ligne du nord commence par NOO et pas NO) OK
// mauvais caractère dans la map OK
// pas de map 
// espace pas entouré par des murs ou par un autre espace OK
// trop de positions de départ OK 
// aucune position de départ OK
// map pas entouré de mur / les 0 sont entourés de 0 ou de 1 OK