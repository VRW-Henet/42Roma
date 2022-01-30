/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:14:44 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/29 17:20:54 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!(new))
		return (0);
	newlst = new;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!(new))
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, new);
	}
	return (newlst);
}
