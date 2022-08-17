/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/18 01:12:08 by aptive           ###   ########.fr       */
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
				data->player->direction = 180;
			else if (data->map[y][x] == 'E')
				data->player->direction = 90;
			else if (data->map[y][x] == 'S')
				data->player->direction = 0;
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

int find_y(int angle, int distance, int origin_y)
{
	int vecteur_y;

	// printf("cos x : %f\n", cos(angle * 3.14/180));
	vecteur_y = (int)(cos(angle * 3.14/180) * distance);
	return (vecteur_y + origin_y);
}

int find_x(int angle, int distance, int origin_x)
{
	int vecteur_x;
	vecteur_x = (int)(sin(angle * 3.14/180) * distance);
	return (vecteur_x + origin_x);
}

void	affichage_direction(t_data *data)
{
	(void)data;

	int	x;
	int	y;

	x = 0;
	y = 0;

	x = find_x(data->player->direction, 1000, data->player->x);
	y = find_y(data->player->direction, 1000, data->player->y);
	printf("direction : %i\n", data->player->direction);
	printf("vecteur x : %i\n", x);
	printf("vecteur y : %i\n", y);

	printf("x1/y1 : (%i , %i)\n", data->player->x, data->player->y);
	printf("x2/y2 : (%i , %i)\n", data->player->x + x, data->player->y + y);
	printf("test\n");

	printf("limite x: %i\n", SQUARE * data->map_w);
	printf("limite y : %i\n", SQUARE * data->map_h);

	if (x >= SQUARE * data->map_w)
		x = data->map_w * SQUARE - 1;
	else if (x < 0)
		x = 0;

	if (y >= SQUARE * (data->map_h - 1))
		y = (data->map_h) * SQUARE;
	else if (y < 0)
		y = 0;


	printf("x1/y1 : (%i , %i)\n", data->player->x, data->player->y);
	printf("x2/y2 : (%i , %i)\n", data->player->x + x, data->player->y + y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);
	printf("end\n");




}

void	affichage_player(t_data *data)
{
	full_circle(data, SQUARE/3, data->player->x, data->player->y, GREEN);
	affichage_direction(data);
}
