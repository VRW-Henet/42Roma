/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadrini <dpadrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:42:35 by dpadrini          #+#    #+#             */
/*   Updated: 2022/01/26 15:54:24 by dpadrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;

	if (!*lst || !lst || !del)
		return ;
	while (*lst && lst)
	{
		clear = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = clear;
	}
}
