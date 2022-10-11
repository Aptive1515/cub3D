/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:51:41 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/11 15:26:25 by chaidel          ###   ########.fr       */
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
	data->tex_no = malloc(sizeof(t_img));
	if (!data->tex_no)
		return (NULL);
	data->tex_so = malloc(sizeof(t_img));
	if (!data->tex_so)
		return (NULL);
	data->tex_we = malloc(sizeof(t_img));
	if (!data->tex_we)
		return (NULL);
	data->tex_ea = malloc(sizeof(t_img));
	if (!data->tex_ea)
		return (NULL);
	init_tex(data);
	return (data);
}

void	init_tex(t_data *data)
{
	data->tex_no->ptr = NULL;
	data->tex_so->ptr = NULL;
	data->tex_we->ptr = NULL;
	data->tex_ea->ptr = NULL;
	data->mlx_3d = NULL;
}

int	free_struct(t_data *data)
{
	if (data->floor_rgb)
		ft_free_doubletab(data->floor_rgb);
	if (data->ceiling_rgb)
		ft_free_doubletab(data->ceiling_rgb);
	if (data->map)
		ft_free_doubletab(data->map);
	if (data->tex_no->path)
		free(data->tex_no->path);
	if (data->tex_so->path)
		free(data->tex_so->path);
	if (data->tex_we->path)
		free(data->tex_we->path);
	if (data->tex_ea->path)
		free(data->tex_ea->path);
	destroyer(data);
	free(data->mlx_3d);
	free(data->player);
	free(data->tex_no);
	free(data->tex_so);
	free(data->tex_we);
	free(data->tex_ea);
	free(data);
	return (0);
}

void	destroyer(t_data *data)
{
	if (data->tex_no->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_no->ptr);
	if (data->tex_so->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_so->ptr);
	if (data->tex_we->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_we->ptr);
	if (data->tex_ea->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_ea->ptr);
	mlx_destroy_image(data->mlx_3d, data->img_3d);
	if (data->mlx_win_3d)
		mlx_destroy_window(data->mlx_3d, data->mlx_win_3d);
	mlx_destroy_display(data->mlx_3d);
}

int	ft_free_doubletab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	printf("%p\n", tab);
	if (tab)
		free(tab);
	return (0);
}
