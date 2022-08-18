/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:09 by aptive            #+#    #+#             */
/*   Updated: 2022/08/18 12:18:28 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_affiche_map(t_data *data)
{
	int		y;
	int		x;
	// mlx_destroy_display(data->mlx);
	// mlx_destroy_image(data->mlx, data->mlx_win);
	mlx_clear_window(data->mlx, data->mlx_win);
	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == '1')
				ft_full(data, (x * SQUARE), (y * SQUARE), BLUE);
			// if (data->map[y][x] == '0')
			// 	ft_full(data, (x * SQUARE), (y * SQUARE), WHITE);
			// if (data->map[y][x] == 'N')
			// {
			// 	ft_full(data, (x * SQUARE), (y * SQUARE), WHITE);
			// 	// full_circle(data, SQUARE/3, (x * SQUARE) + SQUARE/2, (y * SQUARE) + SQUARE/2, BLUE);
			// }
				// ft_affichage_wall(vars, y, x);
			// if (vars->map[y][x] == '0' || vars->map[y][x] == 'P'
			// 	|| vars->map[y][x] == 'E' || vars->map[y][x] == 'C')
			// 	ft_affichage_floor(vars, y, x);
			// if (vars->map[y][x] == 'P')
			// 	ft_affichage_player(vars, y, x);
			// if (vars->map[y][x] == 'C')
			// 	ft_affichage_item(vars, y, x);
			// if (vars->map[y][x] == 'E')
			// 	ft_affichage_door(vars, y, x);
			x++;
		}
		y++;
	}
	ft_grille(data);
	affichage_player(data);
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
