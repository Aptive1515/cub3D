/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:41:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/27 19:58:40 by chaidel          ###   ########.fr       */
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

char *split_txt(char *str)
{
	char	*path;
	char	**tab;

	tab = ft_split(str, ' ');
	path = ft_strdup(tab[1]);
	ft_free_doubletab(tab);
	return (path);
}



int	parsing_path_texture(t_data *data, char **tab_gnl)
{
	int		i;
	int		len;
	
	i = 0;
	len = ft_doubletab_len(tab_gnl);
	if (len < 5)
		return (0);
	while (i < len)
	{
		// printf("%s\n", tab_gnl[i]);
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
		i++;
	}
	return (1);
}

int	parsing_rgb(t_data *data, char *str)
{
	char	**tmp_tab;

	tmp_tab = ft_split(str, ' ');
	if (ft_doubletab_len(tmp_tab) > 2)
		return (ft_free_doubletab(tmp_tab));
	if (tmp_tab[0][0] == 'F')
		data->floor_rgb = ft_split(tmp_tab[1], ',');
	else if (tmp_tab[0][0] == 'C')
		data->ceiling_rgb = ft_split(tmp_tab[1], ',');
	ft_free_doubletab(tmp_tab);
	return (1);
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

char	**split_tab(char **tab, int len, char *(**rest))
{
	char	**opt;
	int		i;
	int		j;
	int		max;

	len++;
	max = ft_doubletab_len(tab);
	if (len >= max)
		return (NULL);
	opt = (char **)malloc(sizeof(char *) * (len + 1));
	if (!opt)
		return (NULL);
	opt[len] = NULL;
	i = 0;
	while (i < len)
	{
		opt[i] = ft_strdup(tab[i]);
		i++;
	}
	*(rest) = (char **)malloc(sizeof(char *) * (max - len + 1));
	if (*(rest) == NULL)
		return (NULL);
	j = 0;
	while (++i < max)
		rest[0][j++] = ft_strdup(tab[i]);
	rest[0][j] = '\0';
	return (opt);
}

int	split_at_key(char **file)
{
	int	len;

	len = ft_doubletab_len(file) - 1;
	while (len > 0 && not_key(file[len]))
		len--;
	return (len);
}

void	parsing_map(t_data *data)
{
	char	**texture;
	char	**map;
	char	**mapi;
	char	*str;
	int		len;

	str = ft_map_read(data->path->path_map);
	map = ft_split(str, '\n');
	free(str);
	len = split_at_key(map);
	texture = split_tab(map, len, &mapi);
	ft_free_doubletab(map);
	if (!parsing_path_texture(data, texture) || !check_rgb(data)/* || !check_texture_path(data)*/)
	{
		ft_free_doubletab(texture);
		free_struct_config(data);
	}
	// for(int i = 0; data->floor_rgb[i]; i++)
	// 	printf("%s\n", data->floor_rgb[i]);
	// for(int i = 0; data->ceiling_rgb[i]; i++)
	// 	printf("%s\n", data->ceiling_rgb[i]);
	ft_free_doubletab(texture);
	copy_map(data, mapi);
	ft_free_doubletab(mapi);
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
