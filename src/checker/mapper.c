/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:30:45 by chaidel           #+#    #+#             */
/*   Updated: 2022/09/14 13:09:46 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
 *  
*/
int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			// printf("y%d, x%d => |%c|\n", y, x, data->map[y][x]);
			if (!(data->map[y][x] == ' ' || data->map[y][x] == '1'
					|| data->map[y][x] == '0'))
			{
				if (data->map[y][x] == 'N' || data->map[y][x] == 'E'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'W')
					c++;
				else
					return (0);
			}
			x++;
		}
		// printf("\n");
		y++;
	}
	if (c != 1)
		return (0);
    // printf("w: %d | h: %d\n", data->map_w, data->map_h);
    return (1);
}


int	solver_x(t_data *data)
{
	int	x;
	int	y;
	int	start;
	int	end;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		start = 0;
		end = 0;
		if (y == 0 || y == data->map_h - 1)
		{
			if (!solver_x_lim(data, y))
				return (0);
		}
		else
		{
			while (x < data->map_w)
			{
				while (!start && data->map[y][x] == ' ')
					x++;
				if (data->map[y][x] != ' ' && start)
					end = 0;
				if (data->map[y][x] == ' ')
				{
					if (!solver_x_open(data, y, x))
					{
						printf("in\n");
						return (0);
					}
				}
				else if (data->map[y][x] == '1' && !start)
					start = 1;
				else if (data->map[y][x] == '1' && start)
					end = 1;
				x++;
			}
			if (!start || !end)
			{
				printf("not close\ny: %d |%s|\n", y, data->map[y]);
				return (0);	
			}
			// printf("s: %d | e: %d\n", start, end);
			
		}
		y++;
	}
	return (1);
}

int	solver_x_lim(t_data *data, int y)
{
	int	x;
	int	start;

	x = 0;
	start = 0;
	while (x < data->map_w)
	{
		if (!(data->map[y][x] == '1' || data->map[y][x] == ' '))
		{
			printf("x_lim 1 not close\ny: %d %d |%s|\n", y, x, data->map[y]);
			return (0);
		}
		while (!start && data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '1' && !start)
			start = 1;
		else if (data->map[y][x] == ' ' && start)
			if (!solver_x_open(data, y, x))
				return (0);
		x++;
	}
	if (!start)
	{
		printf("x_lim 2 not close\ny: %d |%s|\n", y, data->map[y]);
		return (0);
	}
	return (1);
}

/*
 *	S'il le checker trouve un espace, il vérifie tout autour que le vide est bien fermé
*/
int	solver_x_open(t_data *data, int y, int x)
{
	int	i;

	/*	Check en horizontale	*/
	i = x;
	while (data->map[y][i] == ' ')
		if (data->map[y][i - 1] == ' ')
			i--;
		else if (data->map[y][i - 1] == '1')
			break;
		else
			return (0);
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
	// if (y == 0 && x - 1 > 0 && x + 1 < data->map_w)
	// {
	// 	while (y < data->map_h - 1)
	// 	{
	// 		if (data->map[y][x] == ' ' && (data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1'))
	// 			y++;
	// 		else if (data->map[y][x] == '1' && (data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1'))
	// 			return (1);
	// 		else
	// 		{
	// 			printf("op1 not close\ny: %d |%s|\ny: %d |%s|\n", y-1, data->map[y-1], y, data->map[y]);
	// 			return (0);
	// 		}
	// 	}
	// }
	// else if (y == data->map_h - 1 && x - 1 > 0 && x + 1 < data->map_w)
	// {
	// 	while (y >= 0)
	// 	{
	// 		if (data->map[y][x] == ' ' && (data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1'))
	// 			y--;
	// 		else if (data->map[y][x] == '1' && (data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1'))
	// 			return (1);
	// 		else
	// 		{
	// 			printf("op2 not close\ny: %d |%s|\ny: %d |%s|\n", y, data->map[y], y-1, data->map[y-1]);
	// 			return (0);
	// 		}
	// 	}
	// }
	// else
	// {
	// 	printf("me3");
	// 	return (0);
	// }