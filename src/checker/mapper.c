/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:30:45 by chaidel           #+#    #+#             */
/*   Updated: 2022/08/29 21:30:17 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
 *  
*/
int check_map(t_data *data)
{
    int x;
    int y;
    int c;

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

int	launcher(t_data *data)
{
	int	x;
	x = 0;
	while (data->map[0][x] == ' ')
		x++;
	return (solver(data, 0, x));
}

/*
 *	Backtracking
 *	Suit la bordure
 *	Droit, Bas, Gauche, Haut
*/
int	solver(t_data *data, int y, int x)
{

	return (0);
}

