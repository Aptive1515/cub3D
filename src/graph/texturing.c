/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:55:46 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/09 17:48:57 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	v_line_3d(t_data *data, int x, t_img *tex, int side)
{
	int	tex_y;
	int	tex_x;
	int	w_height;

	w_height = data->y_end - data->y_s;
	while (data->y_s < data->y_end)
	{
		if (!(data->y_s > data->screen_h || data->y_s < 0
				|| x < 0 || x > data->screen_w))
		{
			tex_y = (data->y_s - data->screen_h / 2 + w_height / 2)
				* 64 / w_height;
			sides(data, &tex_x, side);
			if (tex_x >= 0 && tex_y >= 0)
			{
				data->addr3d[data->y_s * data->length + x * (data->bpp / 8)]
					= tex->addr[tex_y * tex->line + tex_x * (tex->bpp / 8)];
				data->addr3d[data->y_s * data->length + x * (data->bpp / 8) + 1]
					= tex->addr[tex_y * tex->line + tex_x * (tex->bpp / 8) + 1];
				data->addr3d[data->y_s * data->length + x * (data->bpp / 8) + 2]
					= tex->addr[tex_y * tex->line + tex_x * (tex->bpp / 8) + 2];
			}
		}
		data->y_s++;
	}
}

void	sides(t_data *data, int *tex_x, int side)
{
	if (side == 0)
		*tex_x = 64 - ((int)data->ray_x % 32) * 2 - 1;
	if (side == 1)
		*tex_x = 64 - ((int)data->ray_y % 32) * 2 - 1;
}
