/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:54:13 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:01:29 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_pshift(t_point p, t_map *map)
{
	p.x += map->shift[0];
	p.y += map->shift[1];
	return (p);
}

t_point	ft_pcentr(t_point p, t_map *map)
{
	p.x -= map->wid / 2;
	p.y -= map->len / 2;
	return (p);
}

t_point	ft_isometric(t_point p, t_map *map)
{
	t_point	res;

	res = p;
	if (map->project == 2)
	{
		res.x = cos(map->angle[2]) * p.x - sin(map->angle[2]) * p.y;
		res.y = sin(map->angle[2]) * p.x + cos(map->angle[2]) * p.y;
		p = res;
		res.y = cos(map->angle[0]) * p.y - sin(map->angle[0]) * p.z;
		res.z = sin(map->angle[0]) * p.y + cos(map->angle[0]) * p.z;
		p = res;
		res.x = cos(map->angle[1]) * p.x + sin(map->angle[1]) * p.z;
		res.z = -sin(map->angle[1]) * p.x + cos(map->angle[1]) * p.z;
	}
	else if (map->project == 1)
	{
		res.x = p.x;
		res.y = p.y;
	}
	else
	{
		res.x = (p.x - p.y) * cos(map->angle[1]);
		res.y = (p.x + p.y) * sin(map->angle[0]) - p.z;
	}
	return (res);
}

t_point	ft_nullify_point(t_point dp)
{
	dp.x = 0;
	dp.y = 0;
	dp.z = 0;
	dp.c[0] = 0;
	dp.c[1] = 0;
	dp.c[2] = 0;
	return (dp);
}

t_point	ft_pdelta(t_point p1, t_point p2)
{
	t_point	dp;
	int		max;

	dp.x = p2.x - p1.x;
	dp.y = p2.y - p1.y;
	dp.z = p2.z - p1.z;
	dp.c[0] = p2.c[0] - p1.c[0];
	dp.c[1] = p2.c[1] - p1.c[1];
	dp.c[2] = p2.c[2] - p1.c[2];
	max = (int)fmaxf(fabsf(dp.x), fabsf(dp.y));
	if (max)
	{
		dp.x /= max;
		dp.y /= max;
		dp.z /= max;
		dp.c[0] /= max;
		dp.c[1] /= max;
		dp.c[2] /= max;
	}
	else
		return (ft_nullify_point(dp));
	return (dp);
}
