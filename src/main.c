/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:32:44 by aptive            #+#    #+#             */
/*   Updated: 2022/08/12 17:23:51 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void affichage_data(t_data	*data)
{
	printf("data->path->path_NO : %s\n", data->path->path_NO);
	printf("data->path->path_SO : %s\n", data->path->path_SO);
	printf("data->path->path_WE : %s\n", data->path->path_WE);
	printf("data->path->path_EA : %s\n", data->path->path_EA);
	printf("Floor RGB\n");
	for (int i = 0; data->floor_rgb[i]; i++)
		printf ("ln %i	: %s\n", i, data->floor_rgb[i]);
	printf("Ceeling RGB\n");
	for (int i = 0; data->ceiling_rbg[i]; i++)
		printf ("ln %i	: %s\n", i, data->ceiling_rbg[i]);
	for (int i = 0; data->map[i]; i++)
		printf ("ln %i	: %s\n", i, data->map[i]);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (verif_arg(argc, argv))
		return (1);
	data = init_data(data, argv[1]);
	parsing_map(data);
	affichage_data(data);

	return (0);
}
