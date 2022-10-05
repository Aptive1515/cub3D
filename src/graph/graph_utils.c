/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:45:13 by aptive            #+#    #+#             */
/*   Updated: 2022/10/05 16:41:54 by chaidel          ###   ########.fr       */
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

void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, t_img *tex, int side)
{
	int	tex_y;
	int	tex_x;
	int	step;

	// printf("texy: %d| da: %d\n", tex->line_length, data->line_length_3d);
	// printf("x:%d | y: %d\n", data->ray_x, data->ray_y);
	step = 1*128/tex->line_length;
	while (y < y_end)
	{
		if (!(y > HEIGHT || y < 0 || x < 0 || x > WIDTH))
		{
			// d = y * tex->line_length - HEIGHT * tex->line_length / 2 + y_end * tex->line_length / 2;
			tex_y = ((d * 128) / y_end) / tex->line_length;
			tex_x = x * 128;
			// printf("x:%d\n", tex_x);
			tex_x = 128-tex_x-1;
			if(side == 0 && data->player->tile_step_X > 0)
				tex_x = 128 - tex_x - 1;
    		if(side == 1 && data->player->tile_step_Y < 0)
				tex_x = 128 - tex_x - 1;
			data->addr_3d[y * data->line_length_3d + x /** (data->bits_per_pixel / 8)*/] = 
				tex->addr[tex_y * tex->line_length + tex_x /** (data->bits_per_pixel / 8)*/];


			// if (x == data->player->tile_X_x + data->player->tile_Y_x)
			// 	my_mlx_pixel_put_3d(data, x, y, WHITE);
		}
		y++;
	}
}
