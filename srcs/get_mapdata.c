/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:38 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/13 12:21:31 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit("failed open. (at get_height)\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	if (close(fd) == -1)
		error_and_exit("failed close. (at get_height)\n");
	return (height);
}

static int	get_width(char *filename)
{
	int		fd;
	int		width;
	char	*line;

	width = 0;
	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit("failed open. (at get_width)\n");
	line = get_next_line(fd);
	width = count_col(line, ' ');
	free(line);
	if (close(fd) == -1)
		error_and_exit("failed close. (at get_width)\n");
	return (width);
}

// -------------------

static void	store_value(char *line, t_point *point3D, int y)
{
	int		x;

	x = 0;
	while (line[x] != '\n' && line[x] != '\0')
	{
		point3D->x = (double)x;
		point3D->y = (double)y;
		point3D->z = (double)ft_atoi(line[x]);
		while (*line != ',' && *line != ' ')
			line++;
		if (*line == ',')
			point3D->color = ft_hextoi(line);
		else
			point3D->color = 0xFFFFFF;
		while (*line != ' ')
			line++;
		x++;
	}
}

// void	get_zmin_zmax(t_map *map)
// {
// 	t_point	*head;
// 	size_t	len;

// 	head = map->point3D;
// 	len = (map->height * map->width);
// 	while (0 < len)
// 	{
// 		if ((map->point3D->z) < map->z_min)
// 			map->z_min = map->point3D->z;
// 		if (map->z_max < (map->point3D->z))
// 			map->z_max = map->point3D->z;
// 		len--;
// 	}
// }

void	*get_mapdata(char *filename, t_map *map)
{
	int		fd;
	int		y;
	char	*line;


	printf("\n");
	y = 0;
	line = NULL;
	map->height = get_height(filename);
	map->width = get_width(filename);
	fd = open(filename, O_RDONLY);
	map->point3D = malloc (sizeof(t_point) * (map->height * map->width));
	if (map->point3D == NULL || fd == -1)
		error_and_exit("faild malloc or open. (at get_mapdata)\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		store_value(line, map->point3D, y);
		free (line);
		y++;
	}
	if (close(fd) == -1)
		error_and_exit("failed close. (at get_mapdata)\n");
}
