/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:14:25 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 13:33:07 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_len_map(t_tris *lst)
{
	int		i;
	int		cas;

	i = 0;
	while (lst->next)
		lst = lst->next;
	cas = lst->alpha - 64;
	cas = cas * 4;
	while (i * i < cas)
		i++;
	return (i);
}

void	ft_set_map(char ***map, int len)
{
	int		y;
	int		x;

	y = 0;
	while (y < len)
	{
		x = 0;
		while (x < len)
		{
			(*map)[y][x] = '.';
			x++;
		}
		y++;
	}
	(*map)[y] = NULL;
}

int		ft_creat_map(char ***map, int len, t_tris *lst)
{
	int		i;

	i = 0;
	if (len == 0)
		len = ft_len_map(lst);
	else
		ft_del_array(&(*map));
	if (!(*map = (char**)malloc(sizeof(char*) * len + 1)))
		return (0);
	(*map)[len] = NULL;
	while (i < len)
	{
		if (!((*map)[i] = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		(*map)[i][len] = '\0';
		i++;
	}
	ft_set_map(map, len);
	return (len);
}
