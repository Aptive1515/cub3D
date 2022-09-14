/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:46:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/09/14 17:07:30 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	solver_y(t_data *data)
{
	int	x;
	int	y;
	int	start;
	int	end;
	int	bt;

	x = -1;
	while (++x < data->map_w)
	{
		bt = 0;
		y = -1;
		start = 0;
		end = 0;
		while (++y < data->map_h)
		{
			while (!start && y < data->map_h && data->map[y][x] == ' ')
				y++;
			if (y == data->map_h)
				break;
			if (data->map[y][x] != ' ' && start)
				end = 0;
			if (data->map[y][x] == ' ')
			{
				if (start && bt)
				{
					// printf("opy1\ny: %d x: %d\n|%s|\n|%s|<=\n|%s|\n", y, x, data->map[y-1],data->map[y],data->map[y+1]);
					return (0);
				}
			}
			else if (data->map[y][x] == '1' && !start)
			start = 1;
			else if (data->map[y][x] == '1' && start)
			{
				end = 1;
				bt = 0;
			}
			else
				bt = 1;
		}
		if (start && bt && !end)
		{
			// printf("opy2\ny: %d x: %d, |%c|\n|%s|\n|%s|<=\n|%s|\n", y, x, data->map[y][x], data->map[y-1],data->map[y],data->map[y+1]);
			return (0);
		}
	}
	return (1);
}
