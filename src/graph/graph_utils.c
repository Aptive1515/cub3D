/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:45:13 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 01:04:46 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	verif_wall(t_data *data, int x, int y)
{
	int	x_map;
	int	y_map;

	x_map = x / SQUARE;
	y_map = y / SQUARE;
	// printf("xp / y :	%i / %i\n", x, y);
	// printf("x_map / y_map :	%i / %i\n", x_map, y_map);

	if (x_map > data->map_w - 1 || x_map <= 0 || y_map > data->map_h - 1|| y_map <= 0)
		return (1);
	// printf("y (SQUARE * y_map) : %i\n", (SQUARE * y_map));

	if(x % (SQUARE * x_map)|| y % (SQUARE * y_map))
	{
		if (data->map[y_map][x_map] == '1')
			return (1);
	}
	(void)data;
	return (0);
}

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
