/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:25:05 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 18:23:55 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_set_list(t_list *lst, void *content, size_t size)
{
	t_list		*tmp;

	if (!lst)
	{
		if (!(lst = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		lst->content = content;
		lst->content_size = size;
		lst->next = NULL;
		return (lst);
	}
	else
	{
		tmp = lst;
		while (lst->next)
			lst = lst->next;
		lst->next = ft_set_list(lst->next, content, size);
	}
	return (tmp);
}
