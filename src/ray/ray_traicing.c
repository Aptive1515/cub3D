/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:26:50 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 03:22:09 by aptive           ###   ########.fr       */
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

int	calcul_distance_square(int x1, int x2)
{
	int	x_tmp;

	x_tmp = (x2) - (x1);
	return(x_tmp * x_tmp);
}

int	calcul_ray_distance(int	x, int y, int x2, int y2)
{
	int	dis_x;
	int	dis_y;

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

int	wall_height_apparence(int	distance_ray)
{
	float	tan_alpha;
	float	wall_height_apparence;

	tan_alpha = (float)WALL_H/2 / (float)HORIZON;
	wall_height_apparence = ((float)HORIZON - (float)distance_ray) * tan_alpha;

	printf("*******************\n");
	// printf("distance_ray : %i\n", distance_ray);
	// // printf("WALL_H : %i\n", WALL_H);
	// // printf("HORIZON : %i\n", HORIZON);
	// // printf("tan_alpha : %f\n", tan_alpha);
	// printf("Wall height apparence : %f\n", wall_height_apparence);




	return (wall_height_apparence);
}

void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, int color)
{
	while (y < y_end)
	{
		my_mlx_pixel_put_3d(data, x, y, color);
		y++;
	}
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_color_wall(t_data *data)
{
	int	vecteur_x;
	int	vecteur_y;


	vecteur_x = data->ray_x/32 - data->ray_x_before/32;
	vecteur_y = data->ray_y/32 - data->ray_y_before/32;

	// printf("data->ray_x_before : %i\n", vecteur_x);
	// printf("data->ray_y_before : %i\n", vecteur_y);

	if (vecteur_x > 1 && vecteur_y == 0)
		data->color_wall = WALL_N;
	if (vecteur_x < 1 && vecteur_y == 0)
		data->color_wall = WALL_S;
	if (vecteur_x == 0 && vecteur_y < 0)
		data->color_wall = WALL_E;
	if (vecteur_x == 0 && vecteur_y > 0)
		data->color_wall = WALL_W;


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

int	delete_fish_eye(int distance, float fov)
{
	int	new_distance;
	float angle;

	// if(fov == 0)
	// 	return (distance);

 	angle = ( fov )* 3.14 / 180;
	new_distance = distance * cosf(angle);
	// printf("*************************\n");
	// printf("(fov) 	: %f\n",fov);
	// printf("(fov_inverse) 	: %f\n", 90 - absolu_float(fov));
	// printf("angle 	: %f\n", angle);
	// printf("cosf(angle) : %f\n", cosf(angle));
	// // printf("absolu(fov) : %f\n", absolu_float(fov));
	// printf("distance 	: %i\n", distance);
	// printf("new distance 	: %i\n", new_distance);

	return ((new_distance));
}

void	ray_traicing(t_data *data)
{
	(void)data;
	int	x;
	int	y;
	float	fov;
	int	distance_ray;
	int	wall_ha;
	int	i;

	i = 0;
	fov = -30;

		int y_c;
		int	y_f;

	// while (y_c <= y_f)
	// {

	// 	my_mlx_pixel_put_3d(data, 100, y_c, RED);
	// 	y_c++;
	// }
	int	wall_x = WIDTH;

	while (fov <= 31)
	{

		x = find_x_float((float)data->player->direction + fov, 1000, data->player->x);
		y = find_y_float((float)data->player->direction + fov, 1000, data->player->y);

		// printf("x / y : %i / %i\n", x, y);
		ray_way(data, data->player->x, data->player->y, x, y);
		// printf("data->ray_x : %i\n", data->ray_x);
		// printf("data->ray_y : %i\n", data->ray_y);
		distance_ray = calcul_ray_distance(data->player->x, data->player->y, data->ray_x, data->ray_y);
		// distance_ray = delete_fish_eye(distance_ray, fov);

		printf("distance_ray : %i\n", distance_ray);
		wall_ha = (int)wall_height_apparence(distance_ray);

		y_c = HEIGHT/2 - wall_ha;
		y_f = HEIGHT/2 + wall_ha;
		// printf("wall_ha : %i\n", wall_ha);
		// printf("y_c : %i\n", y_c);
		// printf("y_f : %i\n", y_f);
		// if (fov == -30 || fov == 0 || fov == 30)
			printf("Wall height apparence : %d\n", wall_ha);


		ft_color_wall(data);

		if (data->color_wall == WALL_N)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, RED);
		else if (data->color_wall == WALL_S)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, GREEN);
		else if (data->color_wall == WALL_E)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, BLUE);
		else if (data->color_wall == WALL_W)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, WHITE);
		// printf("i : %i\n", i);
		// printf("fov : %f\n", fov);
		// printf("60/WIDTH : %d\n", 60/WIDTH);
		i++;
		wall_x--;
		fov = fov + 0.075;
		// fov++;
	}
	(void)y_c;
	(void)y_f;
	(void)i;
}



