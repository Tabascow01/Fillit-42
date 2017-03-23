/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:11:16 by mrembusc          #+#    #+#             */
/*   Updated: 2016/12/04 18:55:02 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(const char *pathname)
{
	int		len;
	char	*str;

	str = ft_strnew(547);
	if ((len = read(open(pathname, O_RDONLY), str, 547)) > 545)
		return (NULL);
	return (str);
}
