/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:07:23 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/09 10:28:12 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (1);
}
