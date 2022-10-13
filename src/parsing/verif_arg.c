/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:46:14 by aptive            #+#    #+#             */
/*   Updated: 2022/10/13 12:58:51 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	msg_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int	verif_open_map(char *path_map)
{
	int	fd;

	if (!path_map)
		return (1);
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n%s: %s\n", path_map, strerror(errno));
		return (1);
	}
	close (fd);
	return (0);
}

int	check_filetype(char *file)
{
	if (!ft_strrncmp(file, ".cub", ft_strlen(".cub")))
		return (0);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid map file\n", STDERR_FILENO);
	return (1);
}

int	verif_arg(int argc, char **argv)
{
	if (argc < 2)
		return (msg_error("too few arguments"));
	else if (argc > 2)
		return (msg_error("too much arguments"));
	else if (check_filetype(argv[1]) || verif_open_map(argv[1]))
		return (1);
	return (0);
}

/*
 *	Vérifie si les 1er char sont clés d'option
*/
int	not_key(char *str)
{
	if (ft_strlen(str) > 2)
	{
		if (str[0] == 'F' || str[0] == 'C'
			|| !ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2)
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
			return (0);
	}
	return (1);
}
