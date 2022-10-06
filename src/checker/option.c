/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:52 by root              #+#    #+#             */
/*   Updated: 2022/10/06 17:31:02 by root             ###   ########.fr       */
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

	pth->tex_NO->ptr =
		mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_NO->path, &imgw, &imgh);
	pth->tex_SO->ptr =
		mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_SO->path, &imgw, &imgh);
	pth->tex_WE->ptr =
		mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_WE->path, &imgw, &imgh);
	pth->tex_EA->ptr =
		mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_EA->path, &imgw, &imgh);
	if (pth->tex_NO->ptr == NULL || pth->tex_SO->ptr == NULL
		|| pth->tex_WE->ptr == NULL || pth->tex_EA->ptr == NULL)
		return (0);
	pth->tex_SO->addr = mlx_get_data_addr(pth->tex_SO->ptr,
		&pth->tex_SO->bpp, &pth->tex_SO->length, &pth->tex_SO->end);
	pth->tex_NO->addr = mlx_get_data_addr(pth->tex_NO->ptr, 
		&pth->tex_NO->bpp, &pth->tex_NO->length, &pth->tex_NO->end);
	pth->tex_WE->addr = mlx_get_data_addr(pth->tex_WE->ptr,
		&pth->tex_WE->bpp, &pth->tex_WE->length, &pth->tex_WE->end);
	pth->tex_EA->addr = mlx_get_data_addr(pth->tex_EA->ptr,
		&pth->tex_EA->bpp, &pth->tex_EA->length, &pth->tex_EA->end);
	return (1);
}

int	xpm_err(t_data *pth)
{
	printf("text err\n");
	if (pth->tex_NO)
		mlx_destroy_image(pth->mlx_3d, pth->tex_NO);
	if (pth->tex_SO)
		mlx_destroy_image(pth->mlx_3d, pth->tex_SO);
	if (pth->tex_WE)
		mlx_destroy_image(pth->mlx_3d, pth->tex_WE);
	if (pth->tex_EA)
		mlx_destroy_image(pth->mlx_3d, pth->tex_EA);
	return (0);
}

int	check_rgb(t_data *data)
{
	int	i;
	int	value;

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
