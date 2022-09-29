/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 17:21:25 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	find_player_orientation(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'N')
				data->player->direction = 90 * ONE_DEGRE;
			else if (data->map[y][x] == 'E')
				data->player->direction = 0;
			else if (data->map[y][x] == 'S')
				data->player->direction = 270 * ONE_DEGRE;
			else if (data->map[y][x] == 'W')
				data->player->direction = 180 * ONE_DEGRE;
			x++;
		}
		y++;
	}
}

void	find_player_position(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
			{
				data->player->x = (x * SQUARE) + SQUARE / 2;
				data->player->y = (y * SQUARE) + SQUARE / 2;
			}
			x++;
		}
		y++;
	}
}

void	ft_move_fov(t_data *data, char c)
{
	if (c == 'r')
		data->player->direction -= 10 * ONE_DEGRE;
	if (c == 'g')
		data->player->direction += 10 * ONE_DEGRE;
	if (data->player->direction >= 2 * M_PI)
		data->player->direction = 0;
	else if (data->player->direction <= 0)
		data->player->direction = 2 * M_PI;
}

double	find_move_direction_player(t_data *data, char c)
{
	double	mv_direction;

	if (c == 'u')
		mv_direction = data->player->direction;
	if (c == 'd')
		mv_direction = data->player->direction - 180 * ONE_DEGRE;
	if (c == 'g')
		mv_direction = data->player->direction + 90 * ONE_DEGRE;
	if (c == 'r')
		mv_direction = data->player->direction - 90 * ONE_DEGRE;
	mv_direction = inter_pi(mv_direction);
	return (mv_direction);
}

void	ft_move_player(t_data *data, char c)
{
	double	mv_direction;
	double	x;
	double	y;

	mv_direction = find_move_direction_player(data, c);
	x = find_x(mv_direction, 5, data->player->x);
	y = find_y(mv_direction, 5, data->player->y);
	data->player->x = x;
	data->player->y = y;
}
