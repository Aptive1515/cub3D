/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 01:03:20 by aptive           ###   ########.fr       */
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
		while (x < (int)ft_strlen(data->map[y]))
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
		while (x < (int)ft_strlen(data->map[y]))
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
	data->player = ft_calloc(sizeof(t_player), 1);
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

// int find_y_float(int angle, int distance, int origin_y)
// {
// 	int vecteur_y;
// 	float vecteur_y_float;

// 	// printf("cos x : %f\n", cos(angle * 3.14/180));
// 	vecteur_y_float = (cos(angle * 3.14/180) * distance);
// 	vecteur_y = (int)(cos(angle * 3.14/180) * distance);
// 	printf("vecteur_y_float %f\n", vecteur_y_float);

// 	return (vecteur_y + origin_y);
// }

// int find_x_float(int angle, int distance, int origin_x)
// {
// 	int vecteur_x;
// 	float vecteur_x_float;

// 	vecteur_x = (int)(sin(angle * 3.14/180) * distance);

// 	vecteur_x_float = (sin(angle * 3.14/180) * distance);
// 	printf("vecteur_x_float %f\n", vecteur_x_float);


// 	return (vecteur_x + origin_x);
// }

void	affichage_direction(t_data *data)
{
	(void)data;

	int	x;
	int	y;

	x = 0;
	y = 0;
	int	fov;
	(void) fov;
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



	// printf("direction	:	%i\n", data->player->direction);
	// printf("vec x vec y	:	%i	/	%i\n", x, y);
	// printf("vec y	:	%i\n", y);

	// printf("x1/y1	:	%i	/	%i\n", data->player->x, data->player->y);
	// printf("x2/y2	:	%i	/	%i\n", data->player->x + x, data->player->y + y);
	// printf("***************************************\n");

	// printf("lx/ly	:	%i	/	%i\n", SQUARE * data->map_w, SQUARE * data->map_h);
	// printf("x2/y2	:	%i	/	%i\n", data->player->x + x, data->player->y + y);



	draw_lign(data, data->player->x, data->player->y, x, y, GREEN);

	x = find_x(data->player->direction + 90, 1000, data->player->x);
	y = find_y(data->player->direction + 90, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);

	x = find_x(data->player->direction + 180, 1000, data->player->x);
	y = find_y(data->player->direction + 180, 1000, data->player->y);
	draw_lign(data, data->player->x, data->player->y, x, y, WHITE);

	x = find_x(data->player->direction - 90, 1000, data->player->x);
	y = find_y(data->player->direction - 90, 1000, data->player->y);
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
		data->player->direction-= 3;
	}
	if (c == 'g')
	{
		data->player->direction+= 3;
	}
	if (data->player->direction >= 360)
		data->player->direction = 0;
	else if (data->player->direction < 0)
		data->player->direction = 359;
	ft_affiche_map(data);
}

int find_move_direction_player(t_data *data, char c)
{
	int	mv_direction;

	if (c == 'u')
		mv_direction = data->player->direction;
	if (c == 'd')
		mv_direction = data->player->direction + 180;
	if (c == 'g')
		mv_direction = data->player->direction + 90;
	if (c == 'r')
		mv_direction = data->player->direction - 90;
	return (mv_direction);
}

void	ft_move_player(t_data *data, char c)
{
	int	mv_direction;
	static float	x;
	static float	y;

	mv_direction = find_move_direction_player(data, c);

	x = find_x(mv_direction, 3, data->player->x);
	y = find_y(mv_direction, 3, data->player->y);


	// printf("mv_direction : %i\n", mv_direction);
	// printf("x/y : %i/ %i\n", x - data->player->x, y- data->player->y);

	data->player->x = x;
	data->player->y = y;
	// if (data->player->direction >= 360)
	// 	data->player->direction = 0;
	// else if (data->player->direction < 0)
	// 	data->player->direction = 359;
	ft_affiche_map(data);
}
