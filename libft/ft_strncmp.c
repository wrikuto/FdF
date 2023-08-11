/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:17:32 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/03 20:47:33 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n && (s1[i] || s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

// int	main()
// {
// 	ft_strncmp(NULL, "hello", 3);
// }

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
//     char *str0 = "ABC";
//     char *str1 = "ABD";
//     char *str2 = "AAA";
//     char *str3 = "ABCD";
//     char *str4 = "AB";
//     char *str5 = "B";
//     char *str6 = "A";
//     printf("strncmp    : ABC ABD   = %d\n", strncmp(str0, str1, 2));
//     printf("ft_strncmp : ABC ABD   = %d\n\n", ft_strncmp(str0, str1, 2));
//     printf("strncmp    : ABC ABC   = %d\n", strncmp(str0, str0, 2));
//     printf("ft_strncmp : ABC ABC   = %d\n\n", ft_strncmp(str0, str0, 2));
//     printf("strncmp    : ABC: AAA   = %d\n", strncmp(str0, str2, 2));
//     printf("ft_strncmp : ABC: AAA   = %d\n\n", ft_strncmp(str0, str2, 2));
//     printf("strncmp    : ABC: ABCD  = %d\n", strncmp(str0, str3, 2));
//     printf("ft_strncmp : ABC: ABCD  = %d\n\n", strncmp(str0, str3, 2));
//     printf("strncmp    : ABC: AB    = %d\n", strncmp(str0, str4, 2));
//     printf("ft_strncmp : ABC: AB    = %d\n\n", ft_strncmp(str0, str4, 2));
//     printf("strncmp    : ABC: B     = %d\n", strncmp(str0, str5, 2));
//     printf("ft_strncmp : ABC: B     = %d\n\n", ft_strncmp(str0, str5, 2));
//     printf("strncmp    : ABC: A     = %d\n", strncmp(str0, str6, 2));
//     printf("ft_strncmp : ABC: A     = %d\n", ft_strncmp(str0, str6, 2));
//     return 0;
// }
