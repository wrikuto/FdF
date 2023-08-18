/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:06:35 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/18 16:59:14 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	put_on_pixel(t_fdf *env, int x, int y, uint32_t color)
{
	char	*dst;
	dst = env->addr + (y * env->size_line + x * (env->bpp / 8));
	*(uint32_t*)dst = color;
}

static uint32_t	set_color(t_map	*map)
{
	
}

static void	drawing(t_fdf *env, t_line prm, size_t i, size_t next)
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
		if (point[i + next].screen_x < point[i].screen_x)
			x -=prm.dx;
		else
			x += prm.dx;
		if (point[i + next].screen_y < point[i].screen_y)
			y -=prm.dy;
		else
			y += prm.dy;
		count++;
	}
}

static void	set_params(t_fdf *env, t_point *point, size_t i, size_t next)
{
	t_line	prm;

	prm.px = point[i].screen_x;
	prm.py = point[i].screen_y;
	prm.lx = ft_abs(point[i + next].screen_x - point[i].screen_x);
	prm.ly = ft_abs(point[i + next].screen_y - point[i].screen_y);
	if (prm.lx > prm.ly)
		prm.steps = prm.lx;
	else 
		prm.steps = prm.ly;
	prm.dx = prm.lx / prm.steps;
	prm.dy = prm.ly / prm.steps;
	drawing(env, prm, i ,next);
}


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
			set_params(env, point, i, 1);
		if ((i) < map->width * (map->height - 1))
			set_params(env, point, i, map->width);
		i++;
	}
}

// void	draw_to_screen(t_fdf *env)
// {
// 	size_t	i;
// 	t_point	*point;

// 	i = 0;
// 	point = env->map->point3D;
// 	while (i < (env->map->height * env->map->width))
// 	{
// 		put_on_pixel(env, (int)point[i].screen_x, (int)point[i].screen_y, point[i].color);
// 		i++;
// 	}
// }
