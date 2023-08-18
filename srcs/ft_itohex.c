/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:17:22 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/18 18:28:01 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*itohex(uint32_t num)
{
	size_t		i;
	uint32_t	count_num;
	char		*hex;

	i = 0;
	count_num = num;
	while (count_num != 1)
	{
		count_num = count_num / 16;
		i++;
	}
	while (num != 0)
	{
		
	}
}