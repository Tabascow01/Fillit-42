/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:37:33 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/19 15:13:49 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!n)
		return (1);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
