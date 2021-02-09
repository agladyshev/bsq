/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:05:20 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/09 14:07:39 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*get_copy_plus_buf(char **str, int n)
{
	int		i;
	char	*copy;
	int		size;
	int		prev_size;

	size = BUF * n;
	prev_size = BUF * (n - 1);
	copy = malloc(sizeof(char) * size);
	i = 0;
	while (i < prev_size)
	{
		copy[i] = (*str)[i];
		i++;
	}
	free(*str);
	return (copy);
}
