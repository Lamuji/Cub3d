/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/03 18:29:26 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

char	*ft_strjjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	manager(dest, 0);
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	len_s2 = -1;
	while (s2[++len_s2])
	{
		dest[i] = s2[len_s2];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	main(int ac, char **av)
{
	char **elem;
	char **map;
	int i;

	i = -1;
	elem = get_tab(elem, av, 1);
	map = get_tab(map, av, 2);

	while (map[++i])
		printf("%s\n", map[i]);
	while (1);
	return (0);
}
