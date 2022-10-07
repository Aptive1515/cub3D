/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:02:09 by tdelauna          #+#    #+#             */
/*   Updated: 2022/10/07 20:20:33 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_print(char *s, int fd)
{
	if (s)
	{
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	return (0);
}

int	ft_putchar_fd_print(char c, int fd)
{
	return (write (fd, &c, 1));
}

/*
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (s + i);
		i++;
	}
	return (0);
}*/
