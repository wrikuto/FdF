/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapdata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:12:38 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/12 14:01:35 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *filename)
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

int	get_width(char *filename)
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

// int	*get_pointdata(char *line, int width, int **array)
// {
// 	char	*num;
// 	int		i;

// 	i = 0;
// 	num = ft_split(line, ' ');
// 	while (num != '\0' && i < width)
// 	{

// 	}
// }

t_map	*get_mapdata(char *filename, t_map *map)
{
	int		i;
	int		x;
	int		y;
	char	*line;

	i = 0;
	x = 0;
	y = 0;
	map->height = get_height(filename);
	map->width = get_width(filename);
	map->point3D = malloc (sizeof(t_point) * (map->height * map->width));
	

	return (map);
}
