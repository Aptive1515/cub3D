/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:10:41 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 18:18:15 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calcul_tile_step_y_y(t_player *p, int tile_step)
{
	if (tile_step == 1)
	{
		p->tile_Y_y = (p->y / SQUARE) * SQUARE - 1;
		p->tile_Y_x = p->x + (p->y - p->tile_Y_y - 1) / p->tan_angle_ray;
	}
	else
	{
		p->tile_Y_y = (p->y / SQUARE) * SQUARE + SQUARE;
		p->tile_Y_x = p->x + (p->y - p->tile_Y_y) / p->tan_angle_ray;
	}
}

void	calcul_tile_step_x_x(t_player *p, int tile_step)
{
	if (tile_step == 1)
	{
		p->tile_X_x = (p->x / SQUARE) * SQUARE + SQUARE;
		p->tile_X_y = p->y + (p->x - p->tile_X_x) * p->tan_angle_ray;
	}
	else
	{
		p->tile_X_x = (p->x / SQUARE) * SQUARE - 1;
		p->tile_X_y = p->y + (p->x - p->tile_X_x - 1) * p->tan_angle_ray;
	}
}

void	next_intercept_y(t_player *player)
{
	if (player->tile_step_Y == 1)
	{
		player->tile_Y_y -= (double)SQUARE;
		player->tile_Y_x += player->delta_y;
	}
	else
	{
		player->tile_Y_y += (double)SQUARE;
		player->tile_Y_x -= player->delta_y;
	}
}

void	next_intercept_x(t_player *player)
{
	if (player->tile_step_X == 1)
	{
		player->tile_X_x += (double)SQUARE;
		player->tile_X_y -= player->delta_x;
	}
	else
	{
		player->tile_X_x -= (double)SQUARE;
		player->tile_X_y += player->delta_x;
	}
}
