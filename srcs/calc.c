#include "bsq.h"

int	**init_binary_map(char **map, int lines, char *map_char)
{
	int	line_size;
	int	**arr;
	int	i;
	int	j;

	line_size = ft_strlen(map[0]);
	arr = malloc(sizeof(char *) * (lines + 1));
	arr[lines] = 0;
	i = 0;
	while (i < lines)
	{
		arr[i] = malloc(sizeof(int) * (line_size + 1));
		arr[i][line_size] = -1;
		j = 0;
		while (j < line_size)
		{
			arr[i][j] = (map_char[0] == map[i][j]) ? 1 : 0;
			j++;
		}
		i++;
	}
	return (arr);
}
