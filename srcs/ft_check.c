/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:19:10 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 18:23:53 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_n(char *str, int i, int *j, int *k)
{
	if (i == 0 || (!str[i + 1] && str[i] == '\n' && str[i - 1] == '\n'))
		return (0);
	if (str[i - 1] == '\n')
	{
		*j -= 1;
		*k += 1;
	}
	if ((i + *j) % 5 == 0 && str[i - 1] != '\n')
		return (1);
	if ((i - *k) % 20 == 0)
		return (1);
	return (0);
}

int		ft_check_charset(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = -1;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '\n' && ft_check_n(str, i, &j, &k) == 0)
			return (2);
		i++;
	}
	if (i < 20)
		return (4);
	return (1);
}

int		ft_check_dothash(char *str)
{
	int		hash;
	int		dot;
	int		i;

	hash = 0;
	i = 0;
	dot = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		if (str[i] == '.')
			dot++;
		if (((str[i + 1] == '\n' && str[i] == '\n') || !str[i + 1]) &&
				(hash != 4 || dot != 12))
			return (3);
		else if ((str[i + 1] == '\n' && str[i] == '\n') || !str[i + 1])
		{
			hash = 0;
			dot = 0;
		}
		i++;
	}
	return (1);
}

int		ft_check_tetri(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 1] == '#')
			link++;
		if (str[i] == '#' && str[i - 1] == '#' && i > 0)
			link++;
		if (str[i] == '#' && str[i + 5] == '#')
			link++;
		if (str[i] == '#' && str[i - 5] == '#' && i > 4)
			link++;
		if ((str[i] == '\n' && str[i + 1] == '\n') && (link < 6))
			return (5);
		if (str[i] == '\n' && str[i + 1] == '\n')
			link = 0;
		i++;
	}
	if (link < 6)
		return (5);
	return (1);
}

int		ft_check(char *str)
{
	int		check;

	check = ft_check_charset(str);
	if (check != 1)
		return (check);
	check = ft_check_dothash(str);
	if (check != 1)
		return (check);
	check = ft_check_tetri(str);
	if (check != 1)
		return (check);
	return (1);
}
