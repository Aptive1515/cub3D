/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 16:30:38 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_data	*init_data(t_data *data, char *path_map)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->floor_rgb = NULL;
	data->ceiling_rgb = NULL;
	data->map = NULL;
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (NULL);
	data->path = malloc(sizeof(t_path));
	if (!data->path)
		return (NULL);
	data->path->path_map = path_map;
	data->path->path_NO = NULL;
	data->path->path_SO = NULL;
	data->path->path_WE = NULL;
	data->path->path_EA = NULL;
	
	data->path->texture_NO = NULL;
	data->path->texture_SO = NULL;
	data->path->texture_WE = NULL;
	data->path->texture_EA = NULL;
	return (data);
}

char	*ft_map_read(int fd)
{
	char	*tmp_map;
	char	*map_line;
	int		ln;

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
	char **tmp_tab;
	int	i;

	i = -1;
	while (++i <= 3)
	{
		tmp_tab = ft_split(tab_gnl[i], ' ');
		if (ft_doubletab_len(tmp_tab) > 2)
			return (ft_free_doubletab(tmp_tab));
		if (i == 0)
		{
			if (!ft_strcmp("NO", tmp_tab[0]))
				data->path->path_NO = ft_strdup(tmp_tab[1]);
			else
				return (ft_free_doubletab(tmp_tab));
		}
		else if (i == 1)
		{
			if (!ft_strcmp("SO", tmp_tab[0]))
				data->path->path_SO = ft_strdup(tmp_tab[1]);
			else
				return (ft_free_doubletab(tmp_tab));
		}
		else if (i == 2)
		{
			if (!ft_strcmp("WE", tmp_tab[0]))
				data->path->path_WE = ft_strdup(tmp_tab[1]);
			else
				return (ft_free_doubletab(tmp_tab));
		}
		else if (i == 3)
		{
			if (!ft_strcmp("EA", tmp_tab[0]))
				data->path->path_EA = ft_strdup(tmp_tab[1]);
			else
				return (ft_free_doubletab(tmp_tab));
		}
		ft_free_doubletab(tmp_tab);
	}
	return (1);
}

int	parsing_rgb_fc(t_data *data, char **tab_gnl)
{
	char	**tmp_tab;
	int		i;

	i = -1;
	while (++i <= 1)
	{
		tmp_tab = ft_split(tab_gnl[i], ' ');
		if (ft_doubletab_len(tmp_tab) > 2)
			return (ft_free_doubletab(tmp_tab));
		if (i == 0)
		{
			if (tmp_tab[0][0] == 'F')
				data->floor_rgb = ft_split(tmp_tab[1], ',');
			else
				return (ft_free_doubletab(tmp_tab));
		}
		else if (i == 1)
		{
			if (tmp_tab[0][0] == 'C')
				data->ceiling_rgb = ft_split(tmp_tab[1], ',');
			else
				return (ft_free_doubletab(tmp_tab));
		}
		ft_free_doubletab(tmp_tab);
	}
	return (1);
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
	str = ft_map_read(fd, 5);
	// printf("|%s|\n", str);
	texture = ft_split(str, '\n');
	free(str);
	if (!parsing_path_texture(data, texture)/* || !check_texture_path(data)*/)
	{
		ft_free_doubletab(texture);
		free_struct_config(data);
	}
	ft_free_doubletab(texture);
	str = ft_map_read(fd, 2);
	// printf("|%s|\n", str);
	texture = ft_split(str, '\n');
	free(str);
	if (!parsing_rgb_fc(data, texture) || !check_rgb(data))
	{
		ft_free_doubletab(texture);
		free_struct_config(data);	
	}
	ft_free_doubletab(texture);
	str = ft_map_read(fd, -1);
	// printf("|%s|\n", str);
	map = ft_split(str, '\n');
	free(str);
	copy_map(data, map);
	ft_free_doubletab(map);
	// for (int i = 0; data->map[i]; i++)
	// 	printf("|%s|\n", data->map[i]);
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

int	config_err(void)
{
	printf("Error\n");
	return (0);
}
