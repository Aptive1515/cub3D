/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:30:39 by aptive            #+#    #+#             */
/*   Updated: 2022/09/15 14:20:22 by chaidel          ###   ########.fr       */
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

# define WIDTH	1080
# define HEIGHT	960
# define SQUARE	64
# define RED	0xCF2500
# define RED_DARK	create_trgb(0, 102, 8, 1)
# define WHITE	create_trgb(0, 255, 255, 255)
# define BLUE	create_trgb(0, 54, 60, 2450)
# define GREEN	create_trgb(0, 55, 255, 0)
# define BLACK	create_trgb(0, 0, 0, 0)
# define ROSE	create_trgb(0, 245, 66, 224)
# define HORIZON	600
# define WALL_H	32
# define PI M_PI
# define CONVERT_RAD	PI / (double)180
# define ONE_DEGRE 0.0174533


# define WALL_N	1
# define WALL_S	3
# define WALL_E	2
# define WALL_W	4

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
	int		x;
	int		y;
	double	direction;

	double	tile_Y_x;
	double	tile_Y_y;

	double	tile_X_x;
	double	tile_X_y;
	int		tile_step_x;
	int		tile_step_y;

	float	delta_y;
	float	delta_x;

}	t_player;

typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;


	void		*mlx_3d;
	void		*mlx_win_3d;
	void		*img_3d;
	char		*addr_3d;
	int			bits_per_pixel_3d;
	int			line_length_3d;
	int			endian_3d;

	t_path		*path;
	t_player	*player;
	char		**floor_rgb;
	char		**ceiling_rgb;
	char		**map;

	int			map_h;
	int			map_w;

	double		ray_x;
	double		ray_y;
	int			ray_x_before;
	int			ray_y_before;
	int			color_wall;


}	t_data;

/*
MAIN_C---------------------------------------------------------------------------
*/
void	debug(t_data *data); //DEBUG

/*	Parsing */
t_data	*init_data(t_data *data, char *path_map);
char	*ft_map_read(char *path);
int		parsing_map(t_data *data);
int		copy_map(t_data *data, char **map);
int		msg_error(char *str);
int		verif_open_map(char *path_map);
int		verif_arg(int argc, char **argv);
int		parsing_rgb(t_data *data, char *str);
int		parsing_path_texture(t_data *data, char **tab_gnl);
int		config_err(void);
int		strs_are_num(char **av);
int		not_key(char *str);
int		split_at_key(char **file);
char	**split_tab(char **tab, int len, char *(**rest));
char	*split_txt(char *str);
int		get_max(t_data *data, char **map, int *max);

/*	Checker */
int		check_map(t_data *data);
int		solver_x(t_data *data);
int		solver_x_lim(t_data *data, int y);
int		solver_x_open(t_data *data, int y, int x);
int		solver_y(t_data *data);
/*	Utils */
int		free_struct(t_data *data);
int		free_struct_config(t_data *data);
int		ft_free_doubletab(char **tab);

/*	Option */
int		check_texture_path(t_data *pth);
int		check_rgb(t_data *data);
int		xpm_err(t_data *pth);

/*
GRAPH/FIRGURE_C------------------------------------------------------------------
*/

void	do_circle(t_data *data, int r, int x_centre, int y_centre, int color);
void	full_circle(t_data *data, int r, int x_centre, int y_centre, int color);
void	draw_lign(t_data *data, int x1, int y1, int x2, int y2, int color);

/*
GRAPH/GRAPH_UTILS_C--------------------------------------------------------------
*/
int		verif_wall(t_data *data, int x, int y);
void	my_mlx_pixel_put_limit_wall(t_data *data, int x, int y, int color);
void	ft_lign_vertical(t_data *data, int x, int y, int y_end, int color);
void	ft_lign_horizontal(t_data *data, int x, int x_end, int y,int color);
void	ft_grille(t_data *data);
void	ft_full(t_data *data, int x_beg, int y_beg, int color);
void	my_mlx_pixel_put_limit(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put_3d(t_data *data, int x, int y, int color);
void	ft_lign_vertical_3d(t_data *data, int x, int y, int y_end, int color);

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
void	ft_move_player(t_data *data, char c);
int 	find_x(int angle, int distance, int origin_x);
int 	find_y(int angle, int distance, int origin_y);

/*
HOOK/HOOK_C----------------------------------------------------------------------
*/
int		key_hook(int keycode, t_data *data);
int		ft_close(t_data *data);

/*
RAY/RAY_TRAICING_C---------------------------------------------------------------
*/
void	ray_traicing(t_data *data);
void	ray_way(t_data *data, int x1, int y1, int x2, int y2);
double	delete_fish_eye(t_data *data, double distance, double angle_ray);
/*
RAY/RAY_UTILS_C------------------------------------------------------------------
*/
int		absolu(int nb);
float	absolu_float(float nb);
double	calcul_distance_square(double x1, double x2);
double	calcul_ray_distance(double	x, double y, double x2, double y2);
int 	find_y_float(float angle, int distance, int origin_y);
int 	find_x_float(float angle, int distance, int origin_x);

/*
RAY/RAY_WALL_AFFICHAGE_C---------------------------------------------------------
*/
double	wall_height_apparence(double	distance_ray);
void	ft_color_wall(t_data *data);

#endif
