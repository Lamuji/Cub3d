/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlenmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:14:38 by rfkaier           #+#    #+#             */
/*   Updated: 2022/04/05 12:15:03 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrlenmax(char **str)
{
	int	i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!str[i + 1])
		 	return (res);
		if (res < ft_strlen(str[i]))
			res = ft_strlen(str[i]);
		i++;
	}
	return (res);
}
