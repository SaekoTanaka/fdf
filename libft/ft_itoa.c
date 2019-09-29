/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:01:50 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/10 06:42:43 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		neg;
	size_t	digit;
	char	*s;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 1;
	if (n < 0)
		neg = -1;
	digit = ft_count(n);
	s = ft_strnew(digit);
	if (s == NULL)
		return (NULL);
	n = n * neg;
	while (n > 0)
	{
		s[digit - 1] = n % 10 + '0';
		digit--;
		n = n / 10;
	}
	if (s[0] == '\0')
		s[0] = '-';
	return (s);
}
