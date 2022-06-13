#include "fdf.h"

void	ft_mapwidlen(char *map_file, t_map **map)
{
	char	*str;
	int		fd;

	fd = open(map_file, O_RDONLY, 0);
	(*map)->len = 0;
	while (get_next_line(fd, &str))
		if(str)
		{
			if (!(*map)->wid)
				(*map)->wid = ft_countwords(str, ' ');
			((*map)->len)++;
			free(str);
		}
	(*map)->zoom = (int)fminf(((*map)->win_size)[0] / ((*map)->wid) / 1.1, ((*map)->win_size)[1] / ((*map)->len) / 1.1) + 1;
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

t_map	*ft_fill_ztab(int fd,t_map *map)
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
		while (map_string[x])
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

void	ft_set_color_table(t_map *map)
{
	float	dc[3];
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < 3)
	{
		if (map->max_pt - map->min_pt)
			dc[x] = ((map->color)[1][x] - (map->color)[0][x]) / (map->max_pt - map->min_pt);
		else
			dc[x] = 0;
	}
	y = -1;
	while (++y < map->len)
	{
		x = -1;
		while (++x < map->wid)
		{
			i = -1;
			while (++i < 3)
				if ((map->points)[x][y].c[i] < 0)
					(map->points)[x][y].c[i] = (int)((map->color)[0][i] + ((map->points)[x][y].z - map->min_pt) * dc[i]);
		}
	}
}

t_map	*ft_parce(char *map_file)
{
	int		fd;
	t_map	*map;

	map = NULL;
	map = ft_map_init(map);
	ft_mapwidlen(map_file, &map);
	map = ft_mappoints_init(map);
	fd = open(map_file, O_RDONLY, 0);
	map = ft_fill_ztab(fd, map);
	ft_set_color_table(map);
	close(fd);
	return (map);
}
