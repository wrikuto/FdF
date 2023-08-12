/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:48:44 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/12 18:41:25 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_and_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit (1);
}

int	ft_ishex(char c)
{
	if (('a' <= c && c <= 'f') || \
	('A' <= c && c <= 'F'))
		return (1);
	return (0);
}

uint32_t	hex_to_num(char	c)
{
	uint32_t	num;

	if (('a' <= c && c <= 'f'))
		num = c - 87;
	else if ('A' <= c && c <= 'F')
		num = c - 55;
	return (num);
}
