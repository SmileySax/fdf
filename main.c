/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:56:29 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:32:56 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *str)
{
	perror(str);
	exit(1);
}

int	ft_exit_x_button(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img);
	exit(1);
}

int	ft_keydealer(int key, t_map *map)
{
	if (key >= 123 && key <= 126)
		ft_shifter(key, map);
	if (key == 49)
		ft_project_changer(map);
	if (key == 30 || key == 33 || key == 6 || key == 7)
		ft_facture_n_zoom_variator(key, map);
	if ((key >= 0 && key <= 2) || (key >= 12 && key <= 14))
		ft_3d(key, map);
	if (key == 48)
		ft_reset(map);
	if (key == 53)
		exit(0);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	ft_draw(map);
	return (0);
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

int	main(int argc, char **argv)
{
	t_map	*map;

	argc++;
	map = ft_parce(argv[1]);
	ft_draw(map);
	mlx_key_hook(map->win_ptr, ft_keydealer, map);
	mlx_hook(map->win_ptr, 17, 0, ft_exit_x_button, map);
	mlx_loop(map->mlx_ptr);
	ft_free_map(map);
	return (0);
}
