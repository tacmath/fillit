/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 12:29:42 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 12:36:59 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void		add_tetri(t_map *map, int piece, int mode)
{
	int		i;
	t_point	*coord;
	int		size;

	i = -1;
	size = map->size;
	coord = map->pieces[piece];
	while (++i < 4)
		map->sol[(coord[i].y + map->place[piece].y) *
			size + coord[i].x + map->place[piece].x] = mode;
}

int			ft_check(t_map *map, int piece)
{
	t_point	*coord;
	int		i;
	int		size;

	coord = map->pieces[piece];
	i = -1;
	size = map->size;
	while (++i < 4)
		if (map->sol[(coord[i].y + map->place[piece].y) *
				size + coord[i].x + map->place[piece].x] != 0)
			return (0);
	add_tetri(map, piece, 1);
	return (1);
}

static int	ft_check_co(t_map *map, int n, int m, int i)
{
	int co;

	co = 0;
	if ((map->pieces[m][n].y - 1 == map->pieces[m][i].y)
			&& (map->pieces[m][n].x == map->pieces[m][i].x))
		co++;
	if ((map->pieces[m][n].y + 1 == map->pieces[m][i].y)
			&& (map->pieces[m][n].x == map->pieces[m][i].x))
		co++;
	if ((map->pieces[m][n].y == map->pieces[m][i].y)
			&& (map->pieces[m][n].x - 1 == map->pieces[m][i].x))
		co++;
	if ((map->pieces[m][n].y == map->pieces[m][i].y)
			&& (map->pieces[m][n].x + 1 == map->pieces[m][i].x))
		co++;
	return (co);
}

int			ft_check_pieces(t_map *map)
{
	int	n;
	int	m;
	int	i;
	int	co;

	m = -1;
	while (++m < (int)map->nb)
	{
		co = 0;
		n = -1;
		while (++n < 4)
		{
			i = -1;
			while (++i < 4)
				co += ft_check_co(map, n, m, i);
		}
		if (co < 6)
			return (0);
	}
	return (1);
}
