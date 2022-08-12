/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:57:02 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/27 16:31:21 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t			i;
	unsigned char	*first_cast;
	unsigned char	*second_cast;

	i = 0;
	first_cast = (unsigned char *) first;
	second_cast = (unsigned char *)second;
	if (!length)
		return (0);
	while (first_cast[i] && first_cast[i] == second_cast[i] && i < length - 1)
		i++;
	return ((first_cast[i] - second_cast[i]));
}
