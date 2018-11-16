/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   output.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 14:50:57 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 15:30:30 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <unistd.h>

void	ft_output(t_map *map)
{
	char			*str;
	unsigned int	m;
	unsigned int	n;

	str = ft_memalloc(map->size * (map->size + 1) + 1);
	n = -1;
	while (++n < (map->size * (map->size + 1)))
		str[n] = '.';
	n = -1;
	while (++n < map->size)
		str[(n + 1) * (map->size + 1) - 1] = '\n';
	m = -1;
	while (++m < map->nb)
	{
		n = -1;
		while (++n < 4)
			str[map->pieces[m][n].x + map->place[m].x + (map->pieces[m][n].y
			+ map->place[m].y) * (map->size + 1)] = 'A' + m;
	}
	write(1, str, (map->size * (map->size + 1)));
	ft_strdel(&str);
}
