/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:48:24 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/08 21:26:27 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	chk_filename(char *str)
{
	str = ft_strrchr(str, '.');
	if (ft_strncmp(str, ".fdf", 5) == 0)
		return (1);
	return (0);
}

// check argment and name.
void	chk_arg(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0 || chk_filename(argv) == 0)
	{
		close (fd);
		write(1, "invaild file name.\n", 19);
		exit (1);
	}
	close(fd);
}
