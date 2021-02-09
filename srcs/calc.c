#include "bsq.h"

int	get_min_of_3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c && b <= a)
		return (b);
	else if (c <= b && c <= a)
		return (c);
	return (0);
}

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
			if (i > 0 && j > 0 && map[i][j] != map_char[1])
				arr[i][j] = get_min_of_3(
				arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
	return (arr);
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
