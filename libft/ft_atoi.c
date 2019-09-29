/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:42:40 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/10 06:47:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					n;
	long long unsigned	sum;
	long long unsigned	range;

	range = 9223372036854775807;
	str = ft_is_space(str);
	n = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	sum = 0;
	while (ft_isdigit(*str) == 1)
	{
		sum = *str++ - 48 + sum * 10;
	}
	if (n == -1 && sum > range + 1)
		return (0);
	if (n == 1 && sum > range)
		return (-1);
	return (sum * n);
}
