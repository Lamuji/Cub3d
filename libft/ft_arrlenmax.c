/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlenmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:14:38 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/07 23:07:46 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrlenmax(char **str)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (res < ft_strlen(str[i]))
			res = ft_strlen(str[i]);
		if (!str[i + 1])
			return (res);
		i++;
	}
	return (res);
}
