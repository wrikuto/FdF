/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:41:07 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:43:43 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				cmp;

	if (!(0 <= c && c <= 255))
	{
		while (c < 0)
			c += 256;
		while (c > 255)
			c -= 256;
	}
	i = 0;
	while (str[i] != '\0')
	{
		cmp = (unsigned char)str[i];
		if (cmp == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	const char *s = "libft-test-tokyo";
// 	char *res;
// 	char *res2;

// 	res = ft_strchr(s, 'i' + 256);
// 	res2 = strchr(s, 'i' + 256);

// 	printf("%s\n", res);
// 	printf("%s\n", res2);

// 	return 0;
// }
