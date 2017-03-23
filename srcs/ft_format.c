/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:10:33 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 15:24:27 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris	*ft_set_t_tris(t_tris *lst, char alpha)
{
	if (!lst)
	{
		if (!(lst = (t_tris*)malloc(sizeof(t_tris))))
			return (NULL);
		lst->prev = NULL;
		lst->next = NULL;
		lst->alpha = alpha;
		return (lst);
	}
	else
	{
		while (lst->next)
			lst = lst->next;
		if (!(lst->next = ft_set_t_tris(lst->next, alpha)))
			return (NULL);
		lst->next->prev = lst;
		lst = lst->next;
	}
	return (lst);
}

void	ft_copy_stock_coor(t_tris **lst, t_stk **stk, char **tab)
{
	if (tab[(*stk)->y][(*stk)->x] == '#')
		(*stk)->hash++;
	if (tab[(*stk)->y][(*stk)->x] == '#' && (*stk)->hash == 1)
	{
		(*lst)->x_0 = (*stk)->x;
		(*lst)->y_0 = (*stk)->y;
	}
	if (tab[(*stk)->y][(*stk)->x] == '#' && (*stk)->hash == 2)
	{
		(*lst)->x_1 = (*stk)->x - (*lst)->x_0;
		(*lst)->y_1 = (*stk)->y - (*lst)->y_0;
	}
	if (tab[(*stk)->y][(*stk)->x] == '#' && (*stk)->hash == 3)
	{
		(*lst)->x_2 = (*stk)->x - (*lst)->x_0;
		(*lst)->y_2 = (*stk)->y - (*lst)->y_0;
	}
	if (tab[(*stk)->y][(*stk)->x] == '#' && (*stk)->hash == 4)
	{
		(*lst)->x_3 = (*stk)->x - (*lst)->x_0;
		(*lst)->y_3 = (*stk)->y - (*lst)->y_0;
	}
}

void	ft_stock_coord(t_tris **lst, char **tab)
{
	t_stk	*stk;

	if (!(stk = (t_stk*)malloc(sizeof(t_stk))))
		return ;
	stk->x = 0;
	stk->y = 0;
	stk->hash = 0;
	while (tab[stk->y])
	{
		while (tab[stk->y][stk->x])
		{
			ft_copy_stock_coor(&(*lst), &stk, tab);
			stk->x++;
		}
		stk->y++;
		stk->x = 0;
	}
}

t_tris	*ft_split_tetri(char *str)
{
	t_tris	*lst;
	char	**tab;
	char	**tmp;
	int		i;

	i = 0;
	lst = NULL;
	tab = ft_strsplit_charset(str, "\n\n");
	while (tab[i])
	{
		tmp = ft_strsplit(tab[i], '\n');
		lst = ft_set_t_tris(lst, 'A' + i);
		ft_stock_coord(&lst, tmp);
		ft_del_array(&tmp);
		i++;
	}
	while (lst->prev)
		lst = lst->prev;
	ft_del_array(&tab);
	return (lst);
}
