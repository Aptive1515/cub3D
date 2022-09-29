/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:25:56 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 18:04:58 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	absolu(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

double	absolu_double(double nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

double	calcul_distance_square(double x1, double x2)
{
	double	x_tmp;

	x_tmp = (double)(x2) - (x1);
	return (x_tmp * x_tmp);
}

double	ray_distance(double x, double y, double x2, double y2)
{
	double	dis_x;
	double	dis_y;

	dis_x = calcul_distance_square(x, x2);
	dis_y = calcul_distance_square(y, y2);
	return (sqrt(dis_x + dis_y));
}

double	inter_pi(double angle_ray)
{
	if (angle_ray < 0)
		angle_ray += 2 * M_PI;
	else if (angle_ray > 2 * M_PI)
		angle_ray -= 2 * M_PI;
	return (angle_ray);
}

// int	find_y_float(float angle, int distance, int origin_y)
// {
// 	int	vecteur_y;

// 	vecteur_y = (int)(cos(angle * 3.14 / 180) * distance);
// 	return (vecteur_y + origin_y);
// }

// int	find_x_float(float angle, int distance, int origin_x)
// {
// 	int	vecteur_x;

// 	vecteur_x = (int)(sin(angle * 3.14/180) * distance);
// 	return (vecteur_x + origin_x);
// }
