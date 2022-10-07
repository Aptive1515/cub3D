/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:21:15 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/06 17:34:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	config_err(void)
{
	printf("Error\n");
	return (0);
}

int	free_struct_config(t_data *data)
{
	if (data->floor_rgb)
		ft_free_doubletab(data->floor_rgb);
	if (data->ceiling_rgb)
		ft_free_doubletab(data->ceiling_rgb);
	if (data->map)
		ft_free_doubletab(data->map);
	if (data->tex_NO->path)
		free(data->tex_NO->path);
	if (data->tex_SO->path)
		free(data->tex_SO->path);
	if (data->tex_WE->path)
		free(data->tex_WE->path);
	if (data->tex_EA->path)
		free(data->tex_EA->path);
	if (data->tex_NO->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_NO->ptr);
	if (data->tex_SO->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_SO->ptr);
	if (data->tex_WE->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_WE->ptr);
	if (data->tex_EA->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_EA->ptr);
	freer(data);
	return (config_err());
}

void	freer(t_data *data)
{
	free(data->player);
	free(data->tex_NO);
	free(data->tex_SO);
	free(data->tex_WE);
	free(data->tex_EA);
	free(data);
}