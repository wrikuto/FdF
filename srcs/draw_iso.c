/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:06:35 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/14 21:13:31 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trans_to_iso(t_map *map)
{
	int	i;
	t_point *point;
	
	point = map->point3D;
	i = 0;
	while  (i < (map->height * map->width))
	{
		point[i].iso_x = (point[i].x - point[i].y) * cos_30;
		point[i].iso_y = -point[i].z + (point[i].x + point[i].y) * sin_30;
		i++;
	}
}

static void	get_iso_max(t_map *map)
{
	t_point *point;
	int		i;

	point = map->point3D;
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->max_iso_x < point[i].iso_x)
			map->max_iso_x = point[i].iso_x;
		if (map->max_iso_y < point[i].iso_y)
			map->max_iso_y = point[i].iso_y;
			i++;
	}
	printf("\niso_max:  %f\n\n", map->max_iso_x);
}
void	trans_data(t_map *map)
{
	int	i;
	t_point *point;

	i = 0;
	point = map->point3D;
	trans_to_iso(map);
	get_iso_max(map);
	while  (i < (map->height * map->width))
	{
		point[i].screen_x = \
		(point[i].iso_x + map->max_iso_x) * (WIDTH / (2 * map->max_iso_x));
		point[i].screen_y = \
		(point[i].iso_y + map->max_iso_y) * (HEIGHT / (2 * map->max_iso_y));
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
	int		i;
	t_point	*point;

	i = 0;
	point = env->map->point3D;
	printf("\nTEST_draw: %u\n", point[i].color);
	while (i < (env->map->height * env->map->width) - 1)
	{
		put_on_pixel(env, (int)point[i].screen_x, (int)point[i].screen_y, point[i].color);
		i++;
	}
}