/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:00:46 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/08 18:41:40 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long i;
	unsigned long j;
	unsigned long n;
	unsigned long dst_length;

	dst_length = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	n = size - dst_length - 1;
	j = dst_length;
	i = 0;
	while (i < n && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (size > ft_strlen(src))
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + dst_length);
}

#include <stdlib.h>
int main()
{
	// char *dst1 = (char *)malloc(sizeof(char)*2);
	//	char *dst2 = (char *)malloc(sizeof(char)*2);
	char * src = "the cake is a lie !\0I'm hidden lol\r\n";
	size_t size = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
	char   dst1[0xF00] = "there is no stars in the sky";
	char   dst2[0xF00] = "there is no stars in the sky";

	printf("strlcat return: %lu\n", strlcat(dst1, src, size));
	printf("ft_strlcat return: %lu\n", ft_strlcat(dst2, src, size));
	printf("dst 1: %s\n", dst1);
	printf("dst 2: %s\n", dst2);
}
