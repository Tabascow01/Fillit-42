/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:12:48 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 12:45:53 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
