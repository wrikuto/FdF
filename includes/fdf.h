/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:23:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/08 21:28:23 by wrikuto          ###   ########.fr       */
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
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

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
	int	height;
	int	width;
	int	***array;
	int	z_max;
	int	z_min;
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
	char		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			steep;
	// t_map		*map;
	// t_cam		*cam;
}				t_fdf;

// check filename and value.
void	error_and_exit(char *str);
void	chk_arg(char *argv);
void	chk_file_data(char	*filename);


#endif