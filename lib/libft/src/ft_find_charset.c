/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_charset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:06:51 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/05 13:40:06 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_charset(const char *str, const char *charset)
{
	int		i;

	i = 0;
	while (str[i] && charset[i])
	{
		if (str[i] != charset[i])
			return (0);
		i++;
	}
	if (i != (int)ft_strlen(charset))
		return (0);
	return (1);
}
