/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/16 04:11:29 by rfkaier          ###   ########.fr       */
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
# include <math.h>
# define SUCCESS 0
# define FAILURE 1
# define NORM "01NSEW"
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define M 46
# define TAB 48
# define PLUS 69
# define MINUS 78
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define NORTH 90
# define SOUTH 270
# define EAST 0
# define WEST 180

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cub
{
	char	**elem;
	char	**map;
	int		widthsquare;
	int		width;
	int		height;
	int		pix_x;
	int		pix_y;
	int		count_pos;
	int		*rgb;
	double		angle;
	void	*mlx;
	void	*win;
	double	player_x;
	double	player_y;
	double		dy;
	double		dx;
	t_data	img;
	
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

	/*	deal with key */
int		deal_key(int keycode, t_cub *cub);
int		exit_game(void);

	/*	graphical part */

void	draw_minimap(t_cub *cub);
void	draw_player(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	vision(t_cub *cub);

	/* utils */
void	which_direction(t_cub *cub);
void	define_starting_dydx(t_cub *cub);
//procuration dalil naima 1er dec 1968

#endif