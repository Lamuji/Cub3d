/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:24 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/26 20:40:42 by rfkaier          ###   ########.fr       */
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
# define CLOSE "1*"
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
# define EAST 180
# define WEST 0
# define PI 3.1415926535
# define P2 1.5707963267
# define P3 4.7123889803
# define DR	0.0174533
# define SPEED 2
# define SCR_W 960.0
# define SCR_H 640.0
# define MID_H 320.0
# define MINIPIX 16.0
# define TRIDPIX 64.0


static int	g_cursor;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_r
{
	int		*so_color;
	int		*no_color;
	int		*ea_color;
	int		*we_color;
	int		color_h;
	int		foundcolor;
	int		type;
	char	*wall_v;
	char	*wall_h;
	int		tx;
	int		ty;
	double	index;
	void	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		width;
	int		height;
	int		a;
	int		b;
	int		c;
}			t_r;

typedef struct s_minimap
{
	int	plmapx;
	int	plmapy;
}				t_minimap;

typedef struct s_cub
{
	char		**elem;
	char		**map;
	int			widthsquare;
	int			width;
	int			height;
	int			pix_x;
	int			pix_y;
	int			count_pos;
	int			*rgbc;
	int			*rgbf;
	double		start_angle;
	double		angle;
	double		ra_angle;
	void		*mlx;
	void		*win;
	double		player_x;
	double		player_y;
	double		set_key;
	double		hx;
	double		hy;
	double		vx;
	double		vy;
	double		fx;
	double		fy;
	double		dx;
	double		dy;
	double		step;
	double		ray_length;
	double		fov_lenght;
	double		projected_dist;
	double		wall_top;
	double		wall_bottom;
	double		slice_height;
	t_r			r;
	t_data		img;
	t_data		img2;
	t_data		img3;
}			t_cub;
	/*	LE BOSS DES LEAKS	*/
void			manager(void *ptr);
	/* PARSING */
char			**get_tab(char **av);
void			turn_into_square(char **str);
char			*ft_strdupmap(const char *src, int len);
void			parser(t_cub *cub, int ac, char **av);
int				check_holes(char **tab);
int				arg_is_correct(int ac, char *str);
int				check_invalid_char(char **str);
void			check_pos(t_cub *cub);
int				elem_nbr(t_cub *cub);
int				check_closed(char **str, int width, int height);
int				check_double(char **str);
void			player_pos(t_cub *cub);
void			player_pos_game(t_cub *cub);
	/*	GRAPHICAL PART	*/
void			draw_minimap(t_cub *cub);
void			draw_player(t_cub *cub);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			vision(t_cub *cub, double angle);
void			dda_algo(t_cub *cub);
void			draw(t_cub *cub, double x, double y);
int				looping(t_cub *cub);
void			check_horizontal_up(t_cub *cub, int size);
void			check_horizontal_down(t_cub *cub, int size);
void			check_vertical_right(t_cub *cub, int size);
void			check_vertical_left(t_cub *cub, int size);
void			the_right_one(t_cub *cub);
void			cub3d(t_cub *cub, double angle);

	/*	MOVEMENTS	*/
void			check_move(t_cub *cub);
int				deal_key(int keycode, t_cub *cub);
int				deal_mouse(int x, int y, t_cub *cub);
int				exit_game(void);

	/*	utils	*/
unsigned long	rgb_to_hex(int r, int g, int b);
double			convert_ang(double angle);
void			init_value(t_cub *cub);
void			which_direction(t_cub *cub);
void			define_starting_dydx(t_cub *cub);
int				mlx_mouse_hide(void);
void			path_to_text(t_cub *cub, char *str, char *path);
int				find_pixel(t_cub *cub, int i);
int				schr(char *str, int c);
void			fill_tabs(t_cub *cub, int i, int j, char **tab);
int				check_character(char **tab, int height);
char			*path(char *str);
void			hole_in_map(char *line);
int				check_virgule(char *str);

#endif