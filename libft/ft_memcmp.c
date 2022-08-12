/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:54:54 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/27 16:34:25 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*first_cast;
	unsigned char	*second_cast;

	i = 0;
	first_cast = (unsigned char *)s1;
	second_cast = (unsigned char *)s2;
	if (!n)
		return (0);
	while (first_cast[i] == second_cast[i] && i < n - 1)
		i++;
	return ((int)(first_cast[i] - second_cast[i]));
}
