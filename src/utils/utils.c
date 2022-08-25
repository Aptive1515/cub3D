/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 12:51:41 by chaidel           #+#    #+#             */
/*   Updated: 2022/08/25 14:12:08 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    free_struct_config(t_data *data)
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
	exit(EXIT_FAILURE);
}

void    free_struct(t_data *data)
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
	exit(EXIT_FAILURE);
}

void	ft_free_doubletab(char **tab)
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
}
