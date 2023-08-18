/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:48:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/17 20:17:46 by wrikuto          ###   ########.fr       */
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

// int	ft_ishex(char c)
// {
// 	if (('a' <= c && c <= 'f') || \
// 	('A' <= c && c <= 'F'))
// 		return (1);
// 	return (0);
// }
