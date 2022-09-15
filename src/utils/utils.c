/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:51:41 by chaidel           #+#    #+#             */
/*   Updated: 2022/09/15 12:35:58 by chaidel          ###   ########.fr       */
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

int	free_struct(t_data *data)
{
	if (data->floor_rgb)
		ft_free_doubletab(data->floor_rgb);
	if (data->ceiling_rgb)
		ft_free_doubletab(data->ceiling_rgb);
	if (data->map)
		ft_free_doubletab(data->map);
	if (data->path->path_NO)
		free(data->path->path_NO);
	if (data->path->path_SO)
		free(data->path->path_SO);
	if (data->path->path_WE)
		free(data->path->path_WE);
	if (data->path->path_EA)
		free(data->path->path_EA);
	if (data->path->texture_NO)
		mlx_destroy_image(data->mlx, data->path->texture_NO);
	if (data->path->texture_SO)
		mlx_destroy_image(data->mlx, data->path->texture_SO);
	if (data->path->texture_WE)
		mlx_destroy_image(data->mlx, data->path->texture_WE);
	if (data->path->texture_EA)
		mlx_destroy_image(data->mlx, data->path->texture_EA);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->img_3d);
	
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx_3d, data->mlx_win_3d);
	mlx_destroy_display(data->mlx);
	mlx_destroy_display(data->mlx_3d);
	
	free(data->mlx);
	free(data->mlx_3d);
	free(data->player);
	free(data->path);
	free(data);
	return (0);
}

int	ft_free_doubletab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
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
	while (i < max)
		rest[0][j++] = ft_strdup(tab[i++]);
	rest[0][j] = NULL;
	return (opt);
}
