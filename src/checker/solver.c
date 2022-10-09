/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:46:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/09 18:01:55 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"


/*
 *	le solver verif de colonne en colonne
 *	y		=>	lignes
 *	x		=>	colonnes
 *	start	=>	1er '1' trouver, se reinitialise a chaque nouvelle ligne
 *	end		=>	dernier '1' trouver, se reinitialise des qu'il trouve le 1er start
 *				ou qu'un nouveau start est definie
 *	bt		=>	0 ou player, verif qu'il soit encadree verticalement !PB de bas en haut!
*/
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
				break ;
			if (data->map[y][x] != ' ' && start)
				end = 0;
			if (data->map[y][x] == ' ' && start)
			{
				if (solver_y_open(data, y, x))
				{
					printf("opy1\ny: %d x: %d, |%c|\n|%s|\n|%s|<=\n|%s|\n", y, x, data->map[y][x], data->map[y-1],data->map[y],data->map[y+1]);
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
			printf("opy2\ny: %d x: %d, |%c|\n|%s|\n|%s|<=\n|%s|\n", y, x, data->map[y][x], data->map[y-1],data->map[y],data->map[y+1]);
			return (0); // printf("opy2\ny: %d x: %d, |%c|\n|%s|\n|%s|<=\n|%s|\n", y, x, data->map[y][x], data->map[y-1],data->map[y],data->map[y+1]);
		}
	}
	return (1);
}
/*
 *	S'il le checker trouve un espace, il vérifie tout autour (horizontalement) que le vide est bien fermé
*/
int	solver_y_open(t_data *data, int y, int x)
{
	int	i;

	i = y;
	while (data->map[i][x] == ' ')
		if (data->map[i - 1][x] == ' ')
			i--;
		else if (data->map[i - 1][x] == '1')
			break;
		else
			return (0);
	i = y;
	while (data->map[i][x] == ' ')
	{
		if (i == data->map_h - 1)
			return (1);
		if (data->map[i - 1][x] == '1')
			return (1);
		else if (!(data->map[i + 1][x] == '1' || data->map[i - 1][x] == ' '))
			return (0);
		i++;
	}
	return (1);
}