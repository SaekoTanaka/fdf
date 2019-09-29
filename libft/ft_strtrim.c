/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:58:27 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/09 10:26:19 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	l;
	char	*new;
	char	*p;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	l = ft_strlen(s);
	if (l > 0)
	{
		while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
			l--;
	}
	new = ft_strnew(l);
	if (new == NULL)
		return (NULL);
	p = new;
	while (l-- > 0)
		*new++ = *(char*)s++;
	*new = '\0';
	return (p);
}
