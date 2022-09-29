/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:16:16 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 17:17:24 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_player(t_data *data)
{
	find_player_orientation(data);
	find_player_position(data);
}

int	find_y(double angle, int distance, int origin_y)
{
	int	vecteur_y;

	vecteur_y = (int)(sin(angle) * distance);
	if (angle > 0)
		vecteur_y *= -1;
	return (vecteur_y + origin_y);
}

int	find_x(double angle, int distance, int origin_x)
{
	int	vecteur_x;

	vecteur_x = (int)(cos(angle) * distance);
	return (vecteur_x + origin_x);
}
