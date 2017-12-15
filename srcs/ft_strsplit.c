/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:42:05 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/14 00:00:40 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	split(const char *str, char **ptr, char c)
{
	int i;
	int j;
	int n;
	int k;

	i = 0;
	j = 0;
	k = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == c || !str[i + 1])
		{
			n = i - k;
			ptr[j] = ft_strnew(n + 1);
			k = 0;
			while (k < n + 1)
			{
				ptr[j][k] = (char)str[(i - n - 1) + k + 1];
				k++;
			}
			i++;
			k = i + 1;
			j++;
		}
		ptr[j] = 0;
		if(str[i])
			i++;
	}
}

int		ft_strcleanup(char const *str, char *result, char c)
{
	int i;
	int j;
	int wc;

	i = 0;
	j = 0;
	wc = 0;

	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			result[j++] = str[i];
			i++;
		}
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			result[j++] = c;
			wc++;
		}
	}
	result[j] = '\0';
	return (wc + 1);
}

char	**ft_strsplit(char const *str, char c)
{
	char **ptr;
	char *temp;
	int size;
	if (!str)
		return (NULL);
	temp = ft_strnew(ft_strlen(str));
	size = ft_strcleanup(str, temp, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr || !temp)
		return (NULL);
	if (str[0] == '\0' || size == 1)
	{
		ptr[0] = 0;
		return (ptr);
	}
	split(temp, ptr, c);
	int i;
	i = 0;
	return (ptr);
}

// int main()
// {
// 	char * src;
//  src = "      split       this for   me  !       ";
//  	// src = "0 0 0 0 0 0 0 0 0";
// 	char **r = ft_strsplit(src, ' ');
// 	int i;
// 	i = 0;
// 	while(r[i] != '\0')
// 		printf("%s\n", r[i++]);
// }
