/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:22 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 12:14:01 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return (c);
}

// #include<stdio.h>
// int main() 
// 	char c = 'a';
// 	int result = ft_toupper(c);
// 	printf("Original character: %c\n", c);
// 	printf("Uppercase character: %c\n", result);
// 	return 0;
// }