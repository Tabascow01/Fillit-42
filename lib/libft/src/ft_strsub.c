/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:44:11 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/19 15:38:19 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*result;

	i = 0;
	result = NULL;
	if (!(result = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	return (result);
}