void ray_way(t_data *data, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	e;

	dx = x2 - x1;
	if (dx != 0)
	{
		if (dx > 0)
		{
			dy = y2 - y1;
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						dx = (e = dx) * 2;
						dy = dy *2;
						while (x1 != x2)
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x = x1;
								data->ray_y = y1;

								data->ray_x_before = x1 - 1;


								break;
							}
							x1++;
							e -= dy;
							if (e < 0)
							{
								data->ray_y_before = y1;
								y1++ ; // déplacement diagonal
								e += dx ;
							}
						}
					}
					else
					{
						dx = dx * 2;
						e = dy *2;
						dy = e;
						while (y1 != y2)
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x = x1;
								data->ray_y = y1;
								data->ray_y_before = y1 - 1;
								break;
							}
							y1++;
							e -= dx;
							if (e < 0)
							{
								data->ray_x_before = x1;
								x1++;
								e += dy ;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						dx = (e = dx) * 2 ;
						dy = dy * 2 ;
						while (x1 != x2)
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x_before = x1 - 1;
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1++;
							e += dy;
							if (e < 0)
							{
								data->ray_x_before = y1;
								y1--;
								e += dx ;
							}
						}
					}
					else  // vecteur oblique proche de la verticale, dans le 7e octant
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2 ;
						while (y1 != y2)
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x = x1;
								data->ray_y = y1;
								data->ray_y_before = y1 + 1;
								break;
							}
							y1--;
							e += dx;
							if (e > 0)
							{
								data->ray_x_before = x1;
								x1++ ;  // déplacement diagonal
								e += dy ;
							}
						}
					}
				}
			}
			else  // dy = 0 (et dx > 0)
			{
				// vecteur horizontal vers la droite
				while (x1 != x2)
				{
					if (verif_wall(data, x1 , y1))
						{
							data->ray_y_before = y1;
							data->ray_x_before = x1 - 1;
							data->ray_x = x1;
							data->ray_y = y1;
							break;
						}
					x1++;
				}
			}
		}
		else  // dx < 0
		{
			dy = y2 - y1;
			if (dy != 0 )
			{
				if (dy > 0)
				{
				// vecteur oblique dans le 2d cadran

					if (-dx >= dy)
					{
						// vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
						dx = (e = dx) * 2 ;
						dy = dy * 2 ;  // e est négatif
						while (x1 != x2)  // déplacements horizontaux
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x_before = x1 + 1;
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1--;
							e += dy;
							if (e >= 0)
							{
								data->ray_y_before = y1;
								y1++ ;  // déplacement diagonal
								e += dx ;
							}
						}
					}
					else
					{

						// vecteur oblique proche de la verticale, dans le 3e octant

						e = dy * 2 ;
						dy = e;
						dx = dx * 2 ;  // e est poiftif
						while (y1 != y2)  // déplacements verticaux
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_y_before = y1 - 1;
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							y1++;
							e += dx;
							if (e <= 0)
							{
								data->ray_x_before = x1;
								x1-- ;  // déplacement diagonal
								e += dy ;
							}
						}
					}
				}
				else  // dy < 0 (et dx < 0)
				// vecteur oblique dans le 3e cadran
				{
					if (dx <= dy)
					{
						// vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
						dx = (e = dx) * 2 ;
						dy = dy * 2 ;  // e est négatif
						while (x1 != x2)  // déplacements horizontaux
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_x_before = x1 + 1;
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1--;
							e -= dy;
							if (e >= 0)
							{
								data->ray_y_before = y1;
								y1-- ;
								e += dx ;
							}
						}
					}
					else  // vecteur oblique proche de la verticale, dans le 6e octant
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (y1 != y2)
						{
							if (verif_wall(data, x1 , y1))
							{
								data->ray_y_before = y1 + 1;
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							y1--;
							e -= dx;
							if (e >= 0)
							{
								data->ray_x_before = x1;
								--x1;
								e += dy;
							}
						}
					}
				}
			}
			else  // dy = 0 (et dx < 0)
			{
				while (x1 != x2)
				{
					if (verif_wall(data, x1 , y1))
					{
						data->ray_y_before = y1;
						data->ray_x_before = x1 + 1;
						data->ray_x = x1;
						data->ray_y = y1;
						break;
					}
					x1--;
				}
			}
		}
	}
	else  // dx = 0
	{
		dy = y2 - y1;
		if (dy != 0)
		{
			if (dy > 0)
			{
				// vecteur vertical croissant
				while (y1 != y2)
				{
					if (verif_wall(data, x1 , y1))
					{
						data->ray_y_before = y1 - 1;
						data->ray_x_before = x1;
						data->ray_x = x1;
						data->ray_y = y1;
						break;
					}
					y1++;
				}
			}
			else  // dy < 0 (et dx = 0)
			{
				while (y1 != y2)
				{
					if (verif_wall(data, x1 , y1))
						{
							data->ray_x_before = x1;
							data->ray_y_before = y1 + 1;
							data->ray_x = x1;
							data->ray_y = y1;
							break;
						}
					y1--;
				}
			}
		}
	}
	// le pixel final (x2, y2) n’est pas tracé.
}
