/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/09/14 19:19:35 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*ft_map_read(char *path)
{
	char	*tmp_map;
	char	*map_line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (!fd)
	{
		config_err();
		return (NULL);
	}
	map_line = ft_calloc(sizeof(char), 1);
	if (!map_line)
		return (NULL);
	while (1)
	{
		tmp_map = get_next_line(fd);
		if (!tmp_map)
			break ;
		map_line = ft_strjoin_gnl(map_line, tmp_map);
		free(tmp_map);
	}
	return (map_line);
}

int	parsing_path_texture(t_data *data, char **tab_gnl)
{
	int		i;
	int		len;

	i = -1;
	len = ft_doubletab_len(tab_gnl);
	if (len < 5)
		return (0);
	while (++i < len)
	{
		if (!ft_strncmp("NO", tab_gnl[i], 2))
			data->path->path_NO = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("SO", tab_gnl[i], 2))
			data->path->path_SO = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("WE", tab_gnl[i], 2))
			data->path->path_WE = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("EA", tab_gnl[i], 2))
			data->path->path_EA = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("F", tab_gnl[i], 1))
			parsing_rgb(data, tab_gnl[i]);
		else if (!ft_strncmp("C", tab_gnl[i], 1))
			parsing_rgb(data, tab_gnl[i]);
		else
			return (0);
	}
	return (1);
}

/*	VIRGULE AU DEBUT DU 1ER NUM A CORRIGER*/
int	parsing_rgb(t_data *data, char *str)
{
	char	**tmp_tab;

	tmp_tab = ft_split(str, ' ');
	if (ft_doubletab_len(tmp_tab) > 2)
		return (ft_free_doubletab(tmp_tab));
	if (!ft_strcmp(tmp_tab[0], "F") && (int)ft_strlen(tmp_tab[1]) == 11)
		data->floor_rgb = ft_split(tmp_tab[1], ',');
	else if (!ft_strcmp(tmp_tab[0], "C") && (int)ft_strlen(tmp_tab[1]) == 11)
		data->ceiling_rgb = ft_split(tmp_tab[1], ',');
	else
	{
		ft_free_doubletab(tmp_tab);
		return (0);	
	}
	ft_free_doubletab(tmp_tab);
	return (1);
}

int	parsing_map(t_data *data)
{
	char	**texture;
	char	**map;
	char	**mapi;
	char	*str;

	str = ft_map_read(data->path->path_map);
	map = ft_split(str, '\n');
	free(str);
	texture = split_tab(map, split_at_key(map), &mapi);
	ft_free_doubletab(map);
	if (!texture)
	{
		printf("there1\n");
		ft_free_doubletab(mapi);
		return (free_struct_config(data));
	}
	if (!parsing_path_texture(data, texture)
		|| !check_rgb(data) /*|| !check_texture_path(data)*/)
	{
		printf("there2\n");
		ft_free_doubletab(mapi);
		ft_free_doubletab(texture);
		return (free_struct_config(data));
	}
	ft_free_doubletab(texture);
	if (!copy_map(data, mapi))
	{
		printf("there3\n");
		ft_free_doubletab(mapi);
		return (free_struct_config(data));
	}
	ft_free_doubletab(mapi);
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
