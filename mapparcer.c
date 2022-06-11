#include "fdf.h"

int	ft_keydealer(int key, t_map *map)
{
	printf("%d\n",key);
	if (key == 125)
	{
		map->shift[1] += (int)(map->win_size[1] / 50) + 1;
		printf("shifty = %d", map->shift[1]);
	}
	if (key == 126)
	{
		map->shift[1] -= (int)(map->win_size[1] / 50) + 1;
		printf("shifty = %d", map->shift[1]);
	}
	if (key == 124)
	{
		map->shift[0] += (int)(map->win_size[0] / 70) + 1;
		printf("shiftx = %d", map->shift[0]);
	}
	if (key == 123)
	{
		map->shift[0] -= (int)(map->win_size[0] / 70) + 1;
		printf("shiftx = %d", map->shift[0]);
	}
	if (key == 49)
		map->project++;
	if (map->project == 2)
		map->project = 0;
	if (key == 33)
	{
		if (map->zoom > 3)
			map->zoom -= 0.1 * map->zoom;
		printf("zoom = %d", map->zoom);
	}
	if (key == 30)
	{
		if (map->zoom < 10)
			map->zoom++;
		map->zoom += 0.11 * map->zoom;
		printf("zoom = %d", map->zoom);
	}
	if (key == 6)
	{
		map->z_adopt += 0.15 * map->z_adopt;
		printf("z_adopt = %f", map->z_adopt);
	}
	if (key == 7)
	{
		map->z_adopt -= 0.12 * map->z_adopt;
		printf("z_adopt = %f", map->z_adopt);
	}
	if (key == 5)
	{
		map->angle[0] += 0.05;
		printf("angle[0] = %f", map->angle[0]);
	}
	if (key == 4)
	{
		map->angle[0] -= 0.05;
		printf("angle[0] = %f", map->angle[0]);
	}
	if (key == 13)
	{
		map->angle[1] += 0.05;
//		map->angle[0] -= 0.05;
//		printf("angle[0] = %f", map->angle[0]);
		printf("angle[1] = %f", map->angle[1]);
	}
	if (key == 1)
	{
		map->angle[1] -= 0.05;
//		map->angle[0] += 0.05;
//		printf("angle[0] = %f", map->angle[0]);
		printf("angle[1] = %f", map->angle[1]);
	}
	if (key == 12)
	{
		map->angle2[0] += 0.1;
		printf("angle2[0] = %f", map->angle2[0]);
	}
	if (key == 14)
	{
		map->angle2[0] -= 0.1;
		printf("angle2[0] = %f", map->angle2[0]);
	}
	if (key == 0)
	{
		map->angle2[1] += 0.1;
		printf("angle2[1] = %f", map->angle2[1]);
	}
	if (key == 2)
	{
		map->angle2[1] -= 0.1;
		printf("angle2[1] = %f", map->angle2[1]);
	}
	if (key == 53)
		exit(0);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	return (0);
}

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

void	ft_print(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	printf("len = %d, wid = %d\n", map->len, map->wid);
//	printf("zoom = %d, dc = %d\n", map->zoom, map->dc);
	printf("min = %d, max = %d\n", map->min_pt, map->max_pt);
	while (y < map->len)
	{
		x = 0;
		while (x < 20)//map->wid)
		{
			printf("%.0f", (map->points)[x][y].z);//, (map->points)[x][y].x, (map->points)[x][y].y);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_img_init(t_map *map)
{
	(map->win_size)[0] = 1000;
	(map->win_size)[1] = 1000;
	map->mlx_ptr = mlx_init();;
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->win_size)[0], (map->win_size)[1], "FDF");
	map->img = mlx_new_image(map->mlx_ptr, (map->win_size)[0], (map->win_size)[1]);
	map->img_addr = mlx_get_data_addr(map->img, &(map->bits_per_pixel), &(map->size_line), &(map->endian));
}

t_map *ft_map_init(t_map *map)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		map->len = 0;
		map->wid = 0;
		map->points = NULL;
		ft_img_init(map);
		map->zoom = 0;
		map->angle[0] = -0.9;
		map->angle[1] = -0.9;
		map->angle2[0] = 0.2;
		map->angle2[1] = 0.7;
		(map->color)[0][0] = 0xff;
		(map->color)[0][1] = 0xff;
		(map->color)[0][2] = 0xff;
		(map->color)[1][0] = 0x94;
		(map->color)[1][1] = 0x00;
		(map->color)[1][2] = 0xd3;
		map->project = 0;
	}
	else
		ft_error("malloc_map");
	return (map);
}

