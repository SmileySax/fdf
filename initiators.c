/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:57:24 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:06:09 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_init(t_map *map)
{
	(map->win_size)[0] = 1000;
	(map->win_size)[1] = 1000;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->win_size)[0],
			(map->win_size)[1], "FDF");
	map->img = mlx_new_image(map->mlx_ptr, (map->win_size)[0],
			(map->win_size)[1]);
	map->img_addr = mlx_get_data_addr(map->img, &(map->bits_per_pixel),
			&(map->size_line), &(map->endian));
}

t_map	*ft_map_init(t_map *map)
{
	map = (t_map *)malloc(sizeof(t_map));
	if (map)
	{
		map->len = 0;
		map->wid = 0;
		map->points = NULL;
		ft_img_init(map);
		map->zoom = 0;
		map->angle[0] = 0.7;
		map->angle[1] = -0.45;
		map->angle[2] = 0.6;
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

t_map	*ft_mappoints_init(t_map *map)
{
	int	x;

	map->points = (t_point **)malloc(sizeof(t_point *) * map->wid);
	if (map->points)
	{
		x = 0;
		while (x < map->wid)
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

int	ft_atoi_color(char *str)
{
	int			i;
	long int	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	while (i < 6 && ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F')))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 16 + (str[i++] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 16 + (str[i++] - 'A' + 10);
		else
			res = res * 16 + (str[i++] - '0');
	}
	return (res);
}

void	ft_set_init_color(t_map *map, int x, int y, char *str)
{
	int		i;
	int		color;

	i = 2;
	color = -1;
	if (*str && *(str + 1) == '0' && *(str + 2) == 'x')
	{
		str += 3;
		color = ft_atoi_color(str);
		while (i >= 0)
		{
			(map->points)[x][y].c[i--] = color % 0x100;
			color /= 0x100;
		}
	}
	else
		while (i >= 0)
			(map->points)[x][y].c[i--] = -1;
}
