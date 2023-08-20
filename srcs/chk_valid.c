/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:42:19 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/20 13:55:10 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_col(const char *line, char c)
{
	int	i;
	int	new;

	i = 0;
	new = 0;
	if (line == NULL)
		return (0);
	while (*line != '\n' && *line != '\0')
	{
		if (*line != c && new == 0)
		{
			new = 1;
			i++;
		}
		else if (*line == c)
			new = 0;
		line++;
	}
	return (i);
}

static int	chk_color_num(char *line)
{
	int	i;

	i = 0;
	line++;
	if (line[0] != '0' || (line[1] != 'x' && line[1] != 'X'))
		error_and_exit("ERROR: Invalid color value.\n");
	line = line + 2;
	while (line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && !('a' <= line[i] && line[i] <= 'f') && \
		!('A' <= line[i] && line[i] <= 'F'))
			error_and_exit("ERROR: Wrong color value.(expect 0~9 or a~f)\n");
		i++;
	}
	if (6 < i)
		error_and_exit("ERROR: Too many color value.\n");
	return (i + 3);
}

static void	chk_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '-' || line[i] == '+')
			i++;
		while (line[i] != ' ' && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == 0 && line[i] != '\n' && line[i] != '\0')
				error_and_exit("ERROR: Value is invalid.(error at chk_num)\n");
			i++;
			if (line[i] == '\n' || line[i] == '\0')
				break ;
		}
		if (line[i] == ',')
		{
			if (line[i - 1] == ' ' || line[i + 1] == ' ')
				error_and_exit("ERROR: Value is invalid.(error at chk_num)\n");
			i = i + chk_color_num(&line[i]);
		}
	}
}

void	chk_valid(char	*filename)
{
	char	*line;
	int		fd;
	int		first_line_col;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit("ERROR: Failed open at chk_file_data.\n");
	line = get_next_line(fd);
	if (line == NULL)
		error_and_exit("ERROR: No value in file.\n");
	chk_value(line);
	first_line_col = count_col(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		chk_value(line);
		if (first_line_col != count_col(line, ' '))
			error_and_exit("ERROR: The number of rows are not equal.\n");
		free(line);
	}
	if (close(fd) == -1)
		error_and_exit("ERROR: Failed close at chk_file_data.\n");
}
