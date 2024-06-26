/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:28:53 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/26 14:56:56 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	schr(char *str, int c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

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
			if (str[i][j] != '1' && str[i][j] != '0' && (str[i][j] != 'N'
				|| str[i][j] != 'S' || str[i][j] != 'E' || str[i][j] != 'W')
				&& str[i][j] != '*')
				return (0);
		j++;
		}
	i++;
	}
	return (1);
}

int	check_holes(char **tab)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
			{
				if (!schr(NORM, tab[i][j + 1])
			|| !schr(NORM, tab[i][j - 1]) || !schr(NORM, tab[i + 1][j])
			|| !schr(NORM, tab[i - 1][j]))
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

void	parser(t_cub *cub, int ac, char **av)
{
	check_pos(cub);
	if (!arg_is_correct(ac, av[1]))
		ft_putendl_exit("Error: Bad extension", STDERR_FILENO);
	if (!elem_nbr(cub))
		ft_putendl_exit("Error: Wrong format or missing elements",
			STDERR_FILENO);
	if (!check_double(cub->elem))
		ft_putendl_exit("Error : Elements must be defined once", STDERR_FILENO);
	if (cub->count_pos != 1)
		ft_putendl_exit("Error: Too many or no starting pos", STDERR_FILENO);
	if (check_invalid_char(cub->map))
		ft_putendl_exit("Error: Invalid character", STDERR_FILENO);
	if (!check_closed(cub->map, cub->widthsquare, cub->height))
		ft_putendl_exit("Error: Map not closed", STDERR_FILENO);
	if (check_holes(cub->map))
		ft_putendl_exit("Error: Map error", STDERR_FILENO);
}
