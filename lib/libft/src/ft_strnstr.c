/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:38:57 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 18:10:27 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_stack(const char *s1, const char *s2, size_t i, size_t n)
{
	size_t	j;

	j = 0;
	while (s1[i] && s2[j] && i < n)
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	if (s2[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *hay, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)hay);
	while (hay[i] && i < n)
	{
		if (hay[i] == needle[0])
		{
			if (ft_check_stack(hay, needle, i, n) == 1)
				return ((char*)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
