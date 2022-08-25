/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:32:44 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 14:12:05 by chaidel          ###   ########.fr       */
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
	for (int i = 0; data->ceiling_rgb[i]; i++)
		printf ("ln %i	: %s\n", i, data->ceiling_rgb[i]);
	for (int i = 0; data->map[i]; i++)
		printf ("ln %i	: %s\n", i, data->map[i]);

	printf("map height : %i\n", data->map_h);
	printf("map weight : %i\n", data->map_w);

	printf("data->player->direction : %i\n", data->player->direction);
	printf("data->player->x : %i\n", data->player->x);
	printf("data->player->y : %i\n", data->player->y);


}

int	main(int argc, char **argv)
{
	t_data	*data;


	data = NULL;
	if (verif_arg(argc, argv))
	{
		printf("there\n");
		return (1);
	}
	data = init_data(data, argv[1]);
	parsing_map(data);
	init_player(data);
	printf("done\n");
	free_struct(data);
	return (0);

	// affichage_data(data);

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE, "Cub3D");
	data->img = mlx_new_image(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	ft_affiche_map(data);
	mlx_hook(data->mlx_win, 17, 1L << 0, ft_close, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop(data->mlx);

	return (0);
}
