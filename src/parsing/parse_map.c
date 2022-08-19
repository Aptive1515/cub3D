/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/19 20:26:18 by root             ###   ########.fr       */
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

char	*ft_map_read(int fd, int max)
{
	char	*tmp_map;
	char	*map_line;
	int		ln;

	ln = 0;
	map_line = ft_calloc(sizeof(char), 1);
	if (!map_line)
		return (NULL);
	while (ln != max)
	{
		tmp_map = get_next_line(fd);
		if (!tmp_map)
			break ;
		ln++;
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

void	parsing_map(t_data *data)
{
	char	**texture;
	char	**map;
	char	*str;
	int		fd;

	fd = open(data->path->path_map, O_RDONLY);
	if (!fd)
		msg_error("Map don't exist");
	str = ft_map_read(fd, 7);
	// printf("|%s|\n", str);
	texture = ft_split(str, '\n');
	free(str);
	parsing_path_texture(data, texture);
	parsing_rgb_fc(data, texture);
	str = ft_map_read(fd, -1);
	// printf("|%s|\n", str);
	map = ft_split(str, '\n');
	free(str);
	copy_map(data, map);
	ft_free_doubletab(map);
	for (int i = 0; data->map[i]; i++)
		printf("|%s|\n", data->map[i]);
}

void	get_max(t_data *data, char **map, int *max)
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
	data->map_w = len;
	data->map = ft_calloc(sizeof(data->map), i + 1);
	if(!data->map)
		return;
}

void	copy_map(t_data *data, char **map)
{
	int		i;
	int		max;
	char	*str_sp;
	char	*new_line;
	int		len;

	get_max(data, map, &max);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len < max)
		{
			str_sp = malloc(sizeof(char) * ((max - len) + 1));
			if (!str_sp)
				return ; //erreur a faire
			str_sp[max - len] = '\0';
			ft_memset(str_sp, ' ', max - len);
			new_line = ft_strdup(map[i]);
			data->map[i] = ft_strjoin_gnl(new_line, str_sp);
			// printf("|%s|\n", data->map[i]);
			free(str_sp);
		}
		else
			data->map[i] = ft_strdup(map[i]);
			// printf("|%s|\n", data->map[i]);
		i++;
	}
	// for (int i = 0; data->map[i]; i++)
	// 	printf("|%s|", data->map[i]);
}