/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/08 00:47:02 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <fcntl.h>
# define SUCCESS 0
# define FAILURE 1
# define NORM "01NSEW"

typedef struct s_cub
{
	char	**elem;
	char	**map;
	int		widthsquare;
	int		height;
	int		count_pos;
	int		*rgb;
}			t_cub;

		/*  LE BOSS DES LEAKS */
void	manager(void *ptr);

		/* PARSING */
char	**get_tab(char **av);
void	turn_into_square(char **str);
char	*ft_strdupmap(const char *src, int len);
void	parser(t_cub *cub, int ac, char **av);
int		check_holes(char **tab);
int		arg_is_correct(int ac, char *str);
int		check_invalid_char(char **str);
void	check_pos(t_cub *cub);
int		elem_nbr(t_cub *cub);
int		check_closed(char **str);
int		check_double(char **str);
//procuration dalil naima 1er dec 1968

#endif