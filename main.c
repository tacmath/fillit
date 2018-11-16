/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lperron <lperron@student.le-101.f>         +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 12:00:57 by lperron      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 13:13:56 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	t_map *map;

	map = NULL;
	if (argc == 2)
	{
		map = ft_read_input(argv[1]);
		if (map == NULL)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (ft_resolve(map))
		{
			ft_output(map);
			ft_mapdel(&map);
		}
	}
	else
		ft_putstr("usage: fillit file\n");
	return (0);
}
