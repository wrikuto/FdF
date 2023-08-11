/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:24:42 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

// #include <stdio.h>

// int main() {
// 	char ch1 = 'A';
// 	char ch2 = '$';
// 	char ch3 = '\n';
// 	char ch4 = '^';

// 	printf("Is '%c' printable? %s\n", ch1, ft_isprint(ch1) ? "Yes" : "No");
// 	printf("Is '%c' printable? %s\n", ch2, ft_isprint(ch2) ? "Yes" : "No");
// 	printf("Is '\\n' printable? %s\n", ft_isprint(ch3) ? "Yes" : "No");
// 	printf("Is '%c' printable? %s\n", ch4, ft_isprint(ch4) ? "Yes" : "No");

// 	return 0;
// }
