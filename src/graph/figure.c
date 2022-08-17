/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:02:53 by aptive            #+#    #+#             */
/*   Updated: 2022/08/17 16:03:51 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_lign_vertical(t_data *data, int x, int y, int y_end, int color)
{
	while (y < y_end)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}


void	ft_lign_horizontal(t_data *data, int x, int x_end, int y,int color)
{
	while (x < x_end)
	{
		my_mlx_pixel_put(data, x, y, color);
		x++;
	}
}

void ft_grille(t_data *data)
{
	int i;
	int height;
	int width;

	height = data->map_h * SQUARE;
	width = data->map_w * SQUARE;

	i = 0;
	(void)data;
	while (i < width)
	{
		ft_lign_vertical(data, i, 0, height, RED);
		i += SQUARE;
	}
	i = 0;
	while (i < height)
	{
		ft_lign_horizontal(data, 0, width, i, RED);
		i += SQUARE;
	}
}

void	ft_full(t_data *data, int x_beg, int y_beg, int color)
{
	int	x_end;
	int	y_end;
	// printf("HERE\n");

	x_end = x_beg + SQUARE;
	y_end = y_beg + SQUARE;
	while (x_beg < x_end)
	{
		ft_lign_vertical(data, x_beg, y_beg + 1, y_end, color);
		x_beg++;
	}
}

void	do_circle(t_data *data, int r, int x_centre, int y_centre, int color)
{
	int	x;
	int	y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (x <= y)
	{
		my_mlx_pixel_put(data, x_centre + x , y_centre + y, color);
		my_mlx_pixel_put(data, x_centre + y , y_centre + x, color);
		my_mlx_pixel_put(data, x_centre - x , y_centre + y, color);
		my_mlx_pixel_put(data, x_centre - y , y_centre + x, color);
		my_mlx_pixel_put(data, x_centre + x , y_centre - y, color);
		my_mlx_pixel_put(data, x_centre + y , y_centre - x, color);
		my_mlx_pixel_put(data, x_centre - x , y_centre - y, color);
		my_mlx_pixel_put(data, x_centre - y , y_centre - x, color);
		if (d >= 2 * x)
		{
			d = d - 2 * x - 1;
			x++;
		}
		else if (d < 2* (r - y))
		{
			d = d + 2 * y - 1;
			y = y - 1;
		}
		else
		{
			d = d + 2 * (y - x - 1);
			y--;
			x++;
		}
	}
}

void full_circle(t_data *data, int r, int x_centre, int y_centre, int color)
{
	while (r >= 0)
	{
		do_circle(data, r, x_centre, y_centre, color);
		r--;
	}
}
