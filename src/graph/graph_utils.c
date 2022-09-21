/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:45:13 by aptive            #+#    #+#             */
/*   Updated: 2022/09/16 19:36:33 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put_limit_wall(t_data *data, int x, int y, int color)
{
	if (x > data->map_w * SQUARE || x < 0 || y > data->map_h * SQUARE || y < 0)
		return;
	if (verif_wall(data, x, y))
		return;
	my_mlx_pixel_put(data, x, y, color);
}

void	my_mlx_pixel_put_limit(t_data *data, int x, int y, int color)
{
	if (x > data->map_w * SQUARE || x < 0 || y > data->map_h * SQUARE || y < 0)
		return;
	my_mlx_pixel_put(data, x, y, color);
}

void	my_mlx_pixel_put_3d(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return;

	dst = data->addr_3d + (y * data->line_length_3d + x * (data->bits_per_pixel_3d / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, void* color)
{
	char *dst;
	while (y < y_end)
	{
		if (!(x > WIDTH || x < 0 || y > HEIGHT || y < 0))
		{
			dst = color + (x * 4 + 4 * data->line_length_3d * y);

		}
		// printf("y:%d | x: %d\n",y,x);
		// mlx_put_image_to_window(data->mlx_3d, data->mlx_win_3d, color, x, y);
		// my_mlx_pixel_put_3d(data, x, y, color);
		y++;
	}
/*
	while (y < y_end)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, color, x, y);
		y++;
	}
*/
}
