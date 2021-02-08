#include "bsq.h"

# define BUF 4096

int	get_num_from_str(char *str, int i)
{
	int	j;
	int	nbr;

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
	int	bytes;
	int	i;

	bytes = read(file, buf, 1);	
	line = malloc(sizeof(char) * BUF);
	i = 0;
	while (bytes && *buf != 10)
	{	
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
	int	line_len;
	int	i;

	first = get_line_one(file);
	line_len = ft_strlen(first);
	printf("%d len \n", line_len);
	map = malloc(sizeof(char *) * lines + 1);
	map[0] = malloc(sizeof(char) * line_len + 1);
	i = 0;
	while (i <= line_len)
	{
		map[0][i] = first[i];
		i++;
	}
	free(first);
	printf("First line of arr is: %s\n", map[0]);
	return (map);
}

char	**map_to_arr(int file, int lines)
{
	char	**map;
	int	line_len;
	int	i;
	int	bytes;

	map = init_arr(file, lines);
	line_len = ft_strlen(map[0]);
	bytes = -1;
	i = 1;
	while (bytes)
	{
		map[i] = malloc(sizeof(char) * (line_len + 1));
		bytes = read(file, map[i], line_len + 1);
		if (bytes < line_len + 1 && bytes > 0)
			return (0);
		map[i][line_len] = '\0';
		if (!bytes)
			map[i] = 0;
		else
			i++;
	}
	printf("Lines read: %d\n", i);
	return (map);
}
