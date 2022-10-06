/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:45:13 by aptive            #+#    #+#             */
/*   Updated: 2022/10/06 17:44:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	my_mlx_pixel_put_limit_wall(t_data *data, int x, int y, int color)
{
	if (x > data->map_w * SQUARE || x < 0 || y > data->map_h * SQUARE || y < 0)
		return ;
	if (check_intersection(data, x, y))
		return ;
	my_mlx_pixel_put(data, x, y, color);
}

void	my_mlx_pixel_put_limit(t_data *data, int x, int y, int color)
{
	if (x > data->map_w * SQUARE || x < 0 || y > data->map_h * SQUARE || y < 0)
		return ;
	my_mlx_pixel_put(data, x, y, color);
}

void	my_mlx_pixel_put_3d(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > data->screen_w || x < 0 || y > data->screen_h || y < 0)
		return ;
	dst = data->addr_3d
		+ (y * data->line_length_3d + x * (data->bits_per_pixel_3d / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, t_img *tex, int side)
{
	int	tex_y;
	int	tex_x;
	int	w_height = y_end - y;

	while (y < y_end)
	{
		if (!(y > data->screen_h || y < 0 || x < 0 || x > data->screen_w ))
		{

			tex_y = (y - data->screen_h / 2 + w_height / 2) * 64 / w_height;
			if(side == 0)
				tex_x = 64 - ((int)data->ray_x % 32)*2 - 1;
    		if(side == 1)
				tex_x = 64 - ((int)data->ray_y % 32)*2 - 1;
			if (tex_x  >= 0 && tex_y >= 0)
			{
				data->addr_3d[y * data->line_length_3d + x * (data->bits_per_pixel_3d / 8)] = 
					tex->addr[tex_y * tex->length + tex_x * (tex->bpp / 8)];
				data->addr_3d[y * data->line_length_3d + x * (data->bits_per_pixel_3d / 8) + 1] =
					tex->addr[tex_y * tex->length + tex_x * (tex->bpp / 8) + 1];
				data->addr_3d[y * data->line_length_3d + x * (data->bits_per_pixel_3d / 8) + 2] =
					tex->addr[tex_y * tex->length + tex_x * (tex->bpp / 8) + 2];
			}
		}
		y++;
	}
}

