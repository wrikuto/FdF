/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:46:51 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 17:22:06 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	ft_get_digits(int n)
{
	int	num;
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	num = n;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	char	*ft_enter_num(int n, int digits, char *res)
{
	int		i;

	res[digits] = '\0';
	if (n < 0)
		n = -n;
	i = digits - 1;
	while (i >= 0)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (res);
}

static	char	*ft_intmin(char *res)
{
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	res[11] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			digits;
	int			sign;

	if (n == -2147483648)
	{
		res = malloc(sizeof(char) * 12);
		return (ft_intmin(res));
	}
	sign = 1;
	digits = ft_get_digits(n);
	if (n < 0)
	{
		digits++;
		sign = -1;
	}
	res = malloc(sizeof(char) * (digits + 1));
	if (res == NULL)
		return (NULL);
	res = ft_enter_num(n, digits, res);
	if (n == 0)
		res[0] = '0';
	if (sign == -1)
		res[0] = '-';
	return (res);
}

// #include<stdio.h>

// int	main()
// {
// 	printf("%s\n", ft_itoa(-623));
// 	printf("%s\n", ft_itoa(156));
// 	printf("%s\n", ft_itoa(-0));
// }

// int main()
// {
// 	int num = -2147483648;
// 	char *str = ft_itoa(num);
// 	printf("Number: %d\n", num);
// 	printf("String: %s\n", str);
// 	free(str);  // メモリの解放
// 	return 0;
// }
