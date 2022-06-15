/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:58:49 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:50:31 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		map->z_adopt = 0.03 * (map->win_size)[1] / (1
				+ (map->max_pt - map->min_pt)) / map->zoom;
	}
}

void	ft_bzero(void *str, size_t n)
{
	while (n > 0)
		*(unsigned char *)(str + --n) = '\0';
}

char	**ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (NULL);
}

t_map	*ft_free_map(t_map *map)
{
	int	x;

	x = 0;
	if (map->points)
	{
		while ((map->points)[x] && x < map->wid)
			free((map->points)[x++]);
		free((map->points));
	}
	free(map);
	return (NULL);
}

t_point	ft_pmult(t_point p, int n, float z)
{
	p.x = p.x * n;
	p.y = p.y * n;
	p.z = p.z * n * z;
	return (p);
}
