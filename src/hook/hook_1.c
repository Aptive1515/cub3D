/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:32:28 by aptive            #+#    #+#             */
/*   Updated: 2022/09/26 19:18:50 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(t_data *data)
{
	if (data->forward)
		ft_move_player(data, 'u');
	if (data->backward)
		ft_move_player(data, 'd');
	if (data->go_right)
		ft_move_player(data, 'r');
	if (data->go_left)
		ft_move_player(data, 'g');
	if (data->turn_right)
		ft_move_fov(data, 'r');
	if (data->turn_left)
		ft_move_fov(data, 'g');
	ft_affiche_map(data);
	return (0);
}

int	ft_close(t_data *data)
{
	free_struct(data);
	exit (EXIT_SUCCESS);
}

int	ft_press(int keycode, t_data *data)
{
	if (keycode == 119)
		data->forward = 1;
	else if (keycode == 115)
		data->backward = 1;
	else if (keycode == 97)
		data->go_right = 1;
	else if (keycode == 100)
		data->go_left = 1;
	else if (keycode == 65361)
		data->turn_right = 1;
	else if (keycode == 65363)
		data->turn_left = 1;
	else if (keycode == 65307)
		ft_close(data);
	return (1);
}

int	ft_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->forward = 0;
	else if (keycode == 115)
		data->backward = 0;
	else if (keycode == 97)
		data->go_right = 0;
	else if (keycode == 100)
		data->go_left = 0;
	else if (keycode == 65361)
		data->turn_right = 0;
	else if (keycode == 65363)
		data->turn_left = 0;
	return (1);
}
