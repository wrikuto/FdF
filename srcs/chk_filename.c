/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_filename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:48:24 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/20 14:27:06 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	chk_filename(char *str)
{
	str = ft_strrchr(str, '.');
	if (str != NULL && ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

void	chk_arg(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || chk_filename(argv) == 0)
	{
		close (fd);
		error_and_exit("ERROR: Invaild file name.\n");
	}
	close(fd);
}
