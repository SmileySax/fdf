/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:56:21 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:50:02 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mapwidlen(char *map_file, t_map **map)
{
	char	*str;
	int		fd;

	fd = open(map_file, O_RDONLY, 0);
	(*map)->len = 0;
	while (get_next_line(fd, &str))
	{
		if (str)
		{
			if (!(*map)->wid)
				(*map)->wid = ft_countwords(str, ' ');
			((*map)->len)++;
			free(str);
		}
	}
	(*map)->zoom = (int)fminf(((*map)->win_size)[0] / ((*map)->wid)
			/ 1.5, ((*map)->win_size)[1] / ((*map)->len) / 1.5) + 1;
	(*map)->shift[0] = (int)((*map)->win_size[0] / 2);
	(*map)->shift[1] = (int)((*map)->win_size[1] / 2);
	close(fd);
}

void	ft_height_and_color_filler(t_map *map, int x, int y, char **map_string)
{
	char	*str;

	str = map_string[x];
	(map->points)[x][y].z = ft_atoi(str);
	(map->points)[x][y].x = x;
	(map->points)[x][y].y = y;
	while (*str != ',' || !(*str))
		str++;
	ft_set_init_color(map, x, y, str);
}

t_map	*ft_fill_ztab(int fd, t_map *map)
{
	int		y;
	int		x;
	char	**map_string;
	char	*str;

	str = NULL;
	y = 0;
	while (get_next_line(fd, &str))
	{
		x = 0;
		map_string = ft_split(str, ' ');
		if (!map_string)
			ft_error("malloc3");
		while (map_string[x] && x < map->wid)
			ft_height_and_color_filler(map, x++, y, map_string);
		y++;
		free(str);
		str = NULL;
		ft_free_tab(map_string);
	}
	if (str)
		free(str);
	ft_set_z_minmax(map);
	return (map);
}

int	ft_color_dc_def(t_map *map, int i)
{
	int	dc;

	if (map->max_pt - map->min_pt)
		dc = ((map->color)[1][i] - (map->color)[0][i])
			/ (map->max_pt - map->min_pt);
	else
		dc = 0;
	return (dc);
}

void	ft_set_color_table(t_map *map)
{
	float	dc[3];
	int		x;
	int		y;
	int		i;

	dc[0] = ft_color_dc_def(map, 0);
	dc[1] = ft_color_dc_def(map, 1);
	dc[2] = ft_color_dc_def(map, 2);
	y = -1;
	while (++y < map->len)
	{
		x = -1;
		while (++x < map->wid)
		{
			i = -1;
			while (++i < 3)
				if ((map->points)[x][y].c[i] < 0)
					(map->points)[x][y].c[i] = (int)((map->color)[0][i]
							+ ((map->points)[x][y].z - map->min_pt) * dc[i]);
		}
	}
}
