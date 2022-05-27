/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:36:41 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/26 20:40:33 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	check_virgule(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (0);
	return (1);
}

static	int	ramzi(char **tab, int i, int j)
{
	if (tab[i][j] == 'N' || tab[i][j] == 'S'
		|| tab[i][j] == 'E' || tab[i][j] == 'W')
	{
		if (!tab[i + 1])
		{
			if (tab[i][j] != '1' && tab[i][j] != '*')
				return (1);
		}
		if (!schr("01", tab[i][j + 1])
			|| !schr("01", tab[i][j - 1]) || !schr("01", tab[i + 1][j])
			|| !schr("01", tab[i - 1][j]))
			return (1);
	}
	return (0);
}

void	hole_in_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' && line[i + 1] == '\n' && line[i + 2] == '\n')
			ft_putendl_exit("Error - a fucking hole in map!", STDERR_FILENO);
		i++;
	}
}

char	*path(char *str)
{
	char	*new;
	int		i;

	i = 2;
	new = NULL;
	while (str[i] == ' ')
		i++;
	new = ft_strdup((char *)str + i);
	manager(new);
	return (new);
}

int	check_character(char **tab, int height)
{
	size_t	i;
	size_t	j;

	i = 1;
	(void)height;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ramzi(tab, (int)i, (int)j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// /* 1
//    N
//    1

//    VIRGULE ok
//    SO          TEXTURE.XPM ok
// NEWLINE DANS LA MNAP