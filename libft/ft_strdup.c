/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:12:38 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/26 18:35:53 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_src;
	char	*dest;

	len_src = ft_strlen(s);
	dest = (char *)ft_calloc((len_src) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_memmove(dest, s, len_src);
	dest[len_src] = '\0';
	return (dest);
}
