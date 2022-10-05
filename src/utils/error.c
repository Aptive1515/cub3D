/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:21:15 by chaidel           #+#    #+#             */
/*   Updated: 2022/09/21 12:33:53 by chaidel          ###   ########.fr       */
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
	free(data->player);
	free(data->tex_NO);
	free(data->tex_SO);
	free(data->tex_WE);
	free(data->tex_EA);
	free(data);
	config_err();
	return (0);
}
