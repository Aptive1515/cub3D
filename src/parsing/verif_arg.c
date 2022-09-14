/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:46:14 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 13:32:21 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	msg_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int	verif_open_map(char *path_map)
{
	int	fd_map;

	if (!path_map)
		return (1);
	fd_map = open(path_map, O_RDONLY);
	if (!fd_map)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	close (fd_map);
	return (0);
}

int	verif_arg(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		return (msg_error("too few arguments"));
	else if (argc > 2)
		return (msg_error("too much arguments"));
	else if (verif_open_map(argv[1]))
		return (msg_error("can't open map file"));
	return (0);
}
