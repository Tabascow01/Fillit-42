/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:41:56 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 12:42:08 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst	*ft_handle_null(t_lst *lst, char *str, char *charset)
{
	char	*result;

	if (!*str)
	{
		result = ft_strdup("");
		lst = ft_set_lst(lst, result, 0);
	}
	else if (!*charset)
	{
		result = ft_strdup(str);
		lst = ft_set_lst(lst, result, ft_strlen(result));
	}
	return (lst);
}

static char		*ft_copy(char *str, char *charset, int *i)
{
	char		*result;
	int			j;

	j = *i;
	while (!ft_find_charset(&str[j], charset))
		j += 1;
	if (!(result = (char*)malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (!ft_find_charset(&str[*i], charset))
	{
		result[j] = str[*i];
		*i += 1;
		j++;
	}
	result[j] = '\0';
	return (result);
}

t_lst			*ft_strsplit_charset_lst(char *str, char *charset)
{
	t_lst		*lst;
	int			i;
	char		*result;

	lst = NULL;
	i = 0;
	if (!*charset || !*str)
		return (ft_handle_null(lst, str, charset));
	while (str[i])
	{
		while (ft_find_charset(&str[i], charset))
			i += ft_strlen(charset);
		if (str[i])
		{
			result = ft_copy(str, charset, &i);
			lst = ft_set_lst(lst, result, ft_strlen(result));
		}
	}
	return (lst);
}
