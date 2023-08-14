/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:38 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/14 14:53:35 by wrikuto          ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
	if (close(fd) == -1)
		error_and_exit("failed close. (at get_width)\n");
	return (width);
}

// -------------------------------------

static void	store_value(char *line, t_map *map, int y)
{
	int			x;
	static int	s_i = 0;

	x = 0;
	while (x < map->width)
	{
		while (*line == ' ')
			line++;
		map->point3D[s_i].x = (double)x;
		map->point3D[s_i].y = (double)y;
		map->point3D[s_i].z = (double)ft_atoi(line);
		while (*line != ',' && *line != ' ' && *line != '\n' && *line != '\0')
			line++;
		if (*line == ',')
			map->point3D[s_i].color = ft_hextoi(line);
		else
			map->point3D[s_i].color = 0xFFFFFF;
		while (*line != ' ' && *line != '\n' && *line != '\0')
			line++;
		x++;
		s_i++;
	}
}

void	get_zmin_zmax(t_map *map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = (map->height * map->width);
	while (0 < len)
	{
		if ((map->point3D[i].z) < map->z_min)
			map->z_min = map->point3D[i].z;
		if (map->z_max < (map->point3D[i].z))
			map->z_max = map->point3D[i].z;
		i++;
		len--;
	}
}

void	get_mapdata(char *filename, t_map *map)
{
	int		fd;
	int		y;
	char	*line;

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
		store_value(line, map, y);
		free (line);
		y++;
	}
	get_zmin_zmax(map);
	if (close(fd) == -1)
		error_and_exit("failed close. (at get_mapdata)\n");
}
