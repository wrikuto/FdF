/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:48:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/19 02:10:52 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_and_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit (1);
}

uint32_t	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return num;
}

void	put_on_pixel(t_fdf *env, int x, int y, uint32_t color)
{
	char	*dst;

	dst = env->addr + (y * env->size_line + x * (env->bpp / 8));
	*(uint32_t *)dst = color;
}

// int	ft_ishex(char c)
// {
// 	if (('a' <= c && c <= 'f') || \
// 	('A' <= c && c <= 'F'))
// 		return (1);
// 	return (0);
// }
