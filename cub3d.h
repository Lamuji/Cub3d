/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/04 17:58:19 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include <fcntl.h>
# define SUCCESS 0
# define FAILURE 1

typedef struct s_cub
{
	char	**elem;
	char	**map;
	int		width;
	int		height;
}			t_cub;
		/*  LE BOSS DES LEAKS */

void	manager(void *ptr, int err);


		/* PARSING */

char	**get_tab(char **av);
int		parser(t_cub *map, int ac, char **av);
#endif