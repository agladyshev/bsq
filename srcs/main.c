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

	i = 0;
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
