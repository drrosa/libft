/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:01:14 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/12 15:42:31 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	int		tmp;

	size = 0;
	tmp = n;
	while (tmp)
	{
		tmp = tmp / 10;
		size++;
	}
	if (n <= 0)
		size++;
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n == -2147483648)
		return (ft_strcpy(result, "-2147483648"));
	if (n < 0)
	{
		result[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		result[--size] = n % 10 + '0';
		n = n / 10;
	}
	return (result);
}
