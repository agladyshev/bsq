#include "bsq.h"

void	print_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		map++;
	}
}

void	print_int_map(int **arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j] != 0)
	{
		i = 0;
		while (arr[j][i] != -1)
		{
			printf("%d", arr[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int	*get_bsq(int **arr)
{
	int *bsq;
	int i;
	int j;

	bsq = malloc(sizeof(int) * 3);
	bsq[2] = 0;
	j = 0;
	while (arr[j] != 0)
	{
		i = 0;
		while (arr[j][i] != -1)
		{
			if (arr[j][i] > bsq[2])
			{
				bsq[2] = arr[j][i];
				bsq[0] = i;
				bsq[1] = j;
			}
			i++;
		}
		j++;
	}
	return (bsq);
}

void	update_map(char ***map, int **arr, char *map_char)
{
	int *bsq;
	int i;
	int j;

	bsq = get_bsq(arr);

	printf("%d %d %d \n", bsq[0], bsq[1], bsq[2]);
	j = 0;
	while (arr[j] != 0)
	{
		i = 0;
		while (arr[j][i] != -1)
		{
			if (i > bsq[0] - bsq[2] && j > bsq[1] - bsq[2] && i <= bsq[0] && j <= bsq[1])
				(*map)[j][i] = map_char[2];
			i++;
		}
		j++;
	}
	free(bsq);
}

int	solve_map(char *filename)
{
	char	*map_char;
	char	**map;
	int	lines;
	int	file;
	int	**arr;

	map_char = malloc(sizeof(char) * 3);
	file = open(filename, 0);
	if (file < 0)
		return (1);
	lines = get_map_meta(&map_char, file);
	if (lines == 0 || !map_char[0] || !map_char[1] || !map_char[2])
	{
		return (1);
	}
	printf("Empty: %c | Obst: %c | Full: %c | Lines: %d\n",
			map_char[0], map_char[1], map_char[2], lines);
	map = map_to_arr(file, lines);
	if (!map || !is_map_valid(map, map_char))
		return (1);
	print_map(map);
	arr = init_binary_map(map, lines, map_char);
	print_int_map(arr);
	update_map(&map, arr, map_char);
	print_map(map);
	return (0);
}

int	main(int argc, char **argv)
{
	int	is_error;

	is_error = 0;
	argc--;
	argv++;
	if (!argc)
		is_error = solve_map(0);
	else
		while (*argv)
		{
			is_error = solve_map(*argv);
			if (is_error)
			{
				write(1, "Map error\n", 10);
				return (1);
			}
			argv++;
		}
	return (is_error);
}
