/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:37:34 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 17:21:42 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	malloc_size;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		malloc_size = ft_strlen(s) - start;
	if (ft_strlen(s) - start >= len)
		malloc_size = len;
	res = malloc(sizeof(char) * (malloc_size + 1));
	if (res == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		if (s[start + i] == '\0')
			break ;
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "Hello, world!";
// 	unsigned int start = 7;
// 	size_t len = 5;
// 	char *substr = ft_substr(s, start, len);
// 	if (substr == NULL) {
// 		printf("Substring allocation failed.\n");
// 		return 1;
// 	}
// 	printf("Original string: %s\n", s);
// 	printf("Substring: %s\n", substr);
// 	free(substr);
// 	return 0;
// }