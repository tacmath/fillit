/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lperron <lperron@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 13:43:12 by lperron      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 12:37:24 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int	ft_place_piece(t_map *map, unsigned int piece, int x, int y)
{
	t_point max;

	if (piece == map->nb)
		return (1);
	max = ft_tetrilen(map, piece);
	while (++y < (int)map->size - max.y)
	{
		while (++x < (int)map->size - max.x)
		{
			map->place[piece].x = x;
			map->place[piece].y = y;
			if (ft_check(map, piece))
			{
				if (ft_place_piece(map, piece + 1, -1, -1))
					return (1);
				add_tetri(map, piece, 0);
			}
		}
		x = -1;
	}
	map->place[piece].x = -1;
	map->place[piece].y = -1;
	return (0);
}

int			ft_resolve(t_map *map)
{
	unsigned int i;

	i = -1;
	map->size = ft_sizemin(map);
	if (!(map->sol = ft_strnew(map->size * map->size)))
		return (0);
	while (++i < map->nb)
	{
		map->place[i].x = -1;
		map->place[i].y = -1;
	}
	while (!ft_place_piece(map, 0, -1, -1))
	{
		i = -1;
		map->size += 1;
		while (++i < map->nb)
		{
			map->place[i].x = -1;
			map->place[i].y = -1;
		}
		ft_strdel(&(map->sol));
		if (!(map->sol = ft_strnew(map->size * map->size)))
			return (0);
	}
	return (1);
}
