/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:46:14 by aptive            #+#    #+#             */
/*   Updated: 2022/08/12 14:47:30 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	msg_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int	verif_arg(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		return (msg_error("too few arguments"));
	else if (argc > 2)
		return (msg_error("too much arguments"));
	return (0);
}
