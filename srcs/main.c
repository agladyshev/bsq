#include "bsq.h"

# define BUF 4096

int	solve_map(char *filename)
{
	char	*map_char;
	char	**map;
	int	lines;
	int 	file;
	
	map_char = malloc(sizeof(char) * 3);
	file = open(filename, 0);
	if (file < 0)
		return (0);
	lines = get_map_meta(&map_char, file);
	if (lines == 0 || !map_char[0] || !map_char[1] || !map_char[2])
	{
		printf("fail\n");
		return (0);
	}
	printf("Empty: %c | Obst: %c | Full: %c | Lines: %d\n", map_char[0], map_char[1], map_char[2], lines);
	map = map_to_arr(file, lines);
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
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
	return(is_error);
}
