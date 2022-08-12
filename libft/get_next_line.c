/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:32:26 by tdelauna          #+#    #+#             */
/*   Updated: 2022/03/31 17:09:30 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*buf_rest;
	char		*lign_print;

	if (fd < -1 || BUFFER_SIZE < 1)
		return (0);
	buf_rest = ft_readline(fd, buf_rest);
	if (!buf_rest)
		return (0);
	lign_print = ft_lign_print(buf_rest);
	buf_rest = ft_rest(buf_rest);
	return (lign_print);
}

char	*ft_readline(int fd, char *buf_rest)
{
	char	*buf;
	int		read_b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_b = 1;
	while (!ft_strchr_gnl(buf_rest, '\n') && read_b != 0)
	{
		read_b = read(fd, buf, BUFFER_SIZE);
		if (read_b == -1)
			return (free(buf), NULL);
		buf[read_b] = '\0';
		buf_rest = ft_strjoin_gnl(buf_rest, buf);
	}
	return (free(buf), buf_rest);
}

char	*ft_lign_print(char *buf_rest)
{
	char	*lign_print;
	int		i;

	i = 0;
	if (!buf_rest[i])
		return (NULL);
	while (buf_rest[i] && buf_rest[i] != '\n')
		i++;
	lign_print = (char *)malloc(sizeof(char) * (i + 2));
	if (!lign_print)
		return (NULL);
	i = 0;
	while (buf_rest[i] && buf_rest[i] != '\n')
	{
		lign_print[i] = buf_rest[i];
		i++;
	}
	if (buf_rest[i] == '\n')
	{
		lign_print[i] = buf_rest[i];
		i++;
	}
	lign_print[i] = '\0';
	return (lign_print);
}

char	*ft_rest(char *buf_rest)
{
	char	*dest_rest;
	int		i;
	int		j;

	i = 0;
	while (buf_rest[i] && buf_rest[i] != '\n')
		i++;
	if (!buf_rest[i])
		return (free(buf_rest), NULL);
	dest_rest = malloc(sizeof(char) * (ft_strlen_gnl(buf_rest) - i + 1));
	if (!dest_rest)
		return (NULL);
	i++;
	j = 0;
	while (buf_rest[i])
		dest_rest[j++] = buf_rest[i++];
	dest_rest[j] = '\0';
	return (free(buf_rest), dest_rest);
}
