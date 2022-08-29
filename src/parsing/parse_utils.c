/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:20:21 by chaidel           #+#    #+#             */
/*   Updated: 2022/08/29 15:26:29 by chaidel          ###   ########.fr       */
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

/*
 *	Vérifie si les 1er char sont clés d'option
*/
int	not_key(char *str)
{
	if (ft_strlen(str) > 2)
	{
		if (str[0] == 'F' || str[0] == 'C'
			|| !ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2)
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
			return (0);
	}
	return (1);
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
