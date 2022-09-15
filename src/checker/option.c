/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:52 by root              #+#    #+#             */
/*   Updated: 2022/09/15 11:25:03 by chaidel          ###   ########.fr       */
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
	printf("text err\n");
	if (pth->path->texture_NO)
		mlx_destroy_image(pth->mlx, pth->path->texture_NO);
	if (pth->path->texture_SO)
		mlx_destroy_image(pth->mlx, pth->path->texture_SO);
	if (pth->path->texture_WE)
		mlx_destroy_image(pth->mlx, pth->path->texture_WE);
	if (pth->path->texture_EA)
		mlx_destroy_image(pth->mlx, pth->path->texture_EA);
	return (0);
}

int	check_rgb(t_data *data)
{
	int	i;
	int	value;
	
	// printf("inside\n");
	i = -1;
	if (!data->floor_rgb || !data->ceiling_rgb)
		return (0);
	if (ft_doubletab_len(data->floor_rgb) != 3
		|| ft_doubletab_len(data->ceiling_rgb) != 3)
		return (0);
	if (!strs_are_num(data->floor_rgb) || !strs_are_num(data->ceiling_rgb))
		return (0);
	while (++i < 3)
	{
		value = ft_atoi(data->floor_rgb[i]);
		if (value < 0 || value > 255)
			return (0);
	}
	i = -1;
	while (++i < 3)
	{
		value = ft_atoi(data->ceiling_rgb[i]);
		if (value < 0 || value > 255)
			return (0);
	}
	return (1);
}

int	strs_are_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		j = 0;
		if (!av[i][j])
			return (0);
		while (av[i][j])
			if (!(av[i][j] >= '0' && av[i][j++] <= '9'))
				return (0);
		i++;
	}
	return (1);
}
