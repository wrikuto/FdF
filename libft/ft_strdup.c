/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:46:07 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 18:59:00 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s2 = malloc(sizeof(char) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// #include <stdio.h>

// int main() 
// {
// 	const char *str = "Hello world!";
// 	char *str_copy = ft_strdup(str);

// 	if (str_copy != NULL) {
// 		printf("コピーした文字列: %s\n", str_copy);
// 		free(str_copy);  // 動的に割り当てられたメモリを解放
// 	} else {
// 		printf("メモリの割り当てエラー\n");
// 	}

// 	return 0;
// }