/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:52 by root              #+#    #+#             */
/*   Updated: 2022/10/15 18:13:45 by chaidel          ###   ########.fr       */
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

	if (!check_path(pth))
		return (0);
	pth->tex_no->ptr
		= mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_no->path, &imgw, &imgh);
	pth->tex_so->ptr
		= mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_so->path, &imgw, &imgh);
	pth->tex_we->ptr
		= mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_we->path, &imgw, &imgh);
	pth->tex_ea->ptr
		= mlx_xpm_file_to_image(pth->mlx_3d, pth->tex_ea->path, &imgw, &imgh);
	if (pth->tex_no->ptr == NULL || pth->tex_so->ptr == NULL
		|| pth->tex_we->ptr == NULL || pth->tex_ea->ptr == NULL)
		return (0);
	pth->tex_so->addr = mlx_get_data_addr(pth->tex_so->ptr,
			&pth->tex_so->bpp, &pth->tex_so->line, &pth->tex_so->end);
	pth->tex_no->addr = mlx_get_data_addr(pth->tex_no->ptr,
			&pth->tex_no->bpp, &pth->tex_no->line, &pth->tex_no->end);
	pth->tex_we->addr = mlx_get_data_addr(pth->tex_we->ptr,
			&pth->tex_we->bpp, &pth->tex_we->line, &pth->tex_we->end);
	pth->tex_ea->addr = mlx_get_data_addr(pth->tex_ea->ptr,
			&pth->tex_ea->bpp, &pth->tex_ea->line, &pth->tex_ea->end);
	return (1);
}

int	check_path(t_data *pth)
{
	if (!pth->tex_no->path || !pth->tex_so->path || !pth->tex_we->path
		|| !pth->tex_ea->path)
		return (0);
	return (1);
}

int	xpm_err(t_data *pth)
{
	if (pth->tex_no)
		mlx_destroy_image(pth->mlx_3d, pth->tex_no);
	if (pth->tex_so)
		mlx_destroy_image(pth->mlx_3d, pth->tex_so);
	if (pth->tex_we)
		mlx_destroy_image(pth->mlx_3d, pth->tex_we);
	if (pth->tex_ea)
		mlx_destroy_image(pth->mlx_3d, pth->tex_ea);
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
		while (av[i][j] && av[i][j] != 13)
		{
			if (!(av[i][j] >= '0' && av[i][j++] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}
