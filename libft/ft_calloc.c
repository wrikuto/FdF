/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:05:09 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 17:21:26 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t		totalsize;
	void		*ptr;

	if (num >= (size_t)SIZE_MAX / 10 + (size_t)(1) && size >= 10)
		return (NULL);
	totalsize = num * size;
	ptr = malloc(totalsize);
	if (ptr != NULL)
		ft_memset(ptr, 0, totalsize);
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	// テストケース1: 正常な値でのテスト
// 	size_t num1 = 5;
// 	size_t size1 = sizeof(int);
// 	int* arr1 = ft_calloc(num1, size1);
// 	if (arr1 != NULL)
// 	{
// 		for (size_t i = 0; i < num1; i++)
// 		{
// 			printf("%d ", arr1[i]);  // ゼロで初期化された配列の要素を表示
// 		}
// 		printf("\n");
// 		free(arr1);
// 	}
// 	// テストケース2: サイズが0の場合
// 	size_t num2 = 10;
// 	size_t size2 = 0;
// 	int* arr2 = ft_calloc(num2, size2);
// 	if (arr2 == NULL)
// 	{
// 		printf("失敗！！\n");
// 	}
// 	// テストケース3: 大きなサイズでのテスト
// 	size_t num3 = 1000000;
// 	size_t size3 = sizeof(char);
// 	char *arr3 = ft_calloc(num3, size3);
// 	if (arr3 != NULL)
// 	{
// 		printf("失敗！！\n");
// 		free(arr3);
// 	}
// 	return (0);
// }
