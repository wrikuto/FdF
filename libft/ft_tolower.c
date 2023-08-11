/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:34:04 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:45:26 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}

// #include<stdio.h>

// int main() {
// 	char c = 'A';
// 	int result = ft_tolower(c);
// 	printf("Original character: %c\n", c);
// 	printf("Uppercase character: %c\n", result);
// 	return (0);
// }
