/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/18 15:25:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_data	*init_data(t_data *data, char *path_map)
{
	data = malloc(sizeof(t_data));
	if (!data)
	{
		msg_error("Error : data init problems");
		return (NULL);
	}
	data->path = malloc(sizeof(t_path));
	if (!data->path)
	{
		msg_error("Error : data init problems");
		return (NULL);
	}
	data->path->path_map = path_map;
	return (data);
}

char	*ft_map_read(char *path_map)
{
	int		fd_map;
	char	*tmp_map;
	char	*map_line;

	fd_map = open(path_map, O_RDONLY);
	if (!fd_map)
		msg_error("Map don't exist");
	map_line = malloc(sizeof(char));
	if (!map_line)
		return (NULL);
	map_line[0] = '\0';
	while (1)
	{
		tmp_map = get_next_line(fd_map);
		if (!tmp_map)
			break ;
		map_line = ft_strjoin_gnl(map_line, tmp_map);
		free(tmp_map);
	}
	return (map_line);
}

void	parsing_path_texture(t_data *data, char **tab_gnl)
{
	char **tmp_tab;
	int	i;

	i = -1;
	while (++i <= 3)
	{
		tmp_tab = ft_split(tab_gnl[i], ' ');
		if (i == 0)
			data->path->path_NO = tmp_tab[1];
		else if (i == 1)
			data->path->path_SO = tmp_tab[1];
		else if (i == 2)
			data->path->path_WE = tmp_tab[1];
		else if (i == 3)
			data->path->path_EA = tmp_tab[1];
		free(tmp_tab[0]);
		free(tmp_tab);
	}
}

void	parsing_rgb_fc(t_data *data, char **tab_gnl)
{
	char	**tmp_tab;
	int		i;

	i = -1;
	while (++i <= 1)
	{
		tmp_tab = ft_split(tab_gnl[i + 4], ' ');
		if (i == 0)
			data->floor_rgb = ft_split(tmp_tab[1], ',');
		else if (i == 1)
			data->ceiling_rbg = ft_split(tmp_tab[1], ',');
		ft_free_doubletab(tmp_tab);
	}
}

void	copy_map(t_data *data, char **tab_gnl)
{
	int	i;

	i = -1;
	data->map = ft_calloc(sizeof(data->map), ft_doubletab_len(tab_gnl) - 6);
	if(!data->map)
		return;
	//exit a rajouter
	while (tab_gnl[++i + 6])
		data->map[i] = tab_gnl[i + 6];
	// data->map[i] = NULL;
}

void	parsing_map(t_data *data)
{
	char	**tab_gnl;

	tab_gnl = ft_split(ft_map_read(data->path->path_map), '\n');
	parsing_path_texture(data, tab_gnl);
	parsing_rgb_fc(data, tab_gnl);
	copy_map(data, tab_gnl);

	data->map_h = ft_doubletab_len(data->map);
	data->map_w = ft_strlen(data->map[0]);
}
