/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:30:39 by aptive            #+#    #+#             */
/*   Updated: 2022/10/13 12:09:44 by chaidel          ###   ########.fr       */
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
# define SQUARE	32
# define WALL_H	32
# define PI M_PI
# define CONVERT_RAD 0.01745329
# define ONE_DEGRE 0.0174533

# define WALL_N	1
// RED
# define WALL_S	3
//GREEN
# define WALL_E	2
// BLUE
# define WALL_W	4
// WHITE

typedef struct s_img {
	void	*ptr;
	char	*addr;
	char	*path;
	int		bpp;
	int		line;
	int		end;
}	t_img;

typedef struct s_player {
	int		x;
	int		y;
	double	direction;

	double	tile_y_x;
	double	tile_y_y;

	double	tile_x_x;
	double	tile_x_y;
	int		tile_step_x;
	int		tile_step_y;

	float	delta_y;
	float	delta_x;

	double	distance_proj_plane;
	double	ab_cos_angle_ray;
	double	tan_angle_ray;

}	t_player;

typedef struct s_data {
	void		*mlx_3d;
	void		*mlx_win_3d;
	void		*img_3d;
	char		*addr3d;
	int			bpp;
	int			length;
	int			endian_3d;

	int			screen_h;
	int			screen_w;

	int			y_s;
	int			y_end;

	char		*path_map;
	t_img		*tex_no;
	t_img		*tex_so;
	t_img		*tex_we;
	t_img		*tex_ea;
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

	int			forward;
	int			backward;
	int			go_right;
	int			go_left;

	int			turn_right;
	int			turn_left;

}	t_data;

/*
MAIN_C---------------------------------------------------------------------------
*/
void	debug(t_data *data); //DEBUG

/*	Parsing */
t_data	*init_data(t_data *data, char *path_map);
void	init_tex(t_data *data);
void	init_img(t_data *data);
char	*ft_map_read(char *path);
int		parsing_map(t_data *data);
int		parsing_map_sc(t_data *data, char **mapi, char **tex);
int		copy_map(t_data *data, char **map);
int		msg_error(char *str);
int		verif_open_map(char *path_map);
int		check_filetype(char *file);
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
int		solver_x_sc(t_data *data, int y, int x);
int		solver_x_lim(t_data *data, int y);
int		solver_x_open(t_data *data, int y, int x);
int		solver_y(t_data *data);
int		solver_y_sc(t_data *data, int x);
int		solver_y_open(t_data *data, int y, int x);

/*	Utils */
int		free_struct(t_data *data);
int		free_struct_config(t_data *data);
void	freer(t_data *data);
void	destroyer(t_data *data);
int		ft_free_doubletab(char **tab);

/*	Option */
int		check_texture_path(t_data *pth);
int		check_path(t_data *pth);
int		check_rgb(t_data *data);
int		xpm_err(t_data *pth);

/*
GRAPH/GRAPH_UTILS_C--------------------------------------------------------------
*/
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put_3d(t_data *data, int x, int y, int color);
void	v_line_3d(t_data *data, int x, t_img *tex, int side);
void	sides(t_data *data, int *tex_x, int side);

/*
GRAPH/MAP_C----------------------------------------------------------------------
*/
void	ft_affiche_map(t_data *data);

/*
PLAYER/PLAYER_C------------------------------------------------------------------
*/
void	find_player_orientation(t_data *data);
void	find_player_position(t_data *data);
void	affichage_player(t_data *data);
void	ft_move_fov(t_data *data, char c);
void	ft_move_player(t_data *data, char c);
int		find_x(double angle, int distance, int origin_x);
int		find_y(double angle, int distance, int origin_y);

/*
PLAYER/PLAYER_SUPP_C-------------------------------------------------------------
*/
void	init_player(t_data *data);

/*
HOOK/HOOK_C----------------------------------------------------------------------
*/
int		key_hook(t_data *data);
int		ft_close(t_data *data);
int		ft_press(int keycode, t_data *data);
int		ft_release(int keycode, t_data *data);

/*
RAY/DDA_C------------------------------------------------------------------------
*/
void	dda(t_data *data, t_player *player);
double	calcul_delta(t_player *player, char c);
int		check_intersection(t_data *data, int x, int y);
/*
RAY/DDA_UTILS_C------------------------------------------------------------------
*/
void	calcul_tile_step_y_y(t_player *p, int tile_step);
void	calcul_tile_step_x_x(t_player *p, int tile_step);
void	next_intercept_y(t_player *player);
void	next_intercept_x(t_player *player);
/*
RAY/RAY_TRAICING_C---------------------------------------------------------------
*/
void	ray_traicing(t_data *data);
void	witch_ray(t_data *data, t_player *player);

/*
RAY/RAY_UTILS_C------------------------------------------------------------------
*/
int		absolu(int nb);
double	absolu_double(double nb);
double	calcul_distance_square(double x1, double x2);
double	ray_distance(double x, double y, double x2, double y2);
double	inter_pi(double angle_ray);
// int		find_y_float(float angle, int distance, int origin_y);
// int		find_x_float(float angle, int distance, int origin_x);

/*
RAY/RAY_WALL_AFFICHAGE_C---------------------------------------------------------
*/
void	init_constante(t_data *data);
double	wall_height_apparence(t_player *player, double distance_ray);
void	affiche_wall(t_data *data, double distance_ray, int wall_x);
double	delete_fish_eye(double distance, double fov);

#endif
