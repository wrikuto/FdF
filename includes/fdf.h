/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:23:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/23 01:14:44 by wrikuto          ###   ########.fr       */
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

# define WIDTH 1280
# define HEIGHT 920
# define RATE 1.3913043478
# define COS_30 0.86602540378
# define SIN_30 0.52532198881

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	size_t	dr;
	size_t	dg;
	size_t	db;
}				t_rgb;

typedef struct s_line
{
	double	px;
	double	py;
	double	lx;
	double	ly;
	double	dx;
	double	dy;
	size_t	lenght;
	int		lred;
	int		lgreen;
	int		lblue;
	double	dred;
	double	dgreen;
	double	dblue;
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
	t_point	*point3d;
	double	max_ix;
	double	min_ix;
	double	max_iy;
	double	min_iy;
	double	d_ix;
	double	d_iy;
}				t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	// int			steep;
	t_map		*map;
}				t_fdf;

void		error_and_exit(char *str);
void		chk_arg(char *argv);
void		chk_valid(char	*filename);
int			count_col(const char *line, char c);
void		put_on_pixel(t_fdf *env, int x, int y, uint32_t color);
uint32_t	ft_abs(int num);
uint32_t	ft_hextoi(char *str);
void		get_mapdata(char *filename, t_map *map);
void		trans_data(t_map *map);
void		draw_to_screen(t_fdf *env);
void		draw_line(t_fdf *env);
int			close_win(void *prm);
int			close_esc(int keycode, t_fdf *env);

#endif
