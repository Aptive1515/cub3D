/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:40:28 by aptive            #+#    #+#             */
/*   Updated: 2022/10/07 20:15:28 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(t_data *data, t_player *player, double angle_ray)
{
	calcul_tile_step_y_y(player, player->tile_step_y);
	calcul_tile_step_x_x(player, player->tile_step_x);
	player->delta_x = SQUARE * player->tan_angle_ray;
	player->delta_y = SQUARE / player->tan_angle_ray;
	while (!check_intersection(data, player->tile_y_x, player->tile_y_y))
		next_intercept_y(player);
	while (!check_intersection(data, player->tile_x_x, player->tile_x_y))
		next_intercept_x(player);
}

double	calcul_delta(t_player *player, char c)
{
	if (c == 'X')
		return (player->x - (player->x / SQUARE) * SQUARE);
	else
		return (player->y - (player->y / SQUARE) * SQUARE);
}

int	check_intersection(t_data *data, int x, int y)
{
	int	x_map;
	int	y_map;

	y_map = y / SQUARE;
	x_map = x / SQUARE;
	if (x_map > data->map_w - 1 || x_map <= 0
		|| y_map > data->map_h - 1 || y_map <= 0)
	{
		ft_full(data, (x * SQUARE), (y * SQUARE), RED);
		return (1);
	}
	if (data->map[y_map][x_map] == '1')
		return (1);
	return (0);
}
