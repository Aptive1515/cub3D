/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/18 12:21:28 by aptive           ###   ########.fr       */
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



	printf("direction	:	%i\n", data->player->direction);
	printf("vec x vec y	:	%i	/	%i\n", x, y);
	// printf("vec y	:	%i\n", y);

	printf("x1/y1	:	%i	/	%i\n", data->player->x, data->player->y);
	printf("x2/y2	:	%i	/	%i\n", data->player->x + x, data->player->y + y);
	printf("***************************************\n");

	printf("lx/ly	:	%i	/	%i\n", SQUARE * data->map_w, SQUARE * data->map_h);
	printf("x2/y2	:	%i	/	%i\n", data->player->x + x, data->player->y + y);



	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);




}

void	affichage_player(t_data *data)
{
	full_circle(data, SQUARE / 3, data->player->x, data->player->y, GREEN);
	affichage_direction(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

}

void	ft_move_fov(t_data *data, char c)
{
	if (c == 'r')
	{
		data->player->direction--;
	}
	if (c == 'g')
	{
		data->player->direction++;
	}
	if (data->player->direction >= 360)
		data->player->direction = 0;
	else if (data->player->direction < 0)
		data->player->direction = 359;
	ft_affiche_map(data);
}
