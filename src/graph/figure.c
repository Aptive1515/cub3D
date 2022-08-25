/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:02:53 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 00:21:54 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_lign_vertical(t_data *data, int x, int y, int y_end, int color)
{
	while (y < y_end)
	{
		my_mlx_pixel_put_limit(data, x, y, color);
		y++;
	}
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

// void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, int color)
// {
// 	while (y < y_end)
// 	{
// 		my_mlx_pixel_put_3d(data, x, y, color);
// 		y++;
// 	}
// 	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// }

void	ft_lign_horizontal_3d(t_data *data, int x, int x_end, int y,int color)
{
	while (x < x_end)
	{
		my_mlx_pixel_put_limit(data, x, y, color);
		x++;
	}
}

void	ft_lign_horizontal(t_data *data, int x, int x_end, int y,int color)
{
	while (x < x_end)
	{
		my_mlx_pixel_put_limit(data, x, y, color);
		x++;
	}
}

void ft_grille(t_data *data)
{
	int i;
	int height;
	int width;

	height = data->map_h * SQUARE;
	width = data->map_w * SQUARE;

	i = 0;
	(void)data;
	while (i < width)
	{
		ft_lign_vertical(data, i, 0, height, RED);
		i += SQUARE;
	}
	i = 0;
	while (i < height)
	{
		ft_lign_horizontal(data, 0, width, i, RED);
		i += SQUARE;
	}
}

void	ft_full(t_data *data, int x_beg, int y_beg, int color)
{
	int	x_end;
	int	y_end;
	// printf("HERE\n");

	x_end = x_beg + SQUARE;
	y_end = y_beg + SQUARE;
	while (x_beg < x_end)
	{
		ft_lign_vertical(data, x_beg, y_beg + 1, y_end, color);
		x_beg++;
	}
}

void	do_circle(t_data *data, int r, int x_centre, int y_centre, int color)
{
	int	x;
	int	y;
	int d;

	x = 0;
	y = r;
	d = r - 1;
	while (x <= y)
	{
		my_mlx_pixel_put_limit(data, x_centre + x , y_centre + y, color);
		my_mlx_pixel_put_limit(data, x_centre + y , y_centre + x, color);
		my_mlx_pixel_put_limit(data, x_centre - x , y_centre + y, color);
		my_mlx_pixel_put_limit(data, x_centre - y , y_centre + x, color);
		my_mlx_pixel_put_limit(data, x_centre + x , y_centre - y, color);
		my_mlx_pixel_put_limit(data, x_centre + y , y_centre - x, color);
		my_mlx_pixel_put_limit(data, x_centre - x , y_centre - y, color);
		my_mlx_pixel_put_limit(data, x_centre - y , y_centre - x, color);
		if (d >= 2 * x)
		{
			d = d - 2 * x - 1;
			x++;
		}
		else if (d < 2* (r - y))
		{
			d = d + 2 * y - 1;
			y = y - 1;
		}
		else
		{
			d = d + 2 * (y - x - 1);
			y--;
			x++;
		}
	}
}
int ft_absolu(int nb)
{
	if (nb < 0)
		nb =-nb;
	return (nb);
}

void full_circle(t_data *data, int r, int x_centre, int y_centre, int color)
{
	while (r >= 0)
	{
		do_circle(data, r, x_centre, y_centre, color);
		r--;
	}
}

void draw_lign(t_data *data, int x1, int y1, int x2, int y2, int color)
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, BLUE);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
					my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
					if (verif_wall(data, x1 , y1))
						break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
							my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
							if (verif_wall(data, x1 , y1))
								break;
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
					my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
					if (verif_wall(data, x1 , y1))
						break;
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
					my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
					if (verif_wall(data, x1 , y1))
						break;
					y1++;
				}
			}
			else  // dy < 0 (et dx = 0)
			{
				while (y1 != y2)
				{
					my_mlx_pixel_put_limit_wall(data, x1 , y1, color);
					if (verif_wall(data, x1 , y1))
						break;
					y1--;
				}
			}
		}
	}
	// le pixel final (x2, y2) n’est pas tracé.
}
