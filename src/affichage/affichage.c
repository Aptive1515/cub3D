/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:49:59 by aptive            #+#    #+#             */
/*   Updated: 2022/08/12 16:52:59 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_init_xpm(t_data *data)
{
	int		img_width;
	int		img_height;

	data->path->texture_NO = NULL;

	data->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall_xpm/wall_1.xpm", &img_width, &img_height);

	if (!data->wall)
		ft_xpm_err(data);
}

void	ft_xpm_err(t_data *vars)
{
	if (data->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	msg_error("Can't open texture");
}
