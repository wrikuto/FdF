/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:38:20 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:47 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t	i;
	int		dif;

	i = 0;
	dif = 0;
	while (n--)
	{
		dif = ((unsigned char *)buf1)[i] - ((unsigned char *)buf2)[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (0);
}

// #include<stdio.h>

// int	main(void)
// {
// 	char buf[] = "ABCD5EFGH";
// 	char buf2[] = "ABC123456";

// 	if(ft_memcmp(buf,buf2,3)==0)
// {
// 		puts("先頭から3バイトは一致しています。");
// 	}else{
// 		puts("一致していません。");
// 	}
// 	return (0);
// }
