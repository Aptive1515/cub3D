/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:26:50 by aptive            #+#    #+#             */
/*   Updated: 2022/08/24 18:53:38 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	absolu(int nb)
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

	printf("*******************************\n");
	printf("x / y : %i / %i\n", x, y);
	printf("x2 / y2 : %i / %i\n", x2, y2);
	printf("sqrt(dis_x + dis_y): %f\n", sqrt(dis_x + dis_y));

	return(sqrt(dis_x + dis_y));
}

int	wall_height_apparence(int	distance_ray)
{
	float	tan_alpha;
	float	wall_height_apparence;

	tan_alpha = (float)WALL_H / (float)HORIZON;
	wall_height_apparence = ((float)HORIZON - (float)distance_ray) / tan_alpha;

	printf("*******************\n");
	printf("distance_ray : %i\n", distance_ray);
	// printf("WALL_H : %i\n", WALL_H);
	// printf("HORIZON : %i\n", HORIZON);
	// printf("tan_alpha : %f\n", tan_alpha);
	printf("Wall height apparence : %f\n", wall_height_apparence);




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

void	ray_traicing(t_data *data)
{
	(void)data;
	int	x;
	int	y;
	int	fov;
	int	distance_ray;
	int	wall_ha;

	fov = -30;

		int y_c;
		int	y_f;

	// while (y_c <= y_f)
	// {

	// 	my_mlx_pixel_put_3d(data, 100, y_c, RED);
	// 	y_c++;
	// }
	int	wall_x = WIDTH;

	while (fov <= 30)
	{

		x = find_x(data->player->direction + fov, 1000, data->player->x);
		y = find_y(data->player->direction + fov, 1000, data->player->y);
		ray_way(data, data->player->x, data->player->y, x, y);
		// printf("data->ray_x : %i\n", data->ray_x);
		// printf("data->ray_y : %i\n", data->ray_y);
		distance_ray = calcul_ray_distance(data->player->x, data->player->y, data->ray_x, data->ray_y);
		// printf("distance_ray : %i\n", distance_ray);
		wall_ha = (int)wall_height_apparence(distance_ray);

		y_c = HEIGHT/2 - wall_ha;
		y_f = HEIGHT/2 + wall_ha;
		// printf("wall_ha : %i\n", wall_ha);
		// printf("y_c : %i\n", y_c);
		// printf("y_f : %i\n", y_f);
		if (fov == -30 || fov == 0 || fov == 30)
			printf("Wall height apparence : %d\n", wall_ha);


		ft_lign_vertical_3d(data, wall_x, y_c, y_f, RED);
		wall_x -= WIDTH / 60;
		fov++;
	}
	(void)y_c;
	(void)y_f;
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
								break;
							}
							x1++;
							e -= dy;
							if (e < 0)
							{
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
								break;
							}
							y1++;
							e -= dx;
							if (e < 0)
							{
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
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1++;
							e += dy;
							if (e < 0)
							{
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
								break;
							}
							y1--;
							e += dx;
							if (e > 0)
							{
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
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1--;
							e += dy;
							if (e >= 0)
							{
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
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							y1++;
							e += dx;
							if (e <= 0)
							{
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
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							x1--;
							e -= dy;
							if (e >= 0)
							{
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
								data->ray_x = x1;
								data->ray_y = y1;
								break;
							}
							y1 = y1 - 1;
							e -= dx;
							if (e >= 0)
							{
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
