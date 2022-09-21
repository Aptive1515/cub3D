/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:26:50 by aptive            #+#    #+#             */
/*   Updated: 2022/09/16 19:32:22 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	calcul_delta(t_data *data, char c)
{
	double tile;

	if (c == 'X')
	{

		tile = (data->player->x - (data->player->x/SQUARE) * SQUARE);
		// printf("delta x %f\n", tile);
	}
	else
	{
		tile = (data->player->y - (data->player->y/SQUARE) * SQUARE);
		// printf("delta y %f\n", tile);
	}


	return (tile);
}

// void	calcul_tile_step(t_data *data, double direction_ray, char c, int tile_step)
// {
// 	// printf ("direction_ray : %f\n", direction_ray);
// 	double delta_y;
// 	double delta_x;

// 	if (c == 'Y')
// 	{
// 		if (tile_step == 1)
// 		{
// 			delta_y = calcul_delta(data, 'Y');
// 			delta_x = calcul_delta(data, 'X');

// 		}
// 		else
// 		{
// 			delta_y = -calcul_delta(data, 'Y');
// 			delta_x = -calcul_delta(data, 'X');

// 		}

// 		data->player->tile_Y_y = data->player->y + delta_y;
//  		data->player->tile_Y_y = data->player->x + delta_x + delta_y / tan(direction_ray);

// 		// printf("first data->player->tile_Y_x : %f/ %i\n", data->player->tile_Y_x, (int)data->player->tile_Y_x / 32);
// 		// printf("first data->player->tile_Y_y : %f/ %i\n", data->player->tile_Y_y, (int)data->player->tile_Y_y / 32);
// 	}
// 	else
// 	{

// 		if (tile_step == 1)
// 		{
// 			delta_y = calcul_delta(data, 'Y');
// 			delta_x = calcul_delta(data, 'X');

// 		}
// 		else
// 		{
// 			delta_y = -calcul_delta(data, 'Y');
// 			delta_x = -calcul_delta(data, 'X');

// 		}
// 		data->player->tile_X_x = data->player->x + delta_x;
// 		data->player->tile_X_y = data->player->y + delta_y - delta_x/ tan(direction_ray);;
// 	}
// 	// printf(" tan %f\n",  tan(direction_ray * CONVERT_RAD));
// }

void	calcul_tile_step(t_data *data, double direction_ray, char c, int tile_step)
{
	// printf ("direction_ray : %f\n", direction_ray);
	if (c == 'Y')
	{
		if (tile_step == 1)
		{
			data->player->tile_Y_y = (data->player->y/SQUARE) * SQUARE - 1;
		}
		else
			data->player->tile_Y_y = (data->player->y/SQUARE) * SQUARE + SQUARE;

 		data->player->tile_Y_x = data->player->x + (data->player->y -data->player->tile_Y_y) / tan(direction_ray);

		// printf("first data->player->tile_Y_x : %f/ %i\n", data->player->tile_Y_x, (int)data->player->tile_Y_x / 32);
		// printf("first data->player->tile_Y_y : %f/ %i\n", data->player->tile_Y_y, (int)data->player->tile_Y_y / 32);
	}
	else
	{

		if (tile_step == 1)
		{
			data->player->tile_X_x = (data->player->x/ SQUARE) * SQUARE + SQUARE;
		}
		else
		{
			data->player->tile_X_x = data->player->x/ SQUARE * SQUARE - 1;

		}
		data->player->tile_X_y = data->player->y + (data->player->x - data->player->tile_X_x) * tan(direction_ray);;
	}
	// printf(" tan %f\n",  tan(direction_ray * CONVERT_RAD));
}

void next_intercept(t_data *data, double direction_ray, char c, int tile_step_Y, int tile_step_X)
{
	(void)direction_ray;
	if (c == 'Y')
	{
		if (tile_step_Y == 1)
			data->player->tile_Y_y -= (double)SQUARE; // YA
		else
			data->player->tile_Y_y += (double)SQUARE; //YA

		if (tile_step_Y == 1)
			data->player->tile_Y_x += data->player->delta_y; //XA
		else
			data->player->tile_Y_x -= data->player->delta_y; // XA
	}
	else
	{
		if (tile_step_X == 1)
			data->player->tile_X_x += (double)SQUARE;
		else
			data->player->tile_X_x -= (double)SQUARE;

		if (tile_step_X == 1)
			data->player->tile_X_y -= data->player->delta_x;
		else
			data->player->tile_X_y += data->player->delta_x;
	}
}

int check_intersection(t_data *data, int x, int y)
{
	int	x_map;
	int	y_map;

	x_map = x / SQUARE;
	y_map = y / SQUARE;


	if (x_map > data->map_w - 1|| x_map <= 0 || y_map > data->map_h -1 || y_map <= 0)
	{
		ft_full(data, (x * SQUARE), (y * SQUARE), RED);
		return (1);
	}
	// printf("y (SQUARE * y_map) : %i\n", (SQUARE * y_map));

	// if(x % (SQUARE * x_map) && y % (SQUARE * y_map))
	// {
	// 	if (data->map[y_map][x_map] == '1')
	// 	{
	// 		// ft_full(data, (x_map * SQUARE), (y_map * SQUARE), GREEN);
	// 		return (1);
	// 	}
	// }

	if(x - 1 % (SQUARE * x_map) && y - 1 % (SQUARE * y_map))
	{
		if (data->map[y_map][x_map] == '1')
		{
			// ft_full(data, (x_map * SQUARE), (y_map * SQUARE), GREEN);
			return (1);
		}
	}




	return (0);
}

int	verif_wall(t_data *data, int x, int y)
{
	int	x_map;
	int	y_map;

	x_map = x / SQUARE;
	y_map = y / SQUARE;
	// printf("xp / y :	%i / %i\n", x, y);
	// printf("x_map / y_map :	%i / %i\n", x_map, y_map);

	if (x_map > data->map_w - 1 || x_map <= 0 || y_map > data->map_h - 1|| y_map <= 0)
		return (1);
	// printf("y (SQUARE * y_map) : %i\n", (SQUARE * y_map));

	if(x % (SQUARE * x_map)|| y % (SQUARE * y_map))
	{
		if (data->map[y_map][x_map] == '1')
			return (1);
	}
	(void)data;
	return (0);
}

double distance (double x1, double y1, double x2, double y2)
{
	double x;
	double y;

	x = x2- x1;
	y = y2 - y1;
	return (sqrt(x * x + y * y));
}
void	ray_traicing(t_data *data)
{

	double	fov;
	float	angle_ray;
	double	distance_ray;
	double	wall_ha;
	int		y_c;
	int		y_f;
	int		wall_x = WIDTH;

	fov = -30 * ONE_DEGRE;
	while (fov <= 30 * ONE_DEGRE)
	{

		// Saut de 0 a PI
		angle_ray = data->player->direction + fov;
		if (angle_ray < 0)
			angle_ray += 2 * M_PI;
		else if (angle_ray > 2 * M_PI)
			angle_ray -= 2 * M_PI;


		// direction Pour les lignes verticale
		if (angle_ray < M_PI )
			data->player->tile_step_y = 1;
		else
			data->player->tile_step_y = -1;

		// direction pour les lignes horizontale
		if (angle_ray < M_PI / 2 || angle_ray > 3 * M_PI / 2)
			data->player->tile_step_x = 1;
		else
			data->player->tile_step_x = -1;

		// calcule de la premiere intersection
		calcul_tile_step(data, angle_ray, 'Y', data->player->tile_step_y);
		calcul_tile_step(data, angle_ray, 'X', data->player->tile_step_x);


		// calcule des instection suivante jusqu'a un mur
		data->player->delta_x = SQUARE * tan(angle_ray);
		data->player->delta_y = SQUARE / tan(angle_ray);
		while (!check_intersection(data, data->player->tile_Y_x, data->player->tile_Y_y))
			next_intercept(data, angle_ray, 'Y', data->player->tile_step_y, data->player->tile_step_x);
		while (!check_intersection(data, data->player->tile_X_x, data->player->tile_X_y))
			next_intercept(data, angle_ray, 'X', data->player->tile_step_y, data->player->tile_step_x);


		// calucle de l'insterstion d' un mur le plus proche
		float PA = absolu(data->player->x - data->player->tile_X_x) / absolu_float((float)cos(angle_ray));
		float PB = absolu(data->player->x - data->player->tile_Y_x) / absolu_float((float)cos(angle_ray));
		if ( PB < PA )
		{
			data->ray_x = data->player->tile_Y_x;
			data->ray_y = data->player->tile_Y_y;
			if (data->player->tile_step_y > 0)
				data->color_wall = WALL_E;
			else
				data->color_wall = WALL_W;
		}
		else
		{
			data->ray_x = data->player->tile_X_x;
			data->ray_y = data->player->tile_X_y;
			if (data->player->tile_step_x > 0)
				data->color_wall = WALL_S;
			else
				data->color_wall = WALL_N;
		}


	draw_lign(data, data->player->x, data->player->y, data->ray_x, data->ray_y, WHITE);

		// calcule de la distance du rayon
		distance_ray = calcul_ray_distance(data->player->x, data->player->y, data->ray_x, data->ray_y);

		// delete le fish eye effect
		distance_ray = delete_fish_eye(data, distance_ray, fov);



		// affichage du mur;
		wall_ha = (double)wall_height_apparence(distance_ray) / 2;
		y_c = HEIGHT/2 - wall_ha;
		y_f = HEIGHT/2 + wall_ha;
		if (y_c < 0)
			y_c = 0;
		if (y_c > HEIGHT)
			y_c = HEIGHT;
		if (data->color_wall == WALL_N)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->path->texture_NO);
		else if (data->color_wall == WALL_S)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->path->texture_SO);
		else if (data->color_wall == WALL_E)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->path->texture_EA);
		else if (data->color_wall == WALL_W)
			ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->path->texture_WE);

		wall_x--;
		fov += ONE_DEGRE * 60 / WIDTH;
	}
}


double	delete_fish_eye(t_data *data, double distance, double angle_ray)
{
	double	new_distance;
	(void)data;

	// if (angle_ray > data->player->direction)
	// 	new_distance = distance * (cos(angle_ray));
	// else
		new_distance = distance * absolu_float(cos(angle_ray));
	// printf("*************************\n");
	// printf("(fov) 	: %f\n",fov);
	// printf("(fov_inverse) 	: %f\n", 90 - absolu_float(fov));
	// printf("angle 	: %f\n", angle);
	// printf("cosf(angle) : %f\n", cosf(angle));
	// // printf("absolu(fov) : %f\n", absolu_float(fov));
	// printf("distance 	: %i\n", distance);
	// printf("new distance 	: %i\n", new_distance);

	return (absolu_float((double)(new_distance)));
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
		else// dx < 0
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
