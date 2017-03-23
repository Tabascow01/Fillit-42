/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:03:17 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/04 18:26:42 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_is_placeable(t_tris *lst, char **tab, int x, int y)
{
	int		len;

	len = ft_strlen(tab[y]);
	if ((lst->y_1 + y >= len || lst->y_1 + y < 0)
	|| (lst->y_2 + y >= len || lst->y_2 + y < 0)
	|| (lst->y_3 + y >= len || lst->y_3 + y < 0)
	|| (lst->x_1 + x >= len || lst->x_1 + x < 0)
	|| (lst->x_2 + x >= len || lst->x_2 + x < 0)
	|| (lst->x_3 + x >= len || lst->x_3 + x < 0))
		return (0);
	if ((tab[y][x] == '.')
		&& (tab[lst->y_1 + y][lst->x_1 + x] == '.')
		&& (tab[lst->y_2 + y][lst->x_2 + x] == '.')
		&& (tab[lst->y_3 + y][lst->x_3 + x] == '.'))
		return (1);
	return (0);
}

int		ft_insert_piece(t_tris *lst, char ***tab, int x, int y)
{
	(*tab)[y][x] = lst->alpha;
	(*tab)[lst->y_1 + y][lst->x_1 + x] = lst->alpha;
	(*tab)[lst->y_2 + y][lst->x_2 + x] = lst->alpha;
	(*tab)[lst->y_3 + y][lst->x_3 + x] = lst->alpha;
	return (1);
}

void	ft_clean_piece(t_tris *lst, char ***tab, int x, int y)
{
	(*tab)[y][x] = '.';
	(*tab)[lst->y_1 + y][lst->x_1 + x] = '.';
	(*tab)[lst->y_2 + y][lst->x_2 + x] = '.';
	(*tab)[lst->y_3 + y][lst->x_3 + x] = '.';
}

int		ft_place_tetri(t_tris *lst, char ***map)
{
	int		y;
	int		x;

	y = 0;
	while ((*map)[y])
	{
		x = 0;
		while ((*map)[y][x])
		{
			if (ft_is_placeable(lst, *map, x, y))
			{
				if (ft_insert_piece(lst, map, x, y) && !lst->next)
					return (2);
				if (lst->next)
					if (ft_place_tetri(lst->next, map) == 2)
						return (2);
				ft_clean_piece(lst, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_resolver(t_tris *lst, char ***map)
{
	int		len;

	len = ft_creat_map(map, 0, lst);
	(void)len;
	while (!ft_place_tetri(lst, map))
		ft_creat_map(map, len++, lst);
}
