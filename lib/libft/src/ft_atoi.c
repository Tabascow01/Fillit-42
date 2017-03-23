/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:44:36 by mrembusc          #+#    #+#             */
/*   Updated: 2016/11/12 11:45:34 by mrembusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	int		is_neg;

	i = 0;
	result = 0;
	is_neg = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' ||
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f' ||
			(nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')))
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		i++;
		is_neg = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * is_neg);
}
