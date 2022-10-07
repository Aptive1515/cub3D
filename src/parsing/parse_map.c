/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/10/07 19:48:10 by chaidel          ###   ########.fr       */
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
			data->tex_no->path = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("SO", tab_gnl[i], 2))
			data->tex_so->path = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("WE", tab_gnl[i], 2))
			data->tex_we->path = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("EA", tab_gnl[i], 2))
			data->tex_ea->path = split_txt(tab_gnl[i]);
		else if (!ft_strncmp("F", tab_gnl[i], 1))
			parsing_rgb(data, tab_gnl[i]);
		else if (!ft_strncmp("C", tab_gnl[i], 1))
			parsing_rgb(data, tab_gnl[i]);
		else
		{
			printf("me\n");
			return (0);
		}
	}
	return (1);
}

int	parsing_rgb(t_data *data, char *str)
{
	char	**tmp_tab;
	int		len;

	tmp_tab = ft_split(str, ' ');
	if (ft_doubletab_len(tmp_tab) > 2)
		return (ft_free_doubletab(tmp_tab));
	len = (int)ft_strlen(tmp_tab[1]);
	if (!ft_strcmp(tmp_tab[0], "F") && (len >= 5 && len <= 11))
		data->floor_rgb = ft_split(tmp_tab[1], ',');
	else if (!ft_strcmp(tmp_tab[0], "C") && (len >= 5 && len <= 11))
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

	str = ft_map_read(data->path_map);
	map = ft_split(str, '\n');
	free(str);
	texture = split_tab(map, split_at_key(map), &mapi);
	ft_free_doubletab(map);
	if (!parsing_map_sc(data, mapi, texture))
		return (free_struct_config(data));
	if (!copy_map(data, mapi))
	{
		ft_free_doubletab(mapi);
		return (free_struct_config(data));
	}
	ft_free_doubletab(mapi);
	return (1);
}

int	parsing_map_sc(t_data *data, char **mapi, char **tex)
{
	if (!tex)
	{
		ft_free_doubletab(mapi);
		return (0);
	}
	if (!parsing_path_texture(data, tex) || !check_rgb(data))
	{
		ft_free_doubletab(mapi);
		ft_free_doubletab(tex);
		return (0);
	}
	ft_free_doubletab(tex);
	return (1);
}
