/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:25:56 by aptive            #+#    #+#             */
/*   Updated: 2022/09/17 15:05:56 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	absolu(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

float	absolu_float(float nb)
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

double	calcul_ray_distance(double	x, double y, double x2, double y2)
{
	double	dis_x;
	double	dis_y;

	// printf("x / y : %i / %i\n", x, y);
	// printf("x2 / y2 : %i / %i\n", x2, y2);

	dis_x = calcul_distance_square(x, x2);
	dis_y = calcul_distance_square(y, y2);

	// printf("*******************************\n");
	// printf("x / y : %i / %i\n", x, y);
	// printf("x2 / y2 : %i / %i\n", x2, y2);
	// printf("sqrt(dis_x + dis_y): %f\n", sqrt(dis_x + dis_y));

	return(sqrt(dis_x + dis_y));
}

int find_y_float(float angle, int distance, int origin_y)
{
	int vecteur_y;

	// printf("cos x : %f\n", cos(angle * 3.14/180));
	vecteur_y = (int)(cos(angle * 3.14/180) * distance);
	return (vecteur_y + origin_y);
}

int find_x_float(float angle, int distance, int origin_x)
{
	int vecteur_x;
	vecteur_x = (int)(sin(angle * 3.14/180) * distance);
	return (vecteur_x + origin_x);
}
