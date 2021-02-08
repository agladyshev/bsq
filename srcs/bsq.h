#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_strlen(char *);
int	get_map_meta(char **map_char, int file);
char	**map_to_arr(int file, int lines);

#endif




