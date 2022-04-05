/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/05 13:32:23 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void 	turn_into_square(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == ' ')
				str[i][j] = '*';
			j++;
		}
		i++;
	}
}

static	char	*ft_strdupmap(const char *src, int len)
{
	size_t	i;
	char	*dest;

	dest = ft_calloc(sizeof(char), (len + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		if (src[i] == '\0')
		{
			while (i < len)
			{
				dest[i] = '*';
				i++;
			}
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	void	init_struct(t_cub *cub)
{
	turn_into_square(cub->map);
	//printf("%d\n", cub->width);
}

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
	cub->width = ft_arrlenmax(&tab[i]);
	while (tab[i])
	{
		cub->map[j] = ft_strdupmap(tab[i], cub->width);
		//printf("%s\n", cub->map[j]);
		manager(cub->map[j], 0);
		i++;
		j++;
	}
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
	create_tabs(&cub, av);
	init_struct(&cub);
	while (cub.map[++i])
		printf("%s\n", cub.map[i]);
		
	//parser(&cub, ac, av);
	return (0);
}
