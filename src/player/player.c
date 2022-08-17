/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/17 20:04:16 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void find_player_orientation(t_data *data)
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
				data->player->direction = 0;
			else if (data->map[y][x] == 'E')
				data->player->direction = 90;
			else if (data->map[y][x] == 'S')
				data->player->direction = 180;
			else if (data->map[y][x] == 'W')
				data->player->direction = 270;
			x++;
		}
		y++;
	}
}

void find_player_position(t_data *data)
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
				data->player->x = (x * SQUARE) + SQUARE/2;
				data->player->y = (y * SQUARE) + SQUARE/2;
			}
			x++;
		}
		y++;
	}
}

void	init_player(t_data *data)
{
	data->player = ft_calloc(sizeof(data->player), 1);
	if (!data->player)
		return;
	find_player_orientation(data);
	find_player_position(data);
}

void	affichage_direction(t_data *data)
{
	(void)data;
	// int x = -100;
	// int y = -50;
	// while (x <= 200)
	// {
	// 	while (y <= 60)
	// 	{
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x + x, data->player->y + y, WHITE);
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x + x, data->player->y - y, WHITE);
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x - x, data->player->y + y, WHITE);
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x - x, data->player->y - y, WHITE);

	// 		y++;
	// 	}
	// 	x++;
	// }

	// while (x <= 100)
	// {
	// 	while (y <= 50)
	// 	{
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x + x, data->player->y + y, WHITE);
	// 		draw_lign(data, data->player->x, data->player->y, data->player->x + x, data->player->y - y, WHITE);
	// 		y++;
	// 	}
	// 	x++;
	// }
	draw_lign(data, data->player->x, data->player->y, data->player->x + 100, data->player->y - 50, WHITE);
	draw_lign(data, data->player->x, data->player->y, data->player->x + 100, data->player->y - 30, WHITE);
	// draw_lign(data, data->player->x, data->player->y, data->player->x - 100, data->player->y + 50, WHITE);
	// draw_lign(data, data->player->x, data->player->y, data->player->x - 100, data->player->y - 50, WHITE);
	// draw_lign(data, data->player->x, data->player->y, data->player->x - 0, data->player->y - 50, WHITE);
	// draw_lign(data, data->player->x, data->player->y, data->player->x - 0, data->player->y + 50, WHITE);

	printf("hereeee\n");
}

void	affichage_player(t_data *data)
{
	full_circle(data, SQUARE/3, data->player->x, data->player->y, WHITE);
	affichage_direction(data);
}
