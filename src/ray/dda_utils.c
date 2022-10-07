/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:10:41 by aptive            #+#    #+#             */
/*   Updated: 2022/10/07 20:16:18 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calcul_tile_step_y_y(t_player *p, int tile_step)
{
	if (tile_step == 1)
	{
		p->tile_y_y = (p->y / SQUARE) * SQUARE - 1;
		p->tile_y_x = p->x + (p->y - p->tile_y_y - 1) / p->tan_angle_ray;
	}
	else
	{
		p->tile_y_y = (p->y / SQUARE) * SQUARE + SQUARE;
		p->tile_y_x = p->x + (p->y - p->tile_y_y) / p->tan_angle_ray;
	}
}

void	calcul_tile_step_x_x(t_player *p, int tile_step)
{
	if (tile_step == 1)
	{
		p->tile_x_x = (p->x / SQUARE) * SQUARE + SQUARE;
		p->tile_x_y = p->y + (p->x - p->tile_x_x) * p->tan_angle_ray;
	}
	else
	{
		p->tile_x_x = (p->x / SQUARE) * SQUARE - 1;
		p->tile_x_y = p->y + (p->x - p->tile_x_x - 1) * p->tan_angle_ray;
	}
}

void	next_intercept_y(t_player *player)
{
	if (player->tile_step_y == 1)
	{
		player->tile_y_y -= (double)SQUARE;
		player->tile_y_x += player->delta_y;
	}
	else
	{
		player->tile_y_y += (double)SQUARE;
		player->tile_y_x -= player->delta_y;
	}
}

void	next_intercept_x(t_player *player)
{
	if (player->tile_step_x == 1)
	{
		player->tile_x_x += (double)SQUARE;
		player->tile_x_y -= player->delta_x;
	}
	else
	{
		player->tile_x_x -= (double)SQUARE;
		player->tile_x_y += player->delta_x;
	}
}
