/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/09 15:57:49 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
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
	void	*mlx;
	void	*win;
	
}			t_cub;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

	/*	deal with key */
int		exit_game(void);

	/*	graphical part */
void	draw_minimap(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//procuration dalil naima 1er dec 1968

#endif