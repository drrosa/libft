/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:42:05 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/12 16:21:02 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	compress(const char *str, char **ptr, char c)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i + 1] && str[i] == c)
		{
			i++;
		}
		if (str[i] != c)
			n++;
		if (str[i + 1] == c)
		{
			*ptr = ft_strnew(n);
			while (n)
			{
				**ptr++ = (char)str[i - n--];
			}
			ptr++;
		}
		j++;
		i++;
	}
}

int count(const char *str, char c)
{
	unsigned long i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i + 1] && str[i] == c)
		{
			i++;
		}
		if (str[i] == c)
			j++;
		i++;
	}
	if (i - 1 == ft_strlen(str))
		j = 0;
	return (j);
}

char	*ft_strcleanup(char const *str, char c)
{
	int i;
	int j;
	char *result;

	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(str));
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
			result[j++] = c;
	}
	result[j] = '\0';
	return (result);
}

#include <stdio.h>

char **ft_strsplit(char const *str, char c)
{
	char **ptr = NULL;
	char *temp;
	int size;

	if (!str && !*str)
		return (NULL);

	size = count(str, c);
	ptr = (char **)malloc(sizeof(char *) * (size + 2));
	temp = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr || !*ptr || !temp)
		return (NULL);
	if (size == 0)
	{
		ptr[0] = temp;
		ptr[1] = 0;
		temp[0] = '\0';
		return (ptr);
	}
	//	printf("HERE - size -> %d\n", size);
	compress(str, ptr, c);
	//	printf("%s\n", temp);
	// *ptr = temp;
	return (ptr);
}
