/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:14:51 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/11 20:42:56 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// int main() {
// 	char ch1 = '9';
// 	char ch2 = 'A';

// 	if (ft_isdigit(ch1))
// 	{
// 		printf("%c is a digit\n", ch1);
// 	} else
// 	{
// 		printf("%c is not a digit\n", ch1);
// 	}

// 	if (ft_isdigit(ch2))
// 	{
// 		printf("%c is a digit\n", ch2);
// 	} else
// 	{
// 		printf("%c is not a digit\n", ch2);
// 	}

// 	return (0);
// }
