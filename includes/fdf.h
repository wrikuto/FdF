/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:23:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/18 16:27:59 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>


										#include<stdio.h>


# define WIDTH 1080
# define HEIGHT 960
# define cos_30 0.86602540378
# define sin_30 0.52532198881

typedef struct s_line
{
	double	px;
	double	py;
	double	lx;
	double	ly;
	double	dx;
	double	dy;
	size_t	steps;
}				t_line;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	double		iso_x;
	double		iso_y;
	double		screen_x;
	double		screen_y;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	t_point	*point3D;
	double	max_iso_x;
	double	min_iso_x;
	double	max_iso_y;
	double	min_iso_y;
	int		z_max;
	int		z_min;
}				t_map;

// typedef struct s_cam
// {
// 	int		zoom;
// 	double	x_dig;
// 	double	y_dig;
// 	double	z_dig;
// 	float	z_height;
// 	int		x_set;
// 	int		y_set;
// 	int		z_set;
// 	int		iso;
// }				t_cam;

// typedef struct s_bres
// {
// 	double	ex;
// 	double	dx;
// 	double	Dx;
// 	double	xi;
// 	double	ey;
// 	double	dy;
// 	double	Dy;
// 	double	yi;
// }		t_bres;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	t_map		*map;
	// t_cam		*cam;
}				t_fdf;

// check filename and value.
void		error_and_exit(char *str);
void		chk_arg(char *argv);
void		chk_valid(char	*filename);
int			count_col(const char *line, char c);

uint32_t	ft_abs(int num);

uint32_t	ft_hextoi(char *str);

void		get_mapdata(char *filename, t_map *map);

void	trans_data(t_map *map);

void		draw_to_screen(t_fdf *env);

void	draw_line(t_fdf *env);

#endif
