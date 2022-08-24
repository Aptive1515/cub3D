/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:52 by root              #+#    #+#             */
/*   Updated: 2022/08/24 18:59:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
 *	Ouvre le ficher via le path donné et récup l'image
*/
int	check_texture_path(t_data *pth)
{
	int	imgw;
	int	imgh;

	pth->path->texture_NO = mlx_xpm_file_to_image(pth->mlx, pth->path->path_NO, &imgw, &imgh);
	pth->path->texture_SO = mlx_xpm_file_to_image(pth->mlx, pth->path->path_SO, &imgw, &imgh);
	pth->path->texture_WE = mlx_xpm_file_to_image(pth->mlx, pth->path->path_WE, &imgw, &imgh);
	pth->path->texture_EA = mlx_xpm_file_to_image(pth->mlx, pth->path->path_EA, &imgw, &imgh);
	if (pth->path->texture_NO == NULL || pth->path->texture_SO == NULL
		|| pth->path->texture_WE == NULL || pth->path->texture_EA == NULL)
		return (xpm_err(pth));
	return (1);
}

int	xpm_err(t_data *pth)
{
	if (pth->path->texture_NO)
		mlx_destroy_image(pth->mlx, pth->path->texture_NO);
	if (pth->path->texture_SO)
		mlx_destroy_image(pth->mlx, pth->path->texture_SO);
	if (pth->path->texture_WE)
		mlx_destroy_image(pth->mlx, pth->path->texture_WE);
	if (pth->path->texture_EA)
		mlx_destroy_image(pth->mlx, pth->path->texture_EA);
	return (config_err());
}

// int	check_rgb(t_data *rgb)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
		
// 		i++;
// 	}
// }