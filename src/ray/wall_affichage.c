/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_affichage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:30:03 by aptive            #+#    #+#             */
/*   Updated: 2022/10/05 16:53:39 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_constante(t_data *data)
{
	data->player->distance_proj_plane
		= ((double)WIDTH / 2.0) / tanf(30 * ONE_DEGRE);
	data->forward = 0;
	data->backward = 0;
	data->forward = 0;
	data->backward = 0;
	data->go_right = 0;
	data->go_left = 0;
	data->turn_right = 0;
	data->turn_left = 0;
}

double	wall_height_apparence(t_player *player, double distance_ray)
{
	double	wall_height_apparence;

	wall_height_apparence
		= (WALL_H / distance_ray) * player->distance_proj_plane;
	return (wall_height_apparence);
}

void	affiche_wall(t_data *data, double distance_ray, int wall_x)
{
	double	wall_ha;
	int		y_c;
	int		y_f;

	wall_ha = wall_height_apparence(data->player, distance_ray) / 2;
	y_c = data->screen_h / 2 - wall_ha;
	y_f = data->screen_h / 2 + wall_ha;
	if (data->color_wall == WALL_N)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f,data->tex_NO, 0);
	else if (data->color_wall == WALL_S)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f,data->tex_SO, 0);
	else if (data->color_wall == WALL_E)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f,data->tex_EA, 1);
	else if (data->color_wall == WALL_W)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f,data->tex_WE, 1);
}

double	delete_fish_eye(double distance, double fov)
{
	return (absolu_double(distance * (cos(fov))));
}
