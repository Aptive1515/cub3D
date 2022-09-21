/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:52 by root              #+#    #+#             */
/*   Updated: 2022/09/21 13:22:24 by chaidel          ###   ########.fr       */
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

	pth->tex_NO->img_ptr = mlx_xpm_file_to_image(pth->mlx, pth->tex_NO->path_tex, &imgw, &imgh);
	pth->tex_SO->img_ptr = mlx_xpm_file_to_image(pth->mlx, pth->tex_SO->path_tex, &imgw, &imgh);
	pth->tex_WE->img_ptr = mlx_xpm_file_to_image(pth->mlx, pth->tex_WE->path_tex, &imgw, &imgh);
	pth->tex_EA->img_ptr = mlx_xpm_file_to_image(pth->mlx, pth->tex_EA->path_tex, &imgw, &imgh);
	if (pth->tex_NO->img_ptr == NULL || pth->tex_SO->img_ptr == NULL
		|| pth->tex_WE->img_ptr == NULL || pth->tex_EA->img_ptr == NULL)
		return (0);
	pth->tex_NO->addr = mlx_get_data_addr(pth->tex_NO->img_ptr, &pth->tex_NO->bits_per_pixel, &pth->tex_NO->line_length, &pth->tex_NO->endian);
	pth->tex_SO->addr = mlx_get_data_addr(pth->tex_SO->img_ptr, &pth->tex_SO->bits_per_pixel, &pth->tex_SO->line_length, &pth->tex_SO->endian);
	pth->tex_WE->addr = mlx_get_data_addr(pth->tex_WE->img_ptr, &pth->tex_WE->bits_per_pixel, &pth->tex_WE->line_length, &pth->tex_WE->endian);
	pth->tex_EA->addr = mlx_get_data_addr(pth->tex_EA->img_ptr, &pth->tex_EA->bits_per_pixel, &pth->tex_EA->line_length, &pth->tex_EA->endian);
	return (1);
}

int	xpm_err(t_data *pth)
{
	printf("text err\n");
	if (pth->tex_NO)
		mlx_destroy_image(pth->mlx, pth->tex_NO);
	if (pth->tex_SO)
		mlx_destroy_image(pth->mlx, pth->tex_SO);
	if (pth->tex_WE)
		mlx_destroy_image(pth->mlx, pth->tex_WE);
	if (pth->tex_EA)
		mlx_destroy_image(pth->mlx, pth->tex_EA);
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
