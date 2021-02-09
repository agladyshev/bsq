#include "bsq.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		map++;
	}
}

void	free_arr_char(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

void	free_arr_int(int **arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}
