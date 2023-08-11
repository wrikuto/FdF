/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:35:06 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/05 17:22:09 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	size_t	ft_head(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (set[0] == '\0')
		return (i);
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				break ;
			j++;
			if (set[j] == '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

static	size_t	ft_bottom(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) - 1;
	if (set[0] == '\0')
		return (len);
	while (len - i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[len - i] == set[j])
				break ;
			j++;
			if (set[j] == '\0')
				return (len - i);
		}
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	new_len;
	size_t	i;
	size_t	start;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0' && set[0] == '\0')
		return (ft_strdup(""));
	i = 0;
	start = ft_head(s1, set);
	if (start > ft_bottom(s1, set) || s1[0] == '\0')
		return (ft_strdup(""));
	new_len = ft_bottom(s1, set) - start;
	res = malloc(sizeof(char) * (new_len + 2));
	if (res == NULL)
		return (NULL);
	while (new_len >= i)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// #include<stdio.h>
// int main() {
//     const char *s1 = "\n\n\t    Hello \t  Please\n Trim me !\t\t\t\n   ";
//     const char *set = " \n\t";
//     char *trimmed = ft_strtrim(s1, set);
//     // printf("Original string: %s\n", s1);
//     printf("Trimmed string: [%s]\n", trimmed);
//     // free(trimmed); // メモリ解放
//     return 0;
// }