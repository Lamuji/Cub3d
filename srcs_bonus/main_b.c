/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/05/26 20:27:25 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	looping(t_cub *cub)
{
	double	i;

	cub->img.img = mlx_new_image(cub->mlx, SCR_W, SCR_H);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->img2.img = mlx_new_image(cub->mlx, cub->widthsquare * 8,
			cub->height * 8);
	cub->img2.addr = mlx_get_data_addr(cub->img2.img, &cub->img2.bits_per_pixel,
			&cub->img2.line_length, &cub->img2.endian);
	i = cub->angle - 30;
	cub3d(cub, i);
	draw_minimap(cub);
	draw_player(cub);
	check_move(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img2.img, 20, 20);
	mlx_mouse_hide();
	mlx_destroy_image(cub->mlx, cub->img.img);
	mlx_destroy_image(cub->mlx, cub->img2.img);
	return (0);
}

static	void	create_tabs(t_cub *cub, char **av)
{
	char	**tab;
	int		i;
	int		j;
	int		tablen;

	i = -1;
	j = 0;
	tab = get_tab(av);
	if (tab[0] == NULL)
		ft_putendl_exit("Error. - file.cub is empty", STDERR_FILENO);
	tablen = ft_arrlen(tab);
	cub->elem = ft_calloc(sizeof(char *), 7);
	manager(cub->elem);
	cub->map = ft_calloc(sizeof(char *), tablen - 5);
	manager(cub->map);
	fill_tabs(cub, i, j, tab);
}

static	void	init_struct(t_cub *cub, char **av)
{
	init_value(cub);
	create_tabs(cub, av);
	turn_into_square(cub->map);
	cub->height = ft_arrlen(cub->map);
	cub->count_pos = 0;
	cub->rgbf = ft_calloc(sizeof(int), 3);
	cub->rgbc = ft_calloc(sizeof(int), 3);
	manager(cub->rgbc);
	manager(cub->rgbf);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, SCR_W, SCR_H, "Cub3d");
	cub->set_key = 0;
	cub->projected_dist = floor(MID_H / tan(convert_ang(30.0)));
	which_direction(cub);
}

void	manager(void *ptr)
{
	static t_list	*heap = NULL;
	t_list			*new;

	new = ft_lstnew(ptr);
	ft_lstadd_back(&heap, new);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	ft_bzero(&cub, sizeof(t_cub));
	init_struct(&cub, av);
	parser(&cub, ac, av);
	player_pos(&cub);
	mlx_hook(cub.win, 2, 0, deal_key, &cub);
	mlx_hook(cub.win, 3, 0, deal_key, &cub);
	mlx_hook(cub.win, 17, 0, exit_game, &cub);
	mlx_hook(cub.win, 6, 0, deal_mouse, &cub);
	mlx_loop_hook(cub.mlx, looping, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
