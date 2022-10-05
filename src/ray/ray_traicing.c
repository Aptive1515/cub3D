/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_traicing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:26:50 by aptive            #+#    #+#             */
/*   Updated: 2022/10/05 16:21:59 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

double	calcul_delta(t_player *player, char c)
{
	if (c == 'X')
		return(player->x - (player->x/SQUARE) * SQUARE);
	else
		return(player->y - (player->y/SQUARE) * SQUARE);
}

void	calcul_tile_step(t_player *player, char c, int tile_step)
{
	if (c == 'Y')
	{
		if (tile_step == 1)
		{
			player->tile_Y_y = (player->y/SQUARE) * SQUARE - 1;
			player->tile_Y_x = player->x + (player->y  -player->tile_Y_y - 1) / player->tan_angle_ray;

		}
		else
		{
			player->tile_Y_y = (player->y/SQUARE) * SQUARE + SQUARE;
			player->tile_Y_x = player->x + (player->y  -player->tile_Y_y) / player->tan_angle_ray;
		}
	}
	else
	{

		if (tile_step == 1)
		{
			player->tile_X_x = (player->x/ SQUARE) * SQUARE + SQUARE;
			player->tile_X_y = player->y + (player->x - player->tile_X_x) * player->tan_angle_ray;


		}
		else
		{
			player->tile_X_x = (player->x/ SQUARE) * SQUARE - 1;
			player->tile_X_y = player->y + (player->x - player->tile_X_x - 1) * player->tan_angle_ray;
		}


	}
}

void next_intercept(t_player *player, double direction_ray, char c)
{
	(void)direction_ray;
	if (c == 'Y')
	{
		if (player->tile_step_Y == 1)
		{
			player->tile_Y_y -= (double)SQUARE; // YA
			player->tile_Y_x += player->delta_y; //XA
		}
		else
		{
			player->tile_Y_y += (double)SQUARE; //YA
			player->tile_Y_x -= player->delta_y; // XA
		}
	}
	else
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
}

int check_intersection(t_data *data, int x, int y)
{
	int	x_map;
	int	y_map;


	y_map = y / SQUARE;
	x_map = x / SQUARE;

	if (x_map > data->map_w - 1|| x_map <= 0 || y_map > data->map_h -1 || y_map <= 0)
	{
		ft_full(data, (x * SQUARE), (y * SQUARE), RED);
		return (1);
	}
	if (data->map[y_map][x_map] == '1')
	{
		// ft_full(data, (x_map * SQUARE), (y_map * SQUARE), GREEN);
		return (1);
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

	// if (x_map > data->map_w - 1 || x_map <= 0 || y_map > data->map_h - 1|| y_map <= 0)
	// 	return (1);
	// printf("y (SQUARE * y_map) : %i\n", (SQUARE * y_map));

	if(x % (SQUARE * x_map)|| y % (SQUARE * y_map))
	{
		if (data->map[y_map][x_map] == '1')
			return (1);
	}
	(void)data;
	return (0);
}

double distance(double x1, double y1, double x2, double y2)
{
	double x;
	double y;

	x = x2- x1;
	y = y2 - y1;
	return (sqrt(x * x + y * y));
}

double inter_pi(double angle_ray)
{
	if (angle_ray < 0)
		angle_ray += 2 * M_PI;
	else if (angle_ray > 2 * M_PI)
		angle_ray -= 2 * M_PI;
	return (angle_ray);
}

void	calcul_tile_step_Y(t_player *player, double angle_ray)
{
	if (angle_ray < M_PI )
		player->tile_step_Y = 1;
	else
		player->tile_step_Y = -1;
}

void	calcul_tile_step_X(t_player *player, double angle_ray)
{
	if (angle_ray < M_PI / 2 || angle_ray > 3 * M_PI / 2)
		player->tile_step_X = 1;
	else
		player->tile_step_X = -1;
}

void	affiche_wall(t_data *data, double distance_ray, int wall_x, double PB)
{
	double	wall_ha;
	int		y_c;
	int		y_f;

	wall_ha = wall_height_apparence(data->player, distance_ray) / 2;
	y_c = HEIGHT/2 - wall_ha;
	y_f = HEIGHT/2 + wall_ha;
	if (data->color_wall == WALL_N)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->tex_NO, 1);
	else if (data->color_wall == WALL_S)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->tex_SO, 1);
	else if (data->color_wall == WALL_E)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->tex_EA, 0);
	else if (data->color_wall == WALL_W)
		ft_lign_vertical_3d(data, wall_x, y_c, y_f, data->tex_WE, 0);
}

void	ray_traicing(t_data *data)
{
	double	fov;
	float	angle_ray;
	double	distance_ray;
	int		wall_x = WIDTH;
	t_player *player;
	int	i = 0;

	player = data->player;
	fov = -30 * ONE_DEGRE;
	while (fov <= 30 * ONE_DEGRE)
	{

		// Saut de 0 a PI
		angle_ray = inter_pi(data->player->direction + fov);

		player->tan_angle_ray = tan(angle_ray);
		player->absolu_cos_angle_ray = absolu_double(cos(angle_ray));



		// direction Pour les lignes verticale
		calcul_tile_step_Y(player, angle_ray);

		// direction pour les lignes horizontale
		calcul_tile_step_X(player, angle_ray);

		// calcule de la premiere intersection
		calcul_tile_step(player, 'Y', player->tile_step_Y);
		calcul_tile_step(player, 'X', player->tile_step_X);

		// calcule des instection suivante jusqu'a un mur
		player->delta_x = SQUARE * player->tan_angle_ray;
		player->delta_y = SQUARE / player->tan_angle_ray;


		while (!check_intersection(data, player->tile_Y_x, player->tile_Y_y))
			next_intercept(player, angle_ray, 'Y');
		while (!check_intersection(data, player->tile_X_x, player->tile_X_y))
			next_intercept(player, angle_ray, 'X');


		i++;
		// calucle de l'insterstion d' un mur le plus proche
		double PA = absolu(player->x - (int)player->tile_X_x) / player->absolu_cos_angle_ray;
		double PB = absolu(player->x - (int)player->tile_Y_x) / player->absolu_cos_angle_ray;
		// double PA = calcul_ray_distance(player->x, player->y, (int)player->tile_X_x, (int)player->tile_X_y);
		// double PB = calcul_ray_distance(player->x, player->y, (int)player->tile_Y_x, (int)player->tile_Y_y);


		if (PB < PA)
		{
			data->ray_x = player->tile_Y_x;
			data->ray_y = player->tile_Y_y;
			if (player->tile_step_Y > 0)
				data->color_wall = WALL_S;
			else
				data->color_wall = WALL_N;
		}
		else if ((PB > PA))
		{
			data->ray_x = player->tile_X_x;
			data->ray_y = player->tile_X_y;
			if (player->tile_step_X > 0)
				data->color_wall = WALL_E;
			else
				data->color_wall = WALL_W;
		}


		// calcule de la distance du rayon
		distance_ray = calcul_ray_distance(player->x, player->y, data->ray_x, data->ray_y);

		// delete le fish eye effect
		distance_ray = delete_fish_eye(distance_ray, fov);


		// affichage du mur;
		affiche_wall(data, distance_ray, wall_x, PB);



		wall_x--;
		fov += ONE_DEGRE * 60 / WIDTH;
	}
}


double	delete_fish_eye(double distance, double fov)
{
	return (absolu_double(distance * (cos(fov))));
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
