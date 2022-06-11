#include "fdf.h"

void	ft_pixel_to_img(t_map *map, int x, int y, int c)
{
	char	*pos;

	pos = map->img_addr + y * map->size_line + x * (map->bits_per_pixel / 8);
	*(unsigned int *)pos = c;
}

float	ft_abs(float n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

float	ft_min(float x, float y)
{

	if (x < y)
		return (x);
	else
		return (y);
}

float	ft_max(float x, float y)
{

	if (x > y)
		return (x);
	else
		return (y);
}

t_point	ft_pmult(t_point p, int n, float z)
{
	p.x = p.x * n;
	p.y = p.y * n;
	p.z = p.z * n * z;
	return (p);
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
	max = ft_max(fabs(dp.x), fabs(dp.y));
	dp.x /= max;
	dp.y /= max;
	dp.z /= max;
	dp.c[0] /= max;
	dp.c[1] /= max;
	dp.c[2] /= max;
	return (dp);
}

t_point ft_pincr(t_point p, t_point dp)
{
	p.x = p.x + dp.x;
	p.y = p.y + dp.y;
	p.z = p.z + dp.z;
	p.c[0] = p.c[0] + dp.c[0];
	p.c[1] = p.c[1] + dp.c[1];
	p.c[2] = p.c[2] + dp.c[2];
	return (p);
}

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

/* t_point	ft_isometric(t_point p, t_map *map)
{
	if (map->project == 0)
	{
		p.x = (p.x - cos(map->angle2[0]) * p.y) * cos((map->angle)[0]);
		p.y = (cos(map->angle2[0]) * p.x + p.y) * sin((map->angle)[1]) - p.z;
	}
	else
	{
		p.x = p.x;
		p.y = p.y;
	}
	return (p);
} */

t_point	ft_isometric(t_point p, t_map *map)
{
	t_point res;

	res = p;
	if (map->project == 0)
	{
		p = res;
		res.x = cos(map->angle2[0]) * p.x - sin(map->angle2[0]) * p.y;
		res.y = sin(map->angle2[0]) * p.x + cos(map->angle2[0]) * p.y;
		p = res;
		res.y = cos(map->angle[0]) * p.y - sin(map->angle[0]) * p.z;
		res.z = sin(map->angle[0]) * p.y + cos(map->angle[0]) * p.z;
		p = res;
		res.x = cos(map->angle[1]) * p.x + sin(map->angle[1]) * p.z;
		res.z = - sin(map->angle[1]) * p.x + cos(map->angle[1]) * p.z;
//		p.x = 1*res.x - sin(map->angle[0]) * res.y + cos(map->angle[0]) * res.z;
//		p.y = 0*res.x + cos(map->angle[0]) * res.y + sin(map->angle[0]) * res.z;
//		p.y = 1*p.y - sin(map->angle[1]) * p.x - cos(map->angle[1]) * p.z;
//		p.x = 0*p.y + cos(map->angle[1]) * p.x - sin(map->angle[1]) * p.z;
//		res = p;
		// res.x += p.x * (cos(map->angle2[0]) + cos(map->angle[1]));
		// res.x -= p.y * (sin(map->angle2[0]) + sin(map->angle[0]));
		// res.x += p.z * (cos(map->angle[0]) - sin(map->angle[1]));
		// res.y += p.x * (sin(map->angle2[0]) - sin(map->angle[1]));
		// res.y += p.y * (cos(map->angle2[0]) + cos(map->angle[0]));
		// res.y += p.z * (sin(map->angle[0]) - cos(map->angle[1]));
	}
	else
	{
		res.x = p.x;
		res.y = p.y;
	}
	return (res);
}

void	ft_drawline(t_map *map, t_point p1, t_point p2)
{
	int		c;
	t_point	dp;

	p1 = ft_pcentr(p1, map);
	p2 = ft_pcentr(p2, map);
	p1 = ft_pmult(p1, map->zoom, map->z_adopt);
	p2 = ft_pmult(p2, map->zoom, map->z_adopt);
	p1 = ft_isometric(p1, map);
	p2 = ft_isometric(p2, map);
	p1 = ft_pshift(p1, map);
	p2 = ft_pshift(p2, map);
	dp = ft_pdelta(p1, p2);
	while((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		c = (int)p1.c[0] * 256 * 256 + (int)p1.c[1] * 256 + (int)p1.c[2];
		if (p1.x >= 0 && p1.y >= 0 && p1.x <= (map->win_size)[0] && p1.y <= (map->win_size)[1])
			ft_pixel_to_img(map, p1.x, p1.y, c);
		p1 = ft_pincr(p1, dp);
	}
}

void	ft_draw(t_map *map)
{
//	t_point	p1;
//	t_point	p2;
	int	x;
	int	y;
	ft_bzero((void *)map->img_addr, map->win_size[0] * map->win_size[1] * (map->bits_per_pixel / 8));
	y = 0;
	while (y < map->len)
	{
		x = 0;
		while (x < map->wid)
		{
			if (x < map->wid - 1)
				ft_drawline(map, map->points[x][y], map->points[x + 1][y]);
			if (y < map->len - 1)
				ft_drawline(map, map->points[x][y], map->points[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img, 0, 0);
}

