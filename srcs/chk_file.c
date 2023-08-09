/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:42:19 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/09 17:23:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// count column.
int	count_col(const char *line, char c)
{
	int	i;
	int	new;

	i = 0;
	new = 0;
	if (line == NULL)
		return (0);
	while (*line)
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

//	色情報がある時
int	chk_color_num(char *line)
{
	int	i;

	i = 0;
	line++;
	if (line[0] != '0' || (line[1] != 'x' && line[1] != 'X'))
		error_and_exit("invalid color value.\n");
	line = line + 2;
	while (line[i] != ' ')
	{
		if (ft_isdigit(line[i]) == 0 && !('a' <=line[i] && line[i] <= 'f') && \
		!('A' <=line[i] && line[i] <= 'F'))
			error_and_exit("wrong color value.(expect 0 ~ 9 or a ~ f)\n");
		i++;
		if (6 < i)
			error_and_exit("too many color value.\n");
	}
	return (i + 2);
}

// 	ファイル内の数値が適正かどうかチェック。
void	chk_num(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ' && line[i] != ',')
		{
			if ((line[i] == '-' || line[i] == '+') && ft_isdigit([i + 1]))
				i++;
			if (ft_isdigit(line[i]) == 0 && line[i] != '\n' && line[i] != '\0')
				error_and_exit("value is invalid.(error at chk_num)\n");
			i++;
			if (line[i] == '\n' || line[i] == '\0')
				break ;
		}
		if (line[i] == ',')
		{
			if (line[i - 1] == ' ' || line[i + 1] == ' ')
				error_and_exit("value is invalid.(error at chk_num)\n");
			i = chk_color_num(&line[i]);
		}
	}
}

// カラムの数とデータが適正か同時にチェック
void	chk_file_data(char	*filename)
{
	char	*line;
	int		fd;
	int		first_line_col;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_and_exit("failed open at chk_file_data.\n");
	line = get_next_line(fd);
	chk_num(line);
	first_line_col = count_col(line, ' ');
	printf("gnl 1: %s\n", line);
	free(line);
	while (*line)
	{
		line = get_next_line(fd);
		printf("gnl 2: %s\n", line);
		if (line == NULL)
			break ;
		chk_num(line);
		if (first_line_col != count_col(line, ' '))
			error_and_exit("file data is invalid.\n");
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		error_and_exit("failed close at chk_file_data.\n");
}