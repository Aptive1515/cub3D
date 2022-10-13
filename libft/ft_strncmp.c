/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:57:02 by tdelauna          #+#    #+#             */
/*   Updated: 2022/10/13 12:55:30 by chaidel          ###   ########.fr       */
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

int	ft_strrncmp(const char *s1, const char *s2, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	if (!len)
		return (0);
	while ((tmp_s1[i] == tmp_s2[j]) && tmp_s1[i] && tmp_s2[j] && len - 1 > 0)
	{
		len--;
		i--;
		j--;
	}
	return (tmp_s1[i] - tmp_s2[j]);
}
