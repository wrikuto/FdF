/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 21:18:19 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/03 20:29:05 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == uc)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// #include<stdio.h>
// int main()
// {
// 	const char *str = "Hello, world!";
// 	char *result = ft_memchr(str, 'o', strlen(str));

// 	if (result != NULL)
// 	{
// 		printf("Character 'o' found at position: %ld\n", result - str);
// 		printf("Substring after 'o': %s\n", result);
// 	}
// 	else
// 	{
// 		printf("Character 'o' not found.\n");
// 	}
// 	return 0;
// }