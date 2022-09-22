/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:09 by aptive            #+#    #+#             */
/*   Updated: 2022/09/22 15:54:31 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void affiche_celling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->screen_h / 2)
	{
		x = 0;
		while (x < data->screen_w)
		{
			my_mlx_pixel_put_3d(data, x, y, create_trgb(0, ft_atoi(data->ceiling_rgb[0]), ft_atoi(data->ceiling_rgb[1]), ft_atoi(data->ceiling_rgb[2])));
			x++;
		}
		y++;
	}
}

void affiche_floor(t_data *data)
{
	int	x;
	int	y;

	y = data->screen_h / 2;
	while (y <= data->screen_h)
	{
		x = 0;
		while (x < data->screen_w)
		{
			my_mlx_pixel_put_3d(data, x, y, create_trgb(0, ft_atoi(data->floor_rgb[0]), ft_atoi(data->floor_rgb[1]), ft_atoi(data->floor_rgb[2])));
			x++;
		}
		y++;
	}
}

void	ft_affiche_map(t_data *data)
{
	// int		y;
	// int		x;
	// mlx_destroy_display(data->mlx);
	// mlx_destroy_image(data->mlx, data->mlx_win);
	// mlx_clear_window(data->mlx, data->mlx_win);

	affiche_celling(data);
	affiche_floor(data);

	// y = 0;
	// while (y < data->map_h)
	// {
	// 	x = 0;
	// 	while (x < data->map_w)
	// 	{
	// 		if (x < (int)ft_strlen(data->map[y]))
	// 		{
	// 			if (data->map[y][x] == '1')
	// 				ft_full(data, (x * SQUARE), (y * SQUARE), BLUE);
	// 			if (data->map[y][x] != '1')
	// 				ft_full(data, (x * SQUARE), (y * SQUARE), BLACK);
	// 		}
	// 			x++;
	// 		// if (data->map[y][x] == 'N')
	// 		// // {
	// 		// 	ft_full(data, (x * SQUARE), (y * SQUARE), WHITE);
	// 		// 	// full_circle(data, SQUARE/3, (x * SQUARE) + SQUARE/2, (y * SQUARE) + SQUARE/2, BLUE);
	// 		// }
	// 			// ft_affichage_wall(vars, y, x);
	// 		// if (vars->map[y][x] == '0' || vars->map[y][x] == 'P'
	// 		// 	|| vars->map[y][x] == 'E' || vars->map[y][x] == 'C')
	// 		// 	ft_affichage_floor(vars, y, x);
	// 		// if (vars->map[y][x] == 'P')
	// 		// 	ft_affichage_player(vars, y, x);
	// 		// if (vars->map[y][x] == 'C')
	// 		// 	ft_affichage_item(vars, y, x);
	// 		// if (vars->map[y][x] == 'E')
	// 		// 	ft_affichage_door(vars, y, x);
	// 	}
	// 	y++;
	// }
	// ft_grille(data);
	// affichage_player(data);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	ray_traicing(data);
	mlx_put_image_to_window(data->mlx_3d, data->mlx_win_3d, data->img_3d, 0, 0);
}
