#include "bsq.h"

# define BUF 4096

int	get_num_from_str(char *str, int i)
{
	int j;
	int nbr;

	j = 0;
	nbr = 0;
	while (j < i)
	{
		if(str[j] >= '0' && str[j] <= '9')
			nbr = nbr * 10 + (str[j] - 48);
		j++;
	}
	return (nbr);
}

int	get_map_meta(char **map_char, int file)
{
	int	lines;
	int	bytes;
	int	i;
	char	buf[1];
	char	*str;

	str = malloc(sizeof(char) * 100);
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
/*
int	map_to_str(char *filename)
{
	
}	
*/
int	solve_map(char *filename)
{
	char	*map_char;
	int	lines;
	int 	file;

	map_char = malloc(sizeof(char) * 3);
	file = open(filename, 0);
	if (file < 0)
		return (0);
	lines = get_map_meta(&map_char, file);
	printf("Empty: %c | Obst: %c | Full: %c | Lines: %d\n", map_char[0], map_char[1], map_char[2], lines);
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
