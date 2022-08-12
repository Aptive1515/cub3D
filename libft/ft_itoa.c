/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:16:50 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/29 13:58:30 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_size(int n)
{
	int	size;

	size = 0;
	if (n < 0 && n > -2147483648)
	{
		size++;
		n = -n;
	}
	else if (n == 0)
	{
		return (1);
	}
	else if (n == -2147483648)
	{
		return (11);
	}
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				size;
	unsigned int	tmp;

	size = ft_itoa_size(n);
	tmp = n;
	if (n < 0)
		tmp = -n;
	i = 1;
	str = ft_calloc(sizeof(char), (size + 1));
	if (!str)
		return (NULL);
	if (tmp == 0)
		str[tmp] = '0';
	while (tmp >= 1)
	{
		str[size - i++] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (n < 0)
		*str = '-';
	str[size] = '\0';
	return (str);
}
