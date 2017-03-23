/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:42:24 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 12:42:33 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(char *str, char c, int *i)
{
	char	*result;
	int		j;

	j = *i;
	while (str[j] != c && str[j])
		j++;
	if (!(result = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] != c)
	{
		result[j] = str[*i];
		*i += 1;
		j++;
	}
	result[j] = '\0';
	return (result);
}

t_lst			*ft_strsplit_lst(char *str, char c)
{
	t_lst		*lst;
	char		*tmp;
	int			i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			tmp = ft_copy(str, c, &i);
			lst = ft_set_lst(lst, tmp, ft_strlen(tmp));
		}
	}
	return (lst);
}
