/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:52:24 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/08 12:03:55 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	new = ft_lstnew(f(lst)->content, f(lst)->content_size);
	start = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		lst = lst->next;
		new = new->next;
	}
	new->next = NULL;
	return (start);
}
