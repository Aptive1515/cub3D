/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:30:45 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/13 11:52:38 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
 *	printf("y%d, x%d => |%c|\n", y, x, data->map[y][x]);
*/
int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = -1;
	while (++y < data->map_h)
	{
		x = -1;
		while (++x < data->map_w)
		{
			if (!(data->map[y][x] == ' ' || data->map[y][x] == '1'
					|| data->map[y][x] == '0'))
			{
				if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
					c++;
				else
					return (0);
			}
		}
	}
	if (c != 1)
		return (0);
	return (1);
}

int	solver_x(t_data *data)
{
	int	y;
	int	x;

	x = -1;
	y = -1;
	while (++y < data->map_h)
	{
		if (y == 0 || y == data->map_h - 1)
		{
			if (!solver_x_lim(data, y))
				return (0);
		}
		else
			if (!solver_x_sc(data, y, x))
				return (0);
	}
	return (1);
}

int	solver_x_sc(t_data *data, int y, int x)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (++x < data->map_w)
	{
		if (x == 0 && (data->map[y][x] != '1' || data->map[y][x] != '1'))
			return (0);
		while (!start && data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] != ' ' && start)
			end = 0;
		if (data->map[y][x] == '1' && !start)
			start = 1;
		else if (data->map[y][x] == '1' && start)
			end = 1;
		else if (data->map[y][x] == ' ')
			if (!solver_x_open(data, y, x))
				return (0);
	}
	if (!start || !end)
		return (0);
	return (1);
}

int	solver_x_lim(t_data *data, int y)
{
	int	x;
	int	start;

	x = -1;
	start = 0;
	while (++x < data->map_w)
	{
		if (!(data->map[y][x] == '1' || data->map[y][x] == ' '))
			return (0);
		while (!start && data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '1' && !start)
			start = 1;
		else if (data->map[y][x] == ' ' && start)
			if (!solver_x_open(data, y, x))
				return (0);
	}
	if (!start)
		return (0);
	return (1);
}

/*
 *	S'il le checker trouve un espace, il vérifie tout autour
 *	(horizontalement) que le vide est bien fermé
*/
int	solver_x_open(t_data *data, int y, int x)
{
	int	i;

	i = x;
	while (data->map[y][i] == ' ')
	{
		if (data->map[y][i - 1] == ' ')
			i--;
		else if (data->map[y][i - 1] == '1')
			break ;
		else
			return (0);
	}
	i = x;
	while (data->map[y][i] == ' ')
	{
		if (i == data->map_w - 1)
			return (1);
		if (data->map[y][i + 1] == '1')
			return (1);
		else if (!(data->map[y][i + 1] == '1' || data->map[y][i + 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}
