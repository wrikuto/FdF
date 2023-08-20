/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:29:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/20 14:57:02 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trans_to_iso(t_map *map)
{
	size_t	i;
	t_point	*point;

	point = map->point3d;
	i = 0;
	while (i < (map->height * map->width))
	{
		point[i].iso_x = (point[i].x - point[i].y) * COS_30;
		point[i].iso_y = \
		-(point[i].z * SIN_30) + (point[i].x + point[i].y) * SIN_30;
		i++;
	}
}

static void	get_iso_max(t_map *map)
{
	t_point	*point;
	size_t	i;

	point = map->point3d;
	i = 0;
	while (i < (map->height * map->width))
	{
		if (map->max_ix < point[i].iso_x)
			map->max_ix = point[i].iso_x;
		if (map->max_iy < point[i].iso_y)
			map->max_iy = point[i].iso_y;
		if (point[i].iso_x < map->min_ix)
			map->min_ix = point[i].iso_x;
		if (point[i].iso_y < map->min_iy)
			map->min_iy = point[i].iso_y;
			i++;
	}
	map->d_ix = map->max_ix + fabs(map->min_ix);
	map->d_iy = map->max_iy + fabs(map->min_iy);
}

void	trans_data(t_map *map)
{
	size_t	i;
	t_point	*point;
	double	scale;
	double	px_max;
	double	py_max;

	i = 0;
	point = map->point3d;
	trans_to_iso(map);
	get_iso_max(map);
	px_max = ((map->d_ix) * (WIDTH / (map->d_ix)));
	py_max = (((map->d_iy) * (HEIGHT / (map->d_iy))) * RATE);
	if (py_max <= HEIGHT && px_max - 1 <= WIDTH)
		scale = (map->d_ix);
	else
		scale = (map->d_iy) * 1.75;
	while (i < (map->height * map->width))
	{
		point[i].screen_x = \
		(((point[i].iso_x + fabs(map->min_ix)) * (WIDTH / scale)));
		point[i].screen_y = \
		((point[i].iso_y + fabs(map->min_iy)) * (HEIGHT / scale)) * RATE + 50;
		i++;
	}
}
