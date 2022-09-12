/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_affichage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:30:03 by aptive            #+#    #+#             */
/*   Updated: 2022/09/12 15:25:48 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	wall_height_apparence(double	distance_ray)
{

	double	wall_height_apparence;

	double distance_proj_plane = ((double)WIDTH / 2.0) / tanf(30 * ONE_DEGRE);
	wall_height_apparence = (WALL_H / (double)distance_ray) * distance_proj_plane;

	return (wall_height_apparence);
}

void	ft_color_wall(t_data *data)
{
	(void)data;
}
