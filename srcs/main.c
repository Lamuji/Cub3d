/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:47:05 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/18 02:31:18 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

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
	cub->win = mlx_new_window(cub->mlx, 1920, 1080, "Cub3d");
	cub->img.img = mlx_new_image(cub->mlx, 1920, 1080);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	cub->pix_y = 0;
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
	draw_minimap(&cub);
	draw_player(&cub);
	vision(&cub);
	mlx_put_image_to_window(cub.mlx, cub.win, cub.img.img, 0, 0);
	//mlx_hook(cub.win, 17, 0, exit_game, &cub);
	mlx_loop_hook(cub.win, deal_key, &cub);
	mlx_loop(cub.mlx);

	return (0);
}
