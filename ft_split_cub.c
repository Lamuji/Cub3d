/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:19:45 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/03 18:30:23 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_split_map(char const *str, char set, int num)
{
	char	**tab;
	int		i;
	int		m_tab;
	int		len_word;
	int		count;

	m_tab = 0;
	i = -1;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(tab), (ft_countwords((char *)str, set) + 1));
	manager(tab, 0);
	while (str[++i])
	{
		if (num > i)
			i++;
		len_word = 0;
		if (str[i] != set)
		{
			while (str[i + len_word] != set && str[i + len_word] != '\0')
				len_word++;
			tab[m_tab++] = ft_strndup(str + i, len_word);
			i = i + len_word - 1;
		}
	}
	tab[m_tab] = 0;
	return (tab);
}

static char	**ft_split_elem(char const *str, char set, int num)
{
	char	**tab;
	int		i;
	int		m_tab;
	int		len_word;
	int		count;

	m_tab = 0;
	count = 0;
	i = -1;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(tab), (ft_countwords((char *)str, set) + 1));
	manager(tab, 0);
	while (str[++i] && count < num)
	{
		len_word = 0;
		if (str[i] != set)
		{
			while (str[i + len_word] != set && str[i + len_word] != '\0')
				len_word++;
			tab[m_tab++] = ft_strndup(str + i, len_word);
			i = i + len_word - 1;
			count++;
		}
	}
	tab[m_tab] = 0;
	return (tab);
}

char	**get_tab(char **tab, char **av, int func)
{
	char	*line;
	int		fd;
	int		r;
	char	buffer[2];

	r = 1;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("file doesn't exist", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (r > 0)
	{
		r = read(fd, &buffer, 1);
		buffer[r] = '\0';
		line = ft_strjjoin(line, buffer);
	}
	if (func == 1)
		tab = ft_split_elem(line, '\n', 6);
	else
		tab = ft_split_map(line, '\n', 6);
	manager(tab, 0);
	return (tab);
}
