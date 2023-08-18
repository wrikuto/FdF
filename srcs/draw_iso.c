/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:06:35 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/18 15:55:00 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trans_to_iso(t_map *map)
{
	size_t	i;
	t_point *point;
	
	point = map->point3D;
	i = 0;
	while  (i < (map->height * map->width))
	{
		point[i].iso_x = (point[i].x - point[i].y) * cos_30;
		point[i].iso_y = -(point[i].z * sin_30) + (point[i].x + point[i].y) * sin_30;
		i++;
	}
}

static void	get_iso_max(t_map *map)
{
	t_point	*point;
	size_t	i;

	point = map->point3D;
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->max_iso_x < point[i].iso_x)
			map->max_iso_x = point[i].iso_x;
		if (map->max_iso_y < point[i].iso_y)
			map->max_iso_y = point[i].iso_y;

		if (point[i].iso_x < map->min_iso_x)
			map->min_iso_x = point[i].iso_x;

		if (point[i].iso_y < map->min_iso_y)
			map->min_iso_y = point[i].iso_y;
			i++;
	}
}

void	trans_data(t_map *map)
{
	size_t	i;
	t_point *point;

	i = 0;
	point = map->point3D;
	trans_to_iso(map);
	get_iso_max(map);
	while  (i < (map->height * map->width))
	{
		point[i].screen_x = \
		((point[i].iso_x + (-(map->min_iso_x))) * (WIDTH / (2 * map->max_iso_x)) / 4) * 3 + 150;
		point[i].screen_y = \
		(point[i].iso_y + map->max_iso_y) * (HEIGHT / (2 * map->max_iso_y)) - 100;
		i++;
	}

}

void	put_on_pixel(t_fdf *env, int x, int y, uint32_t color)
{
	char	*dst;
	dst = env->addr + (y * env->size_line + x * (env->bpp / 8));
	*(uint32_t*)dst = color;
}

void	draw_to_screen(t_fdf *env)
{
	size_t	i;
	t_point	*point;

	i = 0;
	point = env->map->point3D;
	while (i < (env->map->height * env->map->width))
	{
		put_on_pixel(env, (int)point[i].screen_x, (int)point[i].screen_y, point[i].color);
		i++;
	}
}

// -------------------------------------


static void	drawing(t_fdf *env, t_line prm, size_t i)
{
	t_point	*point;
	size_t	count;
	double	x;
	double	y;
	
	point = env->map->point3D;
	count = 0;
	x = prm.px;
	y = prm.py;
	while (count <= prm.steps)
	{
		put_on_pixel(env, round(x), round(y), point[i].color);
		x += prm.dx;
		if (point[i + 1].screen_y < point[i].screen_y)
			y -=prm.dy;
		else
			y += prm.dy;
		count++;
	}
}

static void	draw_to_right(t_fdf *env, t_point *point, size_t i)
{
	t_line	prm;

	prm.px = point[i].screen_x;
	prm.py = point[i].screen_y;
	prm.lx = ft_abs(point[i + 1].screen_x - point[i].screen_x);
	prm.ly = ft_abs(point[i + 1].screen_y - point[i].screen_y);
	if (prm.lx > prm.ly)
		prm.steps = prm.lx;
	else 
		prm.steps = prm.ly;
	prm.dx = prm.lx / prm.steps;
	prm.dy = prm.ly / prm.steps;
	drawing(env, prm, i);
}

// static void	draw_to_under(t_fdf *env, t_point *point, size_t i)


void	draw_line(t_fdf *env)
{
	size_t	i;
	t_map	*map;
	t_point	*point;

	i = 0;
	map = env->map;
	point = env->map->point3D;
	while (i < (map->height * map->width) - 1)
	{
		if (point[i].y == point[i + 1].y && i < (map->width * map->height) - 1)
			draw_to_right(env, point, i);
		if (point[].y != ((i + 1) % WIDTH))
			draw_to_under(env, point, i);
		i++;
	}
}

	// int		steps;
	// int		i;
	// float	x;
	// float	y;

	// if (ft_abs(x1 - x0) > ft_abs(x1 - x0))
	// 	steps = ft_abs(x1 - x0);
	// else
	// 	steps = ft_abs(y1 - y0);
	// while (i <= steps)
	// {
	// 	put_on_pixel();
	// 	i++;
	// }