/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:51:41 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/05 18:02:24 by chaidel          ###   ########.fr       */
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
	data->path_map = path_map;
	data->tex_NO = malloc(sizeof(t_img));
	if (!data->tex_NO)
		return (NULL);
	data->tex_SO = malloc(sizeof(t_img));
	if (!data->tex_SO)
		return (NULL);
	data->tex_WE = malloc(sizeof(t_img));
	if (!data->tex_WE)
		return (NULL);
	data->tex_EA = malloc(sizeof(t_img));
	if (!data->tex_EA)
		return (NULL);
	data->tex_NO->img_ptr = NULL;
	data->tex_SO->img_ptr = NULL;
	data->tex_WE->img_ptr = NULL;
	data->tex_EA->img_ptr = NULL;
	data->mlx = NULL;
	data->mlx_3d = NULL;
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
	if (data->tex_NO->path_tex)
		free(data->tex_NO->path_tex);
	if (data->tex_SO->path_tex)
		free(data->tex_SO->path_tex);
	if (data->tex_WE->path_tex)
		free(data->tex_WE->path_tex);
	if (data->tex_EA->path_tex)
		free(data->tex_EA->path_tex);
	if (data->tex_NO->img_ptr)
		mlx_destroy_image(data->mlx, data->tex_NO->img_ptr);
	if (data->tex_SO->img_ptr)
		mlx_destroy_image(data->mlx, data->tex_SO->img_ptr);
	if (data->tex_WE->img_ptr)
		mlx_destroy_image(data->mlx, data->tex_WE->img_ptr);
	if (data->tex_EA->img_ptr)
		mlx_destroy_image(data->mlx, data->tex_EA->img_ptr);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_image(data->mlx, data->img_3d);
	// if (data->mlx_win)
	// 	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx_win_3d)
		mlx_destroy_window(data->mlx_3d, data->mlx_win_3d);
	mlx_destroy_display(data->mlx);
	mlx_destroy_display(data->mlx_3d);
	free(data->mlx);
	free(data->mlx_3d);
	free(data->player);
	free(data->tex_NO);
	free(data->tex_SO);
	free(data->tex_WE);
	free(data->tex_EA);
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
