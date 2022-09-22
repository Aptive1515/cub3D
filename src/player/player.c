/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:11:23 by aptive            #+#    #+#             */
/*   Updated: 2022/09/21 23:23:00 by aptive           ###   ########.fr       */
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
	find_player_orientation(data);
	find_player_position(data);
}

int find_y(double angle, int distance, int origin_y)
{
	int vecteur_y;

	vecteur_y = (int)(sin(angle) * distance);
	if (angle > 0)
		vecteur_y *= -1;
	return (vecteur_y + origin_y);
}

int find_x(double angle, int distance, int origin_x)
{
	int vecteur_x;
	vecteur_x = (int)(cos(angle) * distance);


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
	// affichage_direction(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

}

void	ft_move_fov(t_data *data, char c)
{

	if (c == 'r')
	{
		data->player->direction-= 10 * ONE_DEGRE;
	}
	if (c == 'g')
	{
		data->player->direction+= 10 * ONE_DEGRE;
	}
	if (data->player->direction >= 2 * M_PI)
		data->player->direction = 0;
	else if (data->player->direction <= 0)
		data->player->direction = 2 * M_PI;


}

double find_move_direction_player(t_data *data, char c)
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
	// ft_affiche_map(data);
}
