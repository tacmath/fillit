/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lperron <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 13:46:40 by lperron      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 16:32:28 by lperron     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

static	int		ft_get_pieces(t_map *map, unsigned int fd, int i, int diez)
{
	char	*str;
	int		j;
	int		state;

	str = NULL;
	while ((state = get_next_lineb(fd, &str)) > 0 && ++i < 4)
	{
		j = -1;
		if ((ft_strlen(str) != 4 && i != 5) || (i == 4 && ft_strlen(str) != 0))
			return (clean_exit(&str));
		while (str[++j] != '\0')
		{
			if (str[j] == '#')
			{
				if (diez == 3)
					return (clean_exit(&str));
				ft_fill_tetri(map, ++diez, j, i);
			}
			else if (str[j] != '.')
				return (clean_exit(&str));
		}
		ft_memdel((void**)&str);
	}
	ft_memdel((void**)&str);
	return (diez < 3 || i < 3 ? -1 : state);
}

static	int		ft_normalize_pieces(t_map *map, unsigned i)
{
	int		j;
	t_point	min;

	if (!map)
		return (-1);
	while (++i < map->nb)
	{
		j = 0;
		min.x = map->pieces[i][0].x;
		min.y = map->pieces[i][0].y;
		while (++j < 4)
		{
			if (map->pieces[i][j].x < min.x)
				min.x = map->pieces[i][j].x;
			if (map->pieces[i][j].y < min.y)
				min.y = map->pieces[i][j].y;
		}
		j = -1;
		while (++j < 4)
		{
			map->pieces[i][j].x -= min.x;
			map->pieces[i][j].y -= min.y;
		}
	}
	return (1);
}

static	t_map	*ft_map_alloc(t_map **map)
{
	if (!map)
		return (NULL);
	if (!(*map))
	{
		if (!((*map) = malloc(sizeof(t_map))))
			return (NULL);
		if (!((*map)->place = malloc(sizeof(t_point) * 1)))
			return (NULL);
		if (!((*map)->pieces = malloc(sizeof(t_point*))))
			return (NULL);
		if (!((*map)->pieces[0] = malloc(sizeof(t_point) * 4)))
			return (NULL);
		(*map)->nb = 0;
		(*map)->size = 0;
		(*map)->sol = NULL;
	}
	return (*map);
}

static t_map	*ft_map_realloc(t_map **map)
{
	t_map	*new_map;
	int		i;

	i = -1;
	if (!(new_map = malloc(sizeof(t_map))))
		return (NULL);
	if (!(new_map->place = malloc(sizeof(t_point) * ((*map)->nb + 2))))
		return (NULL);
	while (++i < (int)(*map)->nb + 1)
		new_map->place[i] = (*map)->place[i];
	new_map->nb = (*map)->nb + 1;
	if (!(new_map->pieces = malloc(sizeof(t_point*) * (new_map->nb + 1))))
		return (NULL);
	i = -1;
	while (++i < (int)(*map)->nb + 1)
		new_map->pieces[i] = (*map)->pieces[i];
	if (!(new_map->pieces[i] = malloc(sizeof(t_point) * 4)))
		return (NULL);
	new_map->size = (*map)->size;
	free((*map)->pieces);
	free((*map)->place);
	free(*map);
	*map = new_map;
	(*map)->sol = NULL;
	return (*map);
}

t_map			*ft_read_input(char *file)
{
	int		fd;
	t_map	*map;
	int		state;

	map = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(ft_map_alloc(&map)))
		return (NULL);
	while ((state = ft_get_pieces(map, fd, -1, -1)) > 0)
		if (!(ft_map_realloc(&map)))
			return (NULL);
	map->nb += 1;
	if (state != -1)
		ft_normalize_pieces(map, -1);
	if (state == -1 || ft_check_pieces(map) == 0)
	{
		ft_mapdel(&map);
		return (NULL);
	}
	return (map);
}
