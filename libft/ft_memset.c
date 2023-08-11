/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:34:32 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:45 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	val;

	p = s;
	val = (unsigned char)c;
	while (n--)
	{
		*p++ = val;
	}
	return (s);
}

// #include <stdio.h>
// int main()
// {
// 	char str[20] = "Hello, World!";
// 	printf("Before memset: %s\n", str);
// 	ft_memset(str, 0, 5);
// 	printf("After memset: %s\n", str);
// 	return 0;
// }
