/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:30:45 by chaidel           #+#    #+#             */
/*   Updated: 2022/08/29 14:28:39 by chaidel          ###   ########.fr       */
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

    y = 0;
    while (y < data->map_h)
    {
        x = 0;
        while (x < data->map_w)
        {
            if (data->map[y][x] != '1' || data->map[y][x] != '1' ||)
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}