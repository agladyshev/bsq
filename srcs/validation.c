/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:50:52 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/09 11:50:53 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_map_valid(char **map, char *map_char)
{
	int len;
	int i;

	len = ft_strlen(map[0]);
	while (*map != 0)
	{
		i = 0;
		while ((*map)[i] != '\0')
		{
			if ((*map)[i] != map_char[0] &&
				(*map)[i] != map_char[1])
				return (0);
			i++;
		}
		if (i != len)
			return (0);
		map++;
	}
	return (1);
}
