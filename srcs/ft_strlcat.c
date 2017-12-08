/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:00:46 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/07 21:39:26 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	n;
	unsigned long	dst_length;

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
