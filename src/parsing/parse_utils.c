/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:20:21 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/12 10:01:40 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	split_at_key(char **file)
{
	int	len;

	len = ft_doubletab_len(file) - 1;
	while (len > 0 && not_key(file[len]))
		len--;
	return (len);
}

char	*split_txt(char *str)
{
	char	*path;
	char	**tab;

	tab = ft_split(str, ' ');
	path = ft_strdup(tab[1]);
	ft_free_doubletab(tab);
	return (path);
}

int	get_max(t_data *data, char **map, int *max)
{
	int	i;
	int	len;

	*max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i++]);
		if (len > *max)
			*max = len;
	}
	data->map_h = i;
	data->map_w = *max;
	data->map = ft_calloc(sizeof(data->map), i + 1);
	if (!data->map)
		return (0);
	return (1);
}

int	copy_map(t_data *data, char **map)
{
	int		i;
	int		max;
	char	*str_sp;
	char	*new_line;

	if (!get_max(data, map, &max))
		return (0);
	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) < max)
		{
			str_sp = malloc(sizeof(char) * ((max - ft_strlen(map[i])) + 1));
			if (!str_sp)
				return (0);
			str_sp[max - ft_strlen(map[i])] = '\0';
			ft_memset(str_sp, ' ', max - ft_strlen(map[i]));
			new_line = ft_strdup(map[i]);
			data->map[i] = ft_strjoin_gnl(new_line, str_sp);
			free(str_sp);
		}
		else
			data->map[i] = ft_strdup(map[i]);
	}
	return (1);
}

char	**split_tab(char **tab, int len, char *(**rest))
{
	char	**opt;
	int		i;
	int		j;
	int		max;

	opt = NULL;
	*(rest) = NULL;
	max = ft_doubletab_len(tab);
	if (++len >= max)
		return (NULL);
	opt = (char **)malloc(sizeof(char *) * (len + 1));
	if (!opt)
		return (NULL);
	opt[len] = NULL;
	i = -1;
	while (++i < len)
		opt[i] = ft_strdup(tab[i]);
	*(rest) = (char **)malloc(sizeof(char *) * (max - len + 1));
	if (*(rest) == NULL)
		return (NULL);
	j = 0;
	while (i < max)
		rest[0][j++] = ft_strdup(tab[i++]);
	rest[0][j] = NULL;
	return (opt);
}
