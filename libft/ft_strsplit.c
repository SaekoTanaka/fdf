/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:58:50 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/10 06:42:36 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && s[j])
		{
			n = ft_count_letters(s, c, j);
			if (!(split[i] = ft_strsub(&s[j], 0, n)))
				return (NULL);
			i++;
			j = j + n - 1;
		}
		j++;
	}
	split[i] = NULL;
	return (split);
}
