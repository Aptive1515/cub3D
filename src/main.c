/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:32:44 by aptive            #+#    #+#             */
/*   Updated: 2022/09/14 19:39:49 by chaidel          ###   ########.fr       */
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

	printf("data->player->direction : %f\n", data->player->direction);
	printf("data->player->x : %i\n", data->player->x);
	printf("data->player->y : %i\n", data->player->y);


}

void	debug(t_data *data)
{
	printf("NO %s\nSO %s\nWE %s\nEA %s\n", data->path->path_NO,data->path->path_SO,data->path->path_WE,data->path->path_EA);
	printf("F ");
	for (int i = 0; data->floor_rgb[i]; i++)
		printf("%s,", data->floor_rgb[i]);
	printf("\n");
	printf("C ");
	for (int i = 0; data->ceiling_rgb[i]; i++)
		printf("%s,", data->ceiling_rgb[i]);
	printf("\n\n");
	for (int i = 0; data->map[i]; i++)
		printf("|%s|\n", data->map[i]);
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
	if (!parsing_map(data))
		exit(EXIT_FAILURE);
	init_player(data);

	if (!check_map(data) || !solver_x(data) || !solver_y(data))
	{
		config_err();
		return (free_struct(data));
	}

	// affichage_data(data);

	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE, "Cub3D");
	data->img = mlx_new_image(data->mlx, data->map_w * SQUARE, data->map_h * SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

	data->mlx_3d = mlx_init();
	data->mlx_win_3d = mlx_new_window(data->mlx_3d, WIDTH, HEIGHT, "Cub3D");
	data->img_3d = mlx_new_image(data->mlx_3d, WIDTH, HEIGHT);
	data->addr_3d = mlx_get_data_addr(data->img_3d, &data->bits_per_pixel_3d, &data->line_length_3d, &data->endian_3d);





	ft_affiche_map(data);
	mlx_hook(data->mlx_win, 17, 1L << 0, ft_close, data);
	mlx_key_hook(data->mlx_win, key_hook, data);
	mlx_loop(data->mlx);

	// debug(data);
	return (free_struct(data));
}
