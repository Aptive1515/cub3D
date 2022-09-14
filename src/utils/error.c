/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:21:15 by chaidel           #+#    #+#             */
/*   Updated: 2022/09/14 19:12:16 by chaidel          ###   ########.fr       */
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
	free(data->player);
	free(data->path);
	free(data);
	config_err();
	return (0);
}
