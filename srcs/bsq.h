/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:50:39 by stiffiny          #+#    #+#             */
/*   Updated: 2021/02/10 13:20:48 by stiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUF 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		get_map_meta(char **map_char, int file);
int		is_map_valid(char **map, char *map_char);
char	**map_to_arr(int file, int lines);
void	ft_putstr(char *str);
int		**init_binary_map(char **map, int lines, char *map_char);
void	print_map(char **map);
void	free_arr_char(char **arr);
void	free_arr_int(int **arr);
int		*get_bsq(int **arr);
char	*get_copy_plus_buf(char **str, int n);
int		get_num_from_str(char *str, int i);
#endif
