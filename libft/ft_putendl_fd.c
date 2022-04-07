/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:21:06 by edalmis           #+#    #+#             */
/*   Updated: 2022/04/06 11:30:42 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		write (fd, s, len);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_putendl_exit(char *s, int fd)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		write (fd, s, len);
		ft_putchar_fd('\n', fd);
	}
	exit(EXIT_FAILURE);
}