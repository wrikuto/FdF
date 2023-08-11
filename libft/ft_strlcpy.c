/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:15:26 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:45:26 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size != 0)
	{
		i = 0;
		while ((i < (size - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

// #include <stdio.h>
// int    main(void)
// {
//     int    len;
//     char str[] = "abcdefg";
//     char buffer[20];
//     len = ft_strlcpy(buffer, str, 12);
//     printf("%d\n", len);
//     printf("%s\n", str);
//     printf("%s\n", buffer);
//     return (0);
// }
