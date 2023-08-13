/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:23:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/13 16:16:00 by wrikuto          ###   ########.fr       */
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


										#include<stdio.h>


# define WIDTH 1280
# define HEIGHT 720

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	*point3D;
	int		z_max;
	int		z_min;
}				t_map;

typedef struct s_cam
{
	int		zoom;
	double	x_dig;
	double	y_dig;
	double	z_dig;
	float	z_height;
	int		x_set;
	int		y_set;
	int		z_set;
	int		iso;
}				t_cam;

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


// int			get_height(char *filename);
// int			get_width(char *filename);

uint32_t	ft_hextoi(char *str);

void	get_mapdata(char *filename, t_map *map);

#endif
