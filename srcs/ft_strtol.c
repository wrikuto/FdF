/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:22:36 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/12 18:47:43 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	len_to_space(char *str)
{
	size_t	len;

	if (!str)
		error_and_exit("str is NULL. (at len_to_space)\n");
	while (str[len] != ' ' && str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

uint32_t	atoi_hex(char *str)
{
	uint32_t	num;

	str = str += 2;
	while (*str != ' ')
	{
	if (ft_isdigit(*str))
		num = *str - '0';
	else if (ft_ishex(*str))
		num = hex_to_num(*str);
	}
}