/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:06:21 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 14:28:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	ft_count_digits(int n)
{
	int	num;
	int	i;

	i = 0;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	int	ft_pow(int base, int exp)
{
	int	i;
	int	result;

	result = 1;
	if (base == 0 && exp < 0)
		return (0);
	else
	{
		i = 0;
		while (i < exp)
		{
			result *= base;
			i++;
		}
	}
	return (result);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int		nb;
	int				i;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	i = ft_count_digits(n);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		while (i > 0)
		{
			ft_putchar_fd((nb / ft_pow(10, i - 1)) + '0', fd);
			nb = nb % ft_pow(10, i - 1);
			i--;
		}
	}
}

// int	main(void)
// {
//     int num = -2147483648;
//     int fd = 1;
//     ft_putnbr_fd(num, fd);
//     return 0;
// }
