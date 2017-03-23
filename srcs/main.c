/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:54:07 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/13 15:06:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit [filename]");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_tris	*lst;
	char	*file;
	int		deb;
	char	**map;

	map = NULL;
	if (!ft_check_argc(argc))
		return (0);
	if (!(file = ft_read(argv[1])))
		return (0);
	deb = ft_check(file);
	if (deb != 1)
	{
		ft_putendl("error");
		return (0);
	}
	if (deb == 1)
	{
		lst = ft_split_tetri(file);
		ft_resolver(lst, &map);
	}
	ft_print_words_table(map);
	free(file);
	ft_del_array(&map);
	return (0);
}
