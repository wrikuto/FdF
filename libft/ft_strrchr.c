/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:55:23 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/03 20:32:32 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	cmp;

	if (!(0 <= c && c <= 255))
	{
		while (c < 0)
			c += 256;
		while (c > 255)
			c -= 256;
	}
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		cmp = (int)str[i];
		if (cmp == c)
			return ((char *)&str[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

// #include<stdio.h>
// int main()
// {
// 	const char *str = "Hello, world!";
// 	int c = 'o';
// 	char *result = ft_strrchr(str, c);
// 	if (result != NULL)
// 	{
// 		printf("Character '%c' found at position: %ld\n", c, result - str);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the string.\n", c);
// 	}
// 	return 0;
// }