/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:23:05 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:58 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if (('0' <= n && n <= '9') || \
		(('A' <= n && n <= 'Z') || ('a' <= n && n <= 'z')))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main() {
//     char c1 = 'a';
//     char c2 = '1';
//     char c3 = '!';
//     printf("isalnum('a') = %d\n", ft_isalnum(c1));
//     printf("isalnum('1') = %d\n", ft_isalnum(c2));
//     printf("isalnum('!') = %d\n", ft_isalnum(c3));
//     return 0;
// }
