/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:21:15 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/07 20:21:27 by chaidel          ###   ########.fr       */
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
	if (data->tex_no->path)
		free(data->tex_no->path);
	if (data->tex_so->path)
		free(data->tex_so->path);
	if (data->tex_we->path)
		free(data->tex_we->path);
	if (data->tex_ea->path)
		free(data->tex_ea->path);
	if (data->tex_no->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_no->ptr);
	if (data->tex_so->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_so->ptr);
	if (data->tex_we->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_we->ptr);
	if (data->tex_ea->ptr)
		mlx_destroy_image(data->mlx_3d, data->tex_ea->ptr);
	freer(data);
	return (config_err());
}

void	freer(t_data *data)
{
	free(data->player);
	free(data->tex_no);
	free(data->tex_so);
	free(data->tex_we);
	free(data->tex_ea);
	free(data);
}
