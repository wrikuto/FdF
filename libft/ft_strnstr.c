/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:23:13 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:45:26 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nedln;

	nedln = ft_strlen(needle);
	if (nedln == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0')
	{
		if (len < nedln)
			break ;
		if (ft_strncmp(haystack, needle, nedln) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// #include<stdio.h>
// int main()
// {
// 	const char *haystack = "Hello, World!";
// 	const char *needle = "World";
// 	char *result = ft_strnstr(haystack, needle, ft_strlen(haystack));
// 	if (result != NULL)
// 	{
// 		printf("一致場所: %ld\n", result - haystack);
// 	}
// 	else
// 	{
// 		printf("ない！\n");
// 	}
// 	return (0);
// }
