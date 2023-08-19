/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:29:29 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/19 23:50:20 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	trans_to_iso(t_map *map)
{
	size_t	i;
	t_point	*point;

	point = map->point3D;
	i = 0;
	while (i < (map->height * map->width))
	{
		point[i].iso_x = (point[i].x - point[i].y) * cos_30;
		point[i].iso_y = \
		-(point[i].z * sin_30) + (point[i].x + point[i].y) * sin_30;
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
}

void	trans_data(t_map *map)
{
	size_t	i;
	t_point	*point;
	double	raito;
	double	scale;

	i = 0;
	raito = (double)HEIGHT / WIDTH;
	point = map->point3D;
	trans_to_iso(map);
	get_iso_max(map);
	if (map->max_ix - map->min_ix > ft_abs(map->max_iy - map->min_iy))
		scale = (map->max_ix - map->min_iy) * 1.5;
	else
		scale = (map->max_ix - map->min_iy) * 1.5;
	while (i < (map->height * map->width))
	{
		point[i].screen_x = \
		(((point[i].iso_x + map->max_ix) * (WIDTH / scale )) * raito);

		point[i].screen_y = \
		(point[i].iso_y + ft_abs(map->min_iy) * 1.2) * (HEIGHT / scale );

		i++;
	}
}


// void	trans_data(t_map *map)
// {
// 	size_t	i;
// 	t_point	*point;
// 	double	raito;
// 	double	minimize;

// 	i = 0;
// 	raito = (double)HEIGHT / WIDTH;
// 	point = map->point3D;
// 	trans_to_iso(map);
// 	get_iso_max(map);
// 	if (map->min_iso_y < 0)
// 		minimize = map->max_iso_x / (map->max_iso_x - map->min_iso_y);
// 	else
// 		minimize = 1;
// 		printf("test: %f\n", minimize);
// 	while (i < (map->height * map->width))
// 	{
// 		point[i].screen_x = \
// 		(((point[i].iso_x + map->max_iso_x) * \
// 		(WIDTH / (2 * map->max_iso_x))) * raito) * minimize + 50;
// 		point[i].screen_y = \
// 		(point[i].iso_y + map->max_iso_y) * \
// 		(HEIGHT / (2 * map->max_iso_y)) * minimize - 100;
// 		i++;
// 	}
// }
