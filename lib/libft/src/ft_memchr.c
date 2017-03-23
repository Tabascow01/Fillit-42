/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:13:52 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/18 12:12:49 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	cpy_c;
	int		i;

	str = (char*)s;
	cpy_c = (char)c;
	i = 0;
	while (n)
	{
		if (str[i] == cpy_c)
			return ((void*)&str[i]);
		n--;
		i++;
	}
	return (NULL);
}
