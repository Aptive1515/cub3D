/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:48:56 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/26 18:31:44 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned long	nb;
	long			sign;
	long			i;

	sign = 1;
	i = 0;
	nb = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		nb = ((unsigned long)nptr[i++] - 48) + (nb * 10);
	if (nb > 2147483647 && sign == 1)
		return (-1);
	if (nb > 2147483648 && sign == -1)
		return (0);
	return (nb * sign);
}
