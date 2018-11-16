/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 12:14:00 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 15:08:19 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <unistd.h>

void			ft_mapdel(t_map **map)
{
	unsigned int n;

	if (!(map && *map))
		return ;
	n = -1;
	while (++n < (*map)->nb)
		ft_memdel((void**)&(*map)->pieces[n]);
	ft_memdel((void**)&(*map)->pieces);
	ft_memdel((void**)&(*map)->place);
	if ((*map)->sol)
		ft_strdel(&((*map)->sol));
	ft_memdel((void**)&(*map));
}

int				clean_exit(char **s)
{
	ft_strdel(s);
	return (-1);
}

t_point			ft_tetrilen(t_map *map, int nb)
{
	t_point	len;
	int		n;

	n = 0;
	len.x = map->pieces[nb][0].x;
	len.y = map->pieces[nb][0].y;
	while (++n < 4)
	{
		if (len.x < map->pieces[nb][n].x)
			len.x = map->pieces[nb][n].x;
		if (len.y < map->pieces[nb][n].y)
			len.y = map->pieces[nb][n].y;
	}
	return (len);
}

unsigned int	ft_sizemin(t_map *map)
{
	unsigned int n;

	n = 2;
	while (n * n < map->nb * 4)
		n++;
	return (n);
}

void			ft_fill_tetri(t_map *map, int diez, int x, int y)
{
	map->pieces[map->nb][diez].x = x;
	map->pieces[map->nb][diez].y = y;
}
