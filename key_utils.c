/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:57:34 by keaton            #+#    #+#             */
/*   Updated: 2022/06/16 01:07:40 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_shifter(int key, t_map *map)
{
	if (key == 126)
		map->shift[1] += (int)(map->win_size[1] / 50) + 1;
	else if (key == 125)
		map->shift[1] -= (int)(map->win_size[1] / 50) + 1;
	else if (key == 123)
		map->shift[0] += (int)(map->win_size[0] / 70) + 1;
	else
		map->shift[0] -= (int)(map->win_size[0] / 70) + 1;
}

void	ft_project_changer(t_map *map)
{
	map->project++;
	if (map->project == 3)
		map->project = 0;
}

void	ft_facture_n_zoom_variator(int key, t_map *map)
{
	if (key == 33)
	{
		if (map->zoom > 2)
			map->zoom -= 0.1 * map->zoom;
	}
	else if (key == 30)
	{
		if (map->zoom < 300)
		{
			if (map->zoom < 10)
				map->zoom++;
			map->zoom += 0.11 * map->zoom;
		}
	}
	else if (key == 7)
	{
		if (map->z_adopt < 2.5)
			map->z_adopt += 0.15 * map->z_adopt;
	}
	else
	{
		if (map->z_adopt > 0.01)
			map->z_adopt -= 0.12 * map->z_adopt;
	}
}

void	ft_3d(int key, t_map *map)
{
	if (key == 1)
		map->angle[0] += 0.05;
	else if (key == 13)
		map->angle[0] -= 0.05;
	else if (key == 0)
		map->angle[1] += 0.05;
	else if (key == 2)
		map->angle[1] -= 0.05;
	else if (key == 12)
		map->angle[2] += 0.1;
	else
		map->angle[2] -= 0.1;
}

void	ft_reset(t_map *map)
{
	map->angle[0] = 0.7;
	map->angle[1] = -0.45;
	map->angle[2] = 0.6;
	map->zoom = (int)fminf((map->win_size)[0] / (map->wid)
			/ 1.1, (map->win_size)[1] / (map->len) / 1.1) + 1;
	map->shift[0] = (int)(map->win_size[0] / 2);
	map->shift[1] = (int)(map->win_size[1] / 2);
	map->z_adopt = 0.03 * (map->win_size)[1] / (1
			+ (map->max_pt - map->min_pt)) / map->zoom;
}