t_map *ft_mappoints_init(t_map *map)
{
	int	x;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->wid);
	if (map->points)
	{
		x = 0;
		while(x < map->wid)
		{
			(map->points)[x] = (t_point *)malloc(sizeof(t_point) * map->len);
			if (!(map->points)[x++])
				return (ft_free_map(map));
		}
	}
	else
		ft_error("malloc_points");
	return (map);
}

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
	(*map)->zoom = (int)ft_min(((*map)->win_size)[0] / ((*map)->wid) / 1.1, ((*map)->win_size)[1] / ((*map)->len) / 1.1) + 1;
	(*map)->shift[0] = (int)((*map)->win_size[0] / 2);
	(*map)->shift[1] = (int)((*map)->win_size[1] / 2);
	close(fd);
}

void	ft_set_z_minmax(t_map *map)
{
	int	x;
	int	y;

	if (map)
	{
		map->min_pt = (map->points)[0][0].z;
		map->max_pt = (map->points)[0][0].z;
		y = 0;
		while (y < map->len)
		{
			x = 0;
			while (x < map->wid)
			{
				if ((map->points)[x][y].z < map->min_pt)
					map->min_pt = (map->points)[x][y].z;
				if ((map->points)[x][y].z > map->max_pt)
					map->max_pt = (map->points)[x][y].z;
				x++;
			}
			y++;
		}
		map->z_adopt = 0.03 * (map->win_size)[1] / (1 + (map->max_pt - map->min_pt)) / map->zoom;
	}
}

t_map	*ft_fill_ztab(int fd,t_map *map, char *str)
{
	int		y;
	int		x;
	char	**map_string;

	y = 0;
	while (get_next_line(fd, &str))
	{
		x = 0;
		map_string = ft_split(str, ' ');
//		printf("%s", map_string[13]);
		if (!map_string)
			ft_error("malloc3");
		while (map_string[x])
		{
//			printf("%s", str[x]);
			(map->points)[x][y].z = ft_atoi(map_string[x]);
			(map->points)[x][y].x = x;
			(map->points)[x][y].y = y;
			x++;
		}
		y++;
		free(str);
		ft_free_tab(map_string);
	}
	ft_set_z_minmax(map);
	return (map);
}

void	ft_set_color_table(t_map *map)
{
	float	dc[3];
	float	dz;
	int		x;
//	int		z;
	int		y;
	int		i;

//	z = -1;
	dz = (map->max_pt - map->min_pt);
	/* map->colors = (int**)malloc(sizeof(int*) * dz);
	if (!map->colors)
		perror("malloc color");
	while (++z < dz)
	{
		map->colors[z] = (int*)malloc(sizeof(int) * 3);
		if (!map->colors[z])
			perror("malloc color");
	} */
	x = -1;
	while (++x < 3)
	{
		if (dz)
			dc[x] = ((map->color)[1][x] - (map->color)[0][x]) / dz;
		else
			dc[x] = 0;
	}
//	printf("dc = %f, dz = %f - ", dc[x - 1], dz);
//	z = map->min_pt;
	y = -1;
	while (++y < map->len)
	{
		x = -1;
		while (++x < map->wid)
		{
			i = -1;
			while (++i < 3)
				(map->points)[x][y].c[i] = (int)((map->color)[0][i] + ((map->points)[x][y].z - map->min_pt) * dc[i]);
//			printf("c = %d, z = %f, dc = %f, %f, %f\n", (map->points)[x][y].c[i - 1], (map->points)[x][y].z - map->min_pt, dc[0], dc[1], dc[2]);
		}
	}
//	printf("z = %d, dz = %f\n", z, dz);
	/* while (--z > map->min_pt * map->zoom)
	{
		i = -1;
		while (++i < 3)
			(map->colors)[z][i] = (map->color)[1][i] + (int)(dc[i] * (map->max_pt - z * map->zoom));
	} */
}

t_map	*ft_parce(char *map_file)
{
	int		fd;
	t_map	*map;
	char	*str;

	map = NULL;
	str = NULL;
	map = ft_map_init(map);
	ft_mapwidlen(map_file, &map);
	map = ft_mappoints_init(map);
	fd = open(map_file, O_RDONLY, 0);
	map = ft_fill_ztab(fd, map, str);
//	ft_print(map);
	ft_set_color_table(map);
//	printf("here\n");
//	int i = -1;
//	while (++i < 256)
//		printf("c1 = %d, c2 = %d, c3 = %d\n", (map->colors)[i][0], (map->colors)[i][1], (map->colors)[i][2]);
//	printf("%d-%p\n", fd, map);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	argc++;
	map = ft_parce(argv[1]);
	ft_draw(map);
	mlx_key_hook(map->win_ptr, ft_keydealer, map);
	mlx_loop(map->mlx_ptr);
	ft_free_map(map);
	return (0);
}
