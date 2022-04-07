/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/07 03:16:56 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	create_tabs(t_cub *cub, char **av)
{
	char	**tab = NULL;
	int		i;
	int		j;
	int		tablen;

	i = -1;
	tab = get_tab(av);
	tablen = ft_arrlen(tab);
	cub->elem = ft_calloc(sizeof(char *), 7);
	manager(cub->elem, 0);
	cub->map = ft_calloc(sizeof(char *), tablen - 5);
	manager(cub->map, 0);
	while (++i < 6)
	{
		cub->elem[i] = ft_strdup(tab[i]);
		manager(cub->elem[i], 0);
	}
	j = 0;
	cub->widthsquare = ft_arrlenmax(&tab[i]);
	while (tab[i])
	{
		cub->map[j] = ft_strdupmap(tab[i], cub->widthsquare);
		manager(cub->map[j], 0);
		i++;
		j++;
	}
}

static	void	init_struct(t_cub *cub, char **av)
{
	create_tabs(cub, av);
	turn_into_square(cub->map);
	cub->height = ft_arrlen(cub->map);
	cub->count_pos = 0;
	cub->rgb = ft_calloc(sizeof(int), 3);
	manager(cub->rgb, 0);
}

void	manager(void *ptr, int err)
{
	static t_list	*heap = NULL;
	t_list			*new;

	if (err == 1)
		ft_lstclear(&heap, free);
	else
	{
		new = ft_lstnew(ptr);
		ft_lstadd_back(&heap, new);
	}
}

int	main(int ac, char **av)
{
	t_cub	cub;
	int i = -1;
	ft_bzero(&cub, sizeof(t_cub));
	init_struct(&cub, av);
	parser(&cub, ac, av);
	while (cub.map[++i])
		printf("%s\n", cub.map[i]);
	return (0);
}
