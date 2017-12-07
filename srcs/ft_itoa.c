/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:01:14 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/06 22:39:49 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = n;
	i = 0;
	if (n <= 0)
		i = 1;
	while (tmp != 0)
	{
		tmp = tmp / 10;
		i++;
	}
	str = (char *)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	if (n == '\0' || n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[i] = '\0';
	i--;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
