/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:25:21 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 12:25:27 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_set_lst(t_lst *lst, void *data, size_t data_size)
{
	t_lst		*tmp;

	if (!lst)
	{
		if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		lst->data = data;
		lst->data_size = data_size;
		lst->prev = NULL;
		lst->next = NULL;
		return (lst);
	}
	else
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_set_lst(tmp->next, data, data_size);
		(tmp->next->prev) = tmp;
	}
	return (lst);
}
