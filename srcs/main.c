/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:49:52 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/09 11:49:55 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	update_map(char ***map, int **arr, char *map_char)
{
	int *bsq;
	int i;
	int j;

	bsq = get_bsq(arr);
	j = 0;
	while (arr[j] != 0)
	{
		i = 0;
		while (arr[j][i] != -1)
		{
			if (i > bsq[0] - bsq[2] && j > bsq[1] - bsq[2]
					&& i <= bsq[0] && j <= bsq[1])
				(*map)[j][i] = map_char[2];
			i++;
		}
		j++;
	}
	free(bsq);
}

int		solve_map(char *filename)
{
	char	*map_char;
	char	**map;
	int		lines;
	int		file;
	int		**arr;

	map_char = malloc(sizeof(char) * 3);
	file = (filename != 0) ? open(filename, 0) : 0;
	if (file < 0)
		return (1);
	lines = get_map_meta(&map_char, file);
	if (lines == 0 || !map_char[0] || !map_char[1] || !map_char[2])
		return (1);
	map = map_to_arr(file, lines);
	if (!map || !is_map_valid(map, map_char))
		return (1);
	arr = init_binary_map(map, lines, map_char);
	update_map(&map, arr, map_char);
	print_map(map);
	free_arr_char(map);
	free_arr_int(arr);
	free(map_char);
	return (0);
}

int		main(int argc, char **argv)
{
	int	is_error;
	int	i;

	i = 0;
	is_error = 0;
	argc--;
	argv++;
	if (!argc)
		is_error = solve_map(0);
	else
		while (i < argc)
		{
			if (i > 0)
				write(1, "\n", 1);
			is_error = solve_map(argv[i]);
			if (is_error)
			{
				write(1, "Map error\n", 10);
				return (1);
			}
			i++;
		}
	if (is_error)
		write(1, "Map error\n", 10);
	return (is_error);
}
