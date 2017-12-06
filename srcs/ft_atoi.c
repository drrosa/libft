/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:10:42 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/12/05 21:40:48 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int i;
	int sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' ||
			str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
	{
		if (str[i++] == '-')
		{
			sign = -1;
			break ;
		}
	}
	while (str[i])
	{
		if (str[i] - '0' < 0 || str[i] - '0' > 9)
			break ;
		result = result * 10 + str[i++] - '0';
	}
	return (result * sign);
}
