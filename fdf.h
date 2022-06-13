/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:21:54 by nenvoy            #+#    #+#             */
/*   Updated: 2022/06/11 18:58:04 by keaton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	short	c[3];
}	t_point;

typedef struct s_map
{
	int		wid;
	int		len;
	t_point	**points;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*img_addr;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		win_size[2];
	int		zoom;
	int		color[2][3];
	int		**colors;
	int		min_pt;
	int		max_pt;
	double	angle[3];
	int		project;
	float	z_adopt;
	int		shift[2];
}	t_map;

int		ft_countwords(char const *s, char c);
t_map	*ft_free_map(t_map *map);
char	**ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
void	ft_drawline(t_map *map, t_point p1, t_point p2);
int		ft_keydealer(int i, t_map *map);
void	ft_draw(t_map *map);
void	ft_bzero(void *str, size_t n);
t_point	ft_pshift(t_point p, t_map *map);
t_point	ft_pcentr(t_point p, t_map *map);
t_point	ft_isometric(t_point p, t_map *map);
t_point	ft_nullify_point(t_point dp);
t_point	ft_pdelta(t_point p1, t_point p2);
t_point	ft_pmult(t_point p, int n, float z);
void	ft_set_z_minmax(t_map *map);
void	ft_img_init(t_map *map);
t_map *ft_map_init(t_map *map);
t_map *ft_mappoints_init(t_map *map);
int		ft_atoi_color(char *str);
void	ft_set_init_color(t_map *map, int x, int y, char *str);
void	ft_shifter(int key, t_map *map);
void	ft_project_changer(t_map *map);
void	ft_facture_n_zoom_variator(int key, t_map *map);
void	ft_3d(int key, t_map *map);
void	ft_reset(t_map *map);
void	ft_error(char *str);
t_map	*ft_parce(char *map_file);

#endif
