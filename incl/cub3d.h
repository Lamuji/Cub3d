/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/18 16:38:33 by rfkaier          ###   ########.fr       */
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
# include <OpenGL/OpenGL.h> 
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
# define PI 3.1415926535
# define P2 PI/2
# define P3 3 * PI/2
# define DR	0.0174533
# define SPEED 10
# define SCR_W 960
# define SCR_H 640
# define MID_H SCR_H/2
# define MINIPIX 16
# define TRIDPIX 64

static	int	cursor;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct s_render
{
	int	*color_v;
	int	color_h;
	char *wall_v;
	char *wall_h;
	char *text;
	void *no;
	char *so;
	char *we;
	char *ea;
}			t_render;

typedef struct s_minimap
{
	int plmapx;
	int plmapy;
}				t_minimap;

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
	int		*rgbC;
	int		*rgbF;
	double	start_angle;
	double	angle;
	double	ra_angle;
	void	*mlx;
	void	*win;
	double	player_x;
	double	player_y;
	double	set_key;
	double	Hx; // final horiz dist x
	double	Hy; // final horiz dist y
	double	Vx; // final vertical dist x
	double	Vy; // final vertical dist y
	double	fx; // final distance x
	double	fy; // final distance y
	double	dx; 
	double	dy;
	double	step;
	double	ray_length;
	double	projected_dist;
	double	wall_top;
	double	wall_bottom;
	double	slice_height;
	t_render render;
	t_minimap minimap;
	t_data	img;
	t_data	img2;
	t_data	img3;
}			t_cub;



	/*	LE BOSS DES LEAKS	*/
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
int		check_closed(char **str, int width);
int		check_double(char **str);
void	player_pos(t_cub *cub);
void	player_pos_game(t_cub *cub);

	/*	graphical part	*/

void	draw_minimap(t_cub *cub);
void	draw_player(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	vision(t_cub *cub, double angle);
void	dda_algo(t_cub *cub);
void	draw(t_cub *cub, double x, double y);
int		looping(t_cub *cub);
void	check_horizontal_up(t_cub *cub, int size);
void	check_horizontal_down(t_cub *cub, int size);
void	check_vertical_right(t_cub *cub, int size);
void	check_vertical_left(t_cub *cub, int size);
void	the_right_one(t_cub *cub);
void	cub3d(t_cub *cub, double angle);

	/*	movements	*/
void	check_move(t_cub *cub);
int		deal_key(int keycode, t_cub *cub);
int		deal_mouse(int x, int y, t_cub *cub);
int		exit_game(void);

	/*	utils	*/
unsigned long 	rgb_to_hex(int r, int g, int b);
double			convert_ang(double angle);
void			which_direction(t_cub *cub);
void			define_starting_dydx(t_cub *cub);
int				mlx_mouse_hide();
void			path_to_text(t_cub *cub, char *str, char *path);
//procuration dalil naima 1er dec 1968

#endif