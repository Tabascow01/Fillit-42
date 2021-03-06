/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_realloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:42:42 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 11:44:18 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_realloc(char ***array, size_t new_size)
{
	char		**new_array;
	size_t		i;

	i = 0;
	if (!(new_array = (char**)malloc(sizeof(char*) * new_size + 1)))
		return (NULL);
	while (i < new_size && array[0][i])
	{
		new_array[i] = ft_strdup(array[0][i]);
		free(array[0][i]);
		i++;
	}
	while (i < new_size)
	{
		new_array[i] = NULL;
		i++;
	}
	free(array[0]);
	new_array[i] = NULL;
	*array = new_array;
	return (new_array);
}
