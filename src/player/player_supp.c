/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_supp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:14:02 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 17:20:25 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	affichage_direction(t_data *data)
{
	int	x;
	int	y;
	int	fov;

	x = 0;
	y = 0;
	fov = -30;
	while (fov <= 30)
	{
		x = find_x(data->player->direction + fov, 1000, data->player->x);
		y = find_y(data->player->direction + fov, 1000, data->player->y);
		draw_lign(data, data->player->x, data->player->y, x, y, RED);
		fov++;
	}
	x = find_x(data->player->direction, 1000, data->player->x);
	y = find_y(data->player->direction, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, GREEN);
	x = find_x(data->player->direction, 1000, data->player->x);
	y = find_y(data->player->direction, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);
	x = find_x(data->player->direction, 1000, data->player->x);
	y = find_y(data->player->direction, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);
	x = find_x(data->player->direction, 1000, data->player->x);
	y = find_y(data->player->direction, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);
}

void	affichage_player(t_data *data)
{
	full_circle(data, SQUARE / 4, data->player->x, data->player->y, GREEN);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
