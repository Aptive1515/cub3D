/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:09 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 18:23:46 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	affiche_celling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_h / 2)
	{
		x = 0;
		while (x < data->screen_w)
		{
			my_mlx_pixel_put_3d
			(data, x, y,
			create_trgb(0, ft_atoi(data->ceiling_rgb[0]),
			ft_atoi(data->ceiling_rgb[1]),
			ft_atoi(data->ceiling_rgb[2])));
			x++;
		}
		y++;
	}
}

void	affiche_floor(t_data *data)
{
	int	x;
	int	y;

	y = data->screen_h / 2;
	while (y <= data->screen_h)
	{
		x = 0;
		while (x < data->screen_w)
		{
			my_mlx_pixel_put_3d
				(data, x, y,
				create_trgb(0, ft_atoi(data->floor_rgb[0]),
				ft_atoi(data->floor_rgb[1]),
				ft_atoi(data->floor_rgb[2])));
			x++;
		}
		y++;
	}
}

void	ft_affiche_map(t_data *data)
{
	affiche_celling(data);
	affiche_floor(data);
	ray_traicing(data);
	mlx_put_image_to_window(data->mlx_3d, data->mlx_win_3d, data->img_3d, 0, 0);
}
