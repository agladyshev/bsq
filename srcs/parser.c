/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:50:46 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/09 14:09:00 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		get_map_meta(char **map_char, int file)
{
	int		lines;
	int		bytes;
	int		i;
	char	buf[1];
	char	*str;

	str = malloc(sizeof(char) * BUF);
	bytes = read(file, buf, 1);
	lines = 0;
	i = 0;
	while (bytes && *buf != 10)
	{
		str[i] = buf[0];
		bytes = read(file, buf, 1);
		i++;
	}
	if (i < 4)
		return (0);
	(*map_char)[2] = str[--i];
	(*map_char)[1] = str[--i];
	(*map_char)[0] = str[--i];
	lines = get_num_from_str(str, i);
	free(str);
	return (lines);
}

char	*get_line_one(int file)
{
	char	buf[1];
	char	*line;
	int		bytes;
	int		i;
	int		n;

	n = 1;
	bytes = read(file, buf, 1);
	line = malloc(sizeof(char) * BUF);
	i = 0;
	while (bytes && *buf != 10)
	{
		if ((i + 1) % BUF == 0)
			line = get_copy_plus_buf(&line, ++n);
		line[i] = buf[0];
		bytes = read(file, buf, 1);
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**init_arr(int file, int lines)
{
	char	**map;
	char	*first;
	int		line_len;
	int		i;

	first = get_line_one(file);
	line_len = ft_strlen(first);
	map = malloc(sizeof(char *) * lines + 1);
	if (!map)
		return (0);
	map[0] = malloc(sizeof(char) * line_len + 1);
	i = 0;
	while (i <= line_len)
	{
		map[0][i] = first[i];
		i++;
	}
	free(first);
	return (map);
}

char	*read_line(int file, int line_len)
{
	char	*line;
	int		bytes;
	int		total;

	total = 0;
	line = malloc(sizeof(char) * (line_len + 1));
	while (total < line_len + 1)
	{
		bytes = read(file, line + total, line_len + 1 - total);
		total += bytes;
		if (!bytes)
		{
			free(line);
			line = 0;
			return (line);
		}
	}
	if (line != 0)
		line[line_len] = '\0';
	return (line);
}

char	**map_to_arr(int file, int lines)
{
	int		line_len;
	int		i;
	char	**map;

	map = init_arr(file, lines);
	line_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		i++;
		map[i] = read_line(file, line_len);
	}
	if (lines != i)
		return (0);
	return (map);
}
