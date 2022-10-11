/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:26:50 by aptive            #+#    #+#             */
/*   Updated: 2022/10/11 14:56:37 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	calcul_angle_ray(t_data *data, int wall_x)
{
	return ((atan((wall_x - data->screen_h / 2)
				/ data->player->distance_proj_plane)));
}

void	calcul_tile_step_y(t_player *player, double angle_ray)
{
	if (angle_ray < M_PI)
		player->tile_step_y = 1;
	else
		player->tile_step_y = -1;
}

void	calcul_tile_step_x(t_player *player, double angle_ray)
{
	if (angle_ray < M_PI / 2 || angle_ray > 3 * M_PI / 2)
		player->tile_step_x = 1;
	else
		player->tile_step_x = -1;
}

void	ray_traicing(t_data *data)
{
	double		fov;
	double		angle_ray;
	double		dis_ray;
	int			wall_x;
	t_player	*player;

	wall_x = data->screen_w;
	player = data->player;
	fov = -30 * ONE_DEGRE;
	while (wall_x >= 0)
	{
		angle_ray = inter_pi(data->player->direction + fov);
		player->tan_angle_ray = tan(angle_ray);
		player->ab_cos_angle_ray = absolu_double(cos(angle_ray));
		calcul_tile_step_y(player, angle_ray);
		calcul_tile_step_x(player, angle_ray);
		dda(data, player);
		witch_ray(data, player);
		dis_ray = ray_distance(player->x, player->y, data->ray_x, data->ray_y);
		dis_ray = delete_fish_eye(dis_ray, fov);
		affiche_wall(data, dis_ray, wall_x);
		fov = calcul_angle_ray(data, wall_x);
		wall_x--;
	}
}

void	witch_ray(t_data *data, t_player *player)
{
	double		pa;
	double		pb;

	pa = absolu(player->x - (int)player->tile_x_x) / player->ab_cos_angle_ray;
	pb = absolu(player->x - (int)player->tile_y_x) / player->ab_cos_angle_ray;
	if (pb < pa)
	{
		data->ray_x = player->tile_y_x;
		data->ray_y = player->tile_y_y;
		if (player->tile_step_y > 0)
			data->color_wall = WALL_S;
		else
			data->color_wall = WALL_N;
	}
	else
	{
		data->ray_x = player->tile_x_x;
		data->ray_y = player->tile_x_y;
		if (player->tile_step_x > 0)
			data->color_wall = WALL_E;
		else
			data->color_wall = WALL_W;
	}
}
