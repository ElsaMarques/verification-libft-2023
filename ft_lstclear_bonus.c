/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-oliv <ede-oliv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:22:06 by ede-oliv          #+#    #+#             */
/*   Updated: 2022/12/20 16:22:06 by ede-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextptr;
	t_list	*ptr;

	ptr = *alst;
	while (ptr)
	{
		nextptr = ptr->next;
		ft_lstdelone(&ptr, del);
		ptr = nextptr;
	}
	*alst = NULL;
}
