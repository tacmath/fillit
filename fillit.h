/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lperron <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 13:39:56 by lperron      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 15:05:51 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

struct					s_point
{
	int		x;
	int		y;
};

typedef struct s_point	t_point;

struct					s_map
{
	unsigned int		nb;
	unsigned int		size;
	char				*sol;
	t_point				**pieces;
	t_point				*place;
};

typedef struct s_map	t_map;

int						clean_exit(char **s);
int						get_next_lineb(const int fd, char **line);
void					ft_mapdel(t_map **map);
unsigned int			ft_sizemin(t_map *map);
int						ft_check_pieces(t_map *map);
void					ft_output(t_map *map);
t_map					*ft_read_input(char *file);
int						ft_check(t_map *map, int piece);
int						ft_resolve(t_map *map);
t_point					ft_tetrilen(t_map *map, int nb);
void					ft_fill_tetri(t_map *map, int diez, int x, int y);
void					add_tetri(t_map *map, int piece, int mode);
#endif
