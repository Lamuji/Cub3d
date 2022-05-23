/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:19:45 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/23 18:24:02 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	turn_into_square(char **str)
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

char	*ft_strdupmap(const char *src, int len)
{
	size_t	i;
	char	*dest;

	dest = ft_calloc(sizeof(char), (len + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while ((int)i < len)
	{
		if (src[i] == '\0')
		{
			while ((int)i < len)
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

static char	*ft_strjjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	manager(dest);
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

char	**get_tab(char **av)
{
	char	**tab;
	char	*line;
	int		fd;
	int		r;
	char	buffer[2];

	r = 1;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error. - File doesn't exist", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (r > 0)
	{
		r = read(fd, &buffer, 1);
		buffer[r] = '\0';
		line = ft_strjjoin(line, buffer);
	}
	tab = ft_split(line, '\n');
	manager(tab);
	return (tab);
}
