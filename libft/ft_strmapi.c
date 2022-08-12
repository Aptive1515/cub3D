/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:13:52 by tdelauna          #+#    #+#             */
/*   Updated: 2021/11/27 16:32:27 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	i = 0;
	if (!s || !(*f))
		return (NULL);
	mapi = ft_strdup(s);
	if (!mapi)
		return (NULL);
	while (mapi[i])
	{
		mapi[i] = (*f)(i, mapi[i]);
		i++;
	}
	return (mapi);
}
