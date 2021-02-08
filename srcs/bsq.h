#ifndef BSQ_H
# define BSQ_H
# define BUF 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int	ft_strlen(char *str);
int	get_map_meta(char **map_char, int file);
int	is_map_valid(char **map, char *map_char);
char	**map_to_arr(int file, int lines);

#endif
