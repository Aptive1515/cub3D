/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:32:28 by aptive            #+#    #+#             */
/*   Updated: 2022/09/03 01:45:36 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_data *data)
{
	(void)data;
	// printf("keycode : %i\n", keycode);
	if (keycode == 65307)
		ft_close(data);
	// if (keycode == 65364 || keycode == 1 || keycode == 115)
	// 	ft_move_player(vars, 'b');
	// if (keycode == 65362 || keycode == 13 || keycode == 119)
	// 	ft_move_player(vars, 'h');
	if (keycode == 115)
		ft_move_player(data, 'd');
	if (keycode == 119)
		ft_move_player(data, 'u');
	if (keycode == 100)
		ft_move_player(data, 'r');
	if (keycode == 97)
		ft_move_player(data, 'g');
	if (keycode == 65363)
		ft_move_fov(data, 'r');
	if (keycode == 65361)
		ft_move_fov(data, 'g');
	return (0);
}

int	ft_close(t_data *data)
{
	(void)data;
	exit (EXIT_SUCCESS);
}
