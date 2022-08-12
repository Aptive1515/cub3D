/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:30:39 by aptive            #+#    #+#             */
/*   Updated: 2022/08/12 17:11:18 by aptive           ###   ########.fr       */
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

typedef struct s_path {
	char	*path_map;

	char	*path_NO;
	char	*path_SO;
	char	*path_WE;
	char	*path_EA;




	void	*texture_NO;
	void	*texture_SO;
	void	*texture_WE;
	void	*texture_EA;

}	t_path;

typedef struct s_data {
	t_path	*path;
	char	**floor_rgb;
	char	**ceiling_rbg;
	char	**map;
}	t_data;

/*
MAIN_C---------------------------------------------------------------------------
*/

/*
PARSING/PARSE_MAP_C--------------------------------------------------------------
*/
t_data	*init_data(t_data *data, char *path_map);
char	*ft_map_read(char *path_map);
void	parsing_map(t_data *data);

/*
PARSING/VERIF_ARG_C--------------------------------------------------------------
*/
int		msg_error(char *str);
int		verif_open_map(char *path_map);
int		verif_arg(int argc, char **argv);

#endif
