/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:46:26 by chaidel           #+#    #+#             */
/*   Updated: 2022/10/11 14:56:54 by chaidel          ###   ########.fr       */
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
*/
int	solver_y(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->map_w)
	{
		if (!solver_y_sc(data, x))
			return (0);
	}
	return (1);
}

/*	printf("opyy1\ny: %d x: %d, |%c|\n|%s|\n|%s|<=\n|%s|\n", y, x,
 *	data->map[y][x], data->map[y-1],data->map[y],data->map[y+1]);
*/

int	solver_y_sc(t_data *data, int x)
{
	int	y;
	int	start;
	int	end;

	y = -1;
	start = 0;
	end = 0;
	while (++y < data->map_h)
	{
		if (y == data->map_h)
			break ;
		if (data->map[y][x] != ' ' && start)
			end = 0;
		if (data->map[y][x] == ' ')
		{
			if (!solver_y_open(data, y, x))
				return (0);
		}
		else if (data->map[y][x] == '1' && !start)
			start = 1;
		else if (data->map[y][x] == '1' && start)
			end = 1;
	}
	return (1);
}

/*
 *	Si le solver trouve un espace,
 *	il se deplace sur les espaces precedent ou suivant jusqu'a trouve un 1
 *	sinon erreur
*/
int	solver_y_open(t_data *data, int y, int x)
{
	int	i;

	i = y;
	while (data->map[i][x] == ' ')
	{
		if (i == 0)
			break ;
		if (i > 0 && data->map[i - 1][x] == ' ')
			i--;
		else if (data->map[i - 1][x] == '1')
			break ;
		else
			return (0);
	}
	i = y;
	while (i < data->map_h - 1 && data->map[i][x] == ' ')
	{
		if (data->map[i + 1][x] == ' ')
			i++;
		else if (data->map[i + 1][x] == '1')
			return (1);
		else
			return (0);
	}
	return (1);
}
