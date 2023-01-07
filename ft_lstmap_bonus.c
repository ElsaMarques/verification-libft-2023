/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-oliv <ede-oliv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:43:34 by ede-oliv          #+#    #+#             */
/*   Updated: 2022/12/20 23:43:34 by ede-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	if (!newlist)
		return (NULL);
	head = newlist;
	while (lst->next)
	{
		lst = lst->next;
		newlist->next = f(lst);
		if (!newlist->next)
		{
			free(newlist);
			newlist = NULL;
			return (NULL);
		}
		newlist = newlist->next;
	}
	return (head);
}
