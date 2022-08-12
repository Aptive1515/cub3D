/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:30:39 by aptive            #+#    #+#             */
/*   Updated: 2022/08/12 14:48:09 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../miniLibX_X11/mlx.h"

typedef struct s_data {
}	t_data;

/*
MAIN_C---------------------------------------------------------------------------
*/

/*
PARSING/VERIF_ARG_C--------------------------------------------------------------
*/
int	msg_error(char *str);
int	verif_arg(int argc, char **argv);

#endif
