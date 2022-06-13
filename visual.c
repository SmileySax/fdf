#include "fdf.h"

void	ft_menu(t_map *map)
{
	int		indent;
	void	*m;
	void	*w;

	indent = 1;
	m = map->mlx_ptr;
	w = map->win_ptr;
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Zoom: [ / ]");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Facture: Z / X");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "3d rotation: Q/W/E/A/S/D");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Move: Arrows");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Top View ON/OFF: Space");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Reset: TAB");
	mlx_string_put(m, w, 10, 20 * indent++, 0x94E411, "Exit: ESC");
}

void	ft_pixel_to_img(t_map *map, int x, int y, int c)
{
	char	*pos;

	pos = map->img_addr + y * map->size_line + x * (map->bits_per_pixel / 8);
	*(unsigned int *)pos = c;
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
	ft_menu(map);
}

