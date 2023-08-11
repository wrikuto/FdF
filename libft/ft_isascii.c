/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:12:56 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:57 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int n)
{
	if (0 <= n && n <= 127)
		return (1);
	return (0);
}

// #include <stdio.h>

// int main()
// {
// 	int c0 = 'a';
//     int c1 = '\t';
//     int c2 = 128;

//     printf("isascii('a') = %d\n", ft_isascii(c0));
// 	printf("isascii('\\t') = %d\n", ft_isascii(c1));
//     printf("isascii(128) = %d\n", ft_isascii(c2));

//     return (0);
// }
