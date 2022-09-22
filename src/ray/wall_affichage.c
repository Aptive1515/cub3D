/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_affichage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:30:03 by aptive            #+#    #+#             */
/*   Updated: 2022/09/21 18:47:37 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_constante(t_data *data)
{
	data->player->distance_proj_plane = ((double)WIDTH / 2.0) / tanf(30 * ONE_DEGRE);
	data->forward = 0;
	data->backward = 0;
	data->forward = 0;
	data->backward = 0;
	data->go_right = 0;
	data->go_left = 0;
	data->turn_right = 0;
	data->turn_left = 0;
}

double	wall_height_apparence(t_player *player, double	distance_ray)
{

	double	wall_height_apparence;

	wall_height_apparence = (WALL_H / distance_ray) * player->distance_proj_plane;

	return (wall_height_apparence);
}

