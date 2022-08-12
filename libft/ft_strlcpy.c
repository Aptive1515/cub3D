/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:48:56 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/29 15:28:59 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (size <= 0)
		return (len_src);
	if (len_src >= size)
		len_src = size - 1;
	ft_memcpy(dest, src, len_src);
	dest[len_src] = '\0';
	return (ft_strlen(src));
}
