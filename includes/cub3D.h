/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:30:39 by aptive            #+#    #+#             */
/*   Updated: 2022/08/25 13:52:37 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <string.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../miniLibX_X11/mlx.h"

# define WIDTH	1980
# define HEIGHT	1200
# define SQUARE	32
# define RED	0xCF2500
# define WHITE	create_trgb(0, 255, 255, 255)
# define BLUE	create_trgb(0, 54, 60, 2450)
# define GREEN	create_trgb(0, 55, 255, 0)
# define BLACK	create_trgb(0, 0, 0, 0)

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

typedef struct s_player {
	int	x;
	int	y;
	int	direction;
}	t_player;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	t_path		*path;
	t_player	*player;
	char		**floor_rgb;
	char		**ceiling_rgb;
	char		**map;

	int			map_h;
	int			map_w;
}	t_data;

/*
MAIN_C---------------------------------------------------------------------------
*/

/*	Parsing */
t_data	*init_data(t_data *data, char *path_map);
char	*ft_map_read(int fd, int max);
void	parsing_map(t_data *data);
void	copy_map(t_data *data, char **map);
int		msg_error(char *str);
int		verif_open_map(char *path_map);
int		verif_arg(int argc, char **argv);
int		parsing_rgb_fc(t_data *data, char **tab_gnl);
int		parsing_path_texture(t_data *data, char **tab_gnl);
int		config_err(void);

/*	Utils */
void    free_struct(t_data *data);
void    free_struct_config(t_data *data);
void	ft_free_doubletab(char **tab);
/*
GRAPH/FIRGURE_C------------------------------------------------------------------
*/

void	do_circle(t_data *data, int r, int x_centre, int y_centre, int color);
void	full_circle(t_data *data, int r, int x_centre, int y_centre, int color);
void	draw_lign(t_data *data, int x1, int y1, int x2, int y2, int color);

/*
GRAPH/GRAPH_UTILS_C--------------------------------------------------------------
*/
void	ft_lign_vertical(t_data *data, int x, int y, int y_end, int color);
void	ft_lign_horizontal(t_data *data, int x, int x_end, int y,int color);
void	ft_grille(t_data *data);
void	ft_full(t_data *data, int x_beg, int y_beg, int color);
void	my_mlx_pixel_put_limit(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);

/*
GRAPH/MAP_C----------------------------------------------------------------------
*/
void	ft_affiche_map(t_data *data);

/*
PLAYER/PLAYER_C------------------------------------------------------------------
*/
void	find_player_orientation(t_data *data);
void	find_player_position(t_data *data);
void	init_player(t_data *data);
void	affichage_player(t_data *data);
void	ft_move_fov(t_data *data, char c);

/*
HOOK/HOOK_C----------------------------------------------------------------------
*/
int		key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);

#endif
