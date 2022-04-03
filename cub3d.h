/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/03 18:28:58 by rfkaier          ###   ########.fr       */
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

//typedef struct t_cub

		/*  LE BOSS DES LEAKS */

void	manager(void *ptr, int err);

		/* PARSING */

char	*ft_strjjoin(char *s1, char *s2);
char	**get_tab(char **tab, char **av, int func);

#endif