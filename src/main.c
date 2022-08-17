/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:32:44 by aptive            #+#    #+#             */
/*   Updated: 2022/08/18 01:04:38 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void affichage_data(t_data	*data)
{
	// printf("data->path->path_NO : %s\n", data->path->path_NO);
	// printf("ICI\n");
	// printf("data->path->path_SO : %s\n", data->path->path_SO);
	// printf("data->path->path_WE : %s\n", data->path->path_WE);
	// printf("data->path->path_EA : %s\n", data->path->path_EA);
	printf("Floor RGB\n");
	for (int i = 0; data->floor_rgb[i]; i++)
		printf ("ln %i	: %s\n", i, data->floor_rgb[i]);
	printf("Ceeling RGB\n");
	for (int i = 0; data->ceiling_rbg[i]; i++)
		printf ("ln %i	: %s\n", i, data->ceiling_rbg[i]);
	for (int i = 0; data->map[i]; i++)
		printf ("ln %i	: %s\n", i, data->map[i]);

	printf("map height : %i\n", data->map_h);
	printf("map weight : %i\n", data->map_w);

	printf("data->player->direction : %i\n", data->player->direction);
	printf("data->player->x : %i\n", data->player->x);
	printf("data->player->y : %i\n", data->player->y);


}

void	ft_move_fov(t_data *data, char c)
{
	if (c == 'r')
	{
		data->player->direction--;
	}
		if (c == 'g')
	{
		data->player->direction++;
	}
	ft_affiche_map(data);
}

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	printf("keycode : %i\n", keycode);
	// if (keycode == 65307 || keycode == 53 || keycode == 17)
	// 	ft_close(vars);
	// if (keycode == 65364 || keycode == 1 || keycode == 115)
	// 	ft_move_player(vars, 'b');
	// if (keycode == 65362 || keycode == 13 || keycode == 119)
	// 	ft_move_player(vars, 'h');
	if (keycode == 100)
		ft_move_fov(data, 'r');
	if (keycode == 97)
		ft_move_fov(data, 'g');
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;


	data = NULL;
	if (verif_arg(argc, argv))
		return (1);
	data = init_data(data, argv[1]);
	parsing_map(data);
	init_player(data);

	// affichage_data(data);

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE, "Cub3D");
	data->img = mlx_new_image(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	ft_affiche_map(data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop(data->mlx);

	return (0);
}
