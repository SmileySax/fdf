/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keaton <keaton@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:21:54 by nenvoy            #+#    #+#             */
/*   Updated: 2022/04/02 01:56:50 by keaton           ###   ########.fr       */
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

# define WIDTH			1920
# define HEIGHT			1080

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	1
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	2
# define ANGLE_SIN_UP	3
# define Z_UP			13
# define Z_DOWN			12
# define ISO_ON			18
# define ISO_OFF		19
# define RESET			48

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
	int		win_size[2];
	int		zoom;
	int		color[2][3];
	int		**colors;
	int		min_pt;
	int		max_pt;
	double	angle[2];
	double	angle2[2];
	int		project;
	float	z_adopt;
	int		shift[2];
}	t_map;

/* typedef struct s_fdf {
	int		width;
	int		height;
	t_dot	**matrix;
	int		zoom;
	int		color;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	int		scr_x;
	int		scr_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf; */

int		ft_countwords(char const *s, char c);
t_map	*ft_free_map(t_map *map);
char	**ft_free_tab(char **tab);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, int len);
void	ft_drawline(t_map *map, t_point p1, t_point p2);
int		ft_keydealer(int i, t_map *map);
//float	ft_abs(float n);
float	ft_max(float x, float y);
float	ft_min(float x, float y);
void	ft_draw(t_map *map);

/* void	first_init(t_fdf *data);
void	read_file(char *file, t_fdf *data);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
void	create_line(t_dot start, t_dot end, t_fdf *data);
void	print_menu(t_fdf *data);
void	draw(t_fdf *data, t_dot **matrix);
int		key_hook(int key, t_fdf *data);
void	ft_free(char **arr);
void	ft_bzero(void *str, size_t n);
int		hex_to_dec(char *hex, long long decimal);
void	set_color(t_dot *matrix, char *z);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	init_img(t_fdf *data);
void	isometric(t_dot *start, t_dot *end, t_fdf *data);
void	get_zoom(t_dot *a, t_dot *b, t_fdf *data);
void	get_shift(t_dot *start, t_dot *end, t_fdf *data);
int		error(char *error); */
#endif
