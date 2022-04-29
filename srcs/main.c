/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzi <ramzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/29 06:56:02 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	looping(t_cub *cub)
{
	int l = 0;
	check_move(cub);
	double i = cub->angle - 30;
	draw_minimap(cub);
	draw_player(cub);
	vision(cub, cub->angle);
	double slice_height = cub->projected_dist * (cub->ray_length * 6);
	int begin = SCR_H/2 - slice_height;
	int end = SCR_H/2 + slice_height;
	while (l < SCR_W)
	{
		end = 920/2 + slice_height;
		while (begin < end)
		{
			my_mlx_pixel_put(&cub->img, l, end, 0x00FF0000);
			end--;
		}
		l++;
	}
//	cub3d(cub, i);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return (0);
}

static	void	create_tabs(t_cub *cub, char **av)
{
	char	**tab;
	int		i;
	int		j;
	int		tablen;

	i = -1;
	tab = get_tab(av);
	if (tab[0] == NULL)
		ft_putendl_exit("Error. - file.cub is empty", STDERR_FILENO);
	tablen = ft_arrlen(tab);
	cub->elem = ft_calloc(sizeof(char *), 7);
	manager(cub->elem);
	cub->map = ft_calloc(sizeof(char *), tablen - 5);
	manager(cub->map);
	while (++i < 6)
	{
		cub->elem[i] = ft_strdup(tab[i]);
		manager(cub->elem[i]);
	}
	j = 0;
	cub->widthsquare = ft_arrlenmax(&tab[i]);
	while (tab[i])
	{
		cub->map[j] = ft_strdupmap(tab[i], cub->widthsquare);
		manager(cub->map[j]);
		i++;
		j++;
	}
}

static	void	init_struct(t_cub *cub, char **av)
{
	create_tabs(cub, av);
	turn_into_square(cub->map);
	cub->height = ft_arrlen(cub->map);
	cub->count_pos = 0;
	cub->rgb = ft_calloc(sizeof(int), 3);
	manager(cub->rgb);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, 1080, 920, "Cub3d");
	cub->img.img = mlx_new_image(cub->mlx, 1080, 920);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	cub->set_key = 0;
	cub->projected_dist = 64/(floor(460/tan(convert_ang(30))));
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
	int i = -1;
	ft_bzero(&cub, sizeof(t_cub));
	init_struct(&cub, av);
	parser(&cub, ac, av);
	player_pos(&cub);
	//printf("position player x %f y %f\n", cub.dx, cub.dy);
	mlx_hook(cub.win, 2, 0, deal_key, &cub);
	mlx_hook(cub.win, 17, 0, exit_game, &cub);
	mlx_loop_hook(cub.mlx, looping, &cub);
	mlx_loop(cub.mlx);
	return (0);
}

// salut, revoit la fonction check horizontal et repare tes soucis, 
//tu dois placer des pixel a chq fois que tu passe par une ligne ou colonne 
//juska un mur. 