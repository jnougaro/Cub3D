/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnougaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:31:19 by jnougaro          #+#    #+#             */
/*   Updated: 2022/02/16 11:44:50 by jnougaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
# include <limits.h>
# include <stdint.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 720
# define WALL_STRIP_WIDTH 1
# define MINI_CUB_SIZE 1 
# define TEXTURE_WIDTH 64 
# define TEXTURE_HEIGHT 64 
# define RAD_MAX 6.28319

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;		
}	t_rgb;

typedef struct s_coordinates
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_coordinates;

typedef struct s_map
{
	int		i;
	int		j;
	int		player;
	int		eot;
	int		width;
	int		height;
	char	**map_tab;
}	t_map;

typedef struct s_arg
{
	int		count;
	int		ret;
	int		i;
	int		j;
	char	*line;
	char	**temp_map;
}	t_arg;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;	
}	t_mlx;

typedef struct s_player
{
	int		walk_dir;
	int		turn_dir;
	int		press_cam_r;
	int		press_cam_l;
	double	x;
	double	y;
	double	pix_x;
	double	pix_y;
	double	rot_angle;
	double	rot_speed;
	double	strafing_angle;
	double	fov;
}	t_player;

typedef struct s_ray
{
	double	first_inter_x;
	double	first_inter_y;
	double	next_hor_inter_x;
	double	next_hor_inter_y;
	double	next_ver_inter_x;
	double	next_ver_inter_y;
	double	check_x;
	double	check_y;
	double	x_step;
	double	y_step;
	double	hit_wall_hor_x;
	double	hit_wall_hor_y;
	double	hit_wall_ver_x;
	double	hit_wall_ver_y;
	double	small_dist;
	double	hor_hit_dist;
	double	ver_hit_dist;
	double	small_dist_x;		
	double	small_dist_y;		
	double	correct_wall_dist;
	int		check_hit_wall_h;
	int		check_hit_wall_v;
	int		ray_no;
	int		ray_so;
	int		ray_we;
	int		ray_ea;
	int		hit_no;
	int		hit_so;
	int		hit_we;
	int		hit_ea;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_proj
{
	int		width_no;
	int		width_so;
	int		width_we;
	int		width_ea;
	int		height_no;
	int		height_so;
	int		height_we;
	int		height_ea;
	int		offset_x;	
	int		offset_y;
	int		dist_from_top;
	int		wall_top_pix;
	int		wall_bottom_pix;
	double	dist_proj_plane;
	double	proj_wall_height;
}	t_proj;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_struct
{
	t_rgb			*rgb_floor;
	t_rgb			*rgb_ceiling;
	t_coordinates	*coor;
	t_map			*map;
	t_mlx			*mlx;
	t_player		*player;
	t_img			*img;
	t_ray			**ray;
	t_texture		**texture;
	t_proj			*proj;
	int				fd;
}	t_struct;

int				count_line(char **tab);
int				check_if_param_empty(t_struct *data);
int				check_char_map(t_struct *data, char c);
int				handle_cross(t_struct *data);
int				handle_keyrelease(int keysym, t_struct *data);
int				handle_keypress(int keysym, t_struct *data);
int				rgb_generator(int t, int r, int g, int b);
int				window_resized(t_struct *data);
int				render_game(t_struct *data);
int				check_if_map_has_wall(t_struct *data, double x, double y);
unsigned int	get_texture_color(t_texture *texture, \
					int texture_x, int texture_y);
unsigned int	get_texture(t_struct *data, int ray_id, int wall_strip_height);
unsigned int	get_texture_2(t_struct *data, int ray_id, \
					int wall_strip_height);
double			normalize_ray(double ray_angle);
double			player_wall_dist(double x1, double y1, double x2, double y2);
void			free_tab(char **tab, int j);
void			parse_arg(t_struct *data, char *argv);
void			print_error(t_struct *data, char *str, int index);
void			init_rgb(t_struct *data);
void			init_coor(t_struct *data);
void			init_map(t_struct *data);
void			init_data(t_struct *data);
void			init_ray(t_struct *data);
void			init_ray_2(t_struct *data, int i);
void			init_proj(t_struct *data);
void			free_struct_ray(t_struct *data, int j);
void			ft_free(t_struct *data);
void			count_file_line(t_struct *data, t_arg *arg);
void			set_arg(t_struct *data, char *argv);
void			init_arg(t_arg *arg);
void			fill_temp_map(t_struct *data, t_arg *arg, char *argv);
void			check_param(t_struct *data, t_arg *arg);
void			fill_info(t_struct *data, t_arg *arg);
void			check_path_texture(t_struct *data, t_arg *arg, char *str);
void			free_param_struct(t_struct *data);
void			check_end_line(t_struct *data, t_arg *arg);
void			check_info_rgb(t_struct *data, t_arg *arg, char *str);
void			count_comma(t_struct *data, t_arg *arg);
void			check_if_num(t_struct *data, t_arg *arg, int index, char *str);
void			error_free_arg(t_struct *data, t_arg *arg);
void			fill_rgb_floor(t_struct *data, t_arg *arg, \
					int index, int first);
void			fill_rgb_ceiling(t_struct *data, t_arg *arg, \
					int index, int first);
void			fill_map_tab(t_struct *data, t_arg *arg);
void			parse_map(t_struct *data);
void			error_map(t_struct *data);
void			find_end_of_tab(t_struct *data);
void			check_space(t_struct *data);
void			check_around_space(t_struct *data, int i, int j);
void			check_up(t_struct *data);
void			check_down(t_struct *data);
void			check_current(t_struct *data);
void			start_game(t_struct *data);
void			init_window(t_struct *data);
void			init_mlx(t_struct *data);
void			init_player(t_struct *data);
void			init_img(t_struct *data);
void			ft_free_game(t_struct *data);
void			get_info_player(t_struct *data, char c);
void			move_player(t_struct *data, int index);
void			move_player_2(t_struct *data, double new_player_x, \
					double new_player_y);
void			my_pixel_put(t_struct *data, int x, int y, int color);
void			get_width(t_struct *data, t_arg *arg);
void			check_ends(t_struct *data);
void			rotate_cam(t_struct *data);
void			cast_rays(t_struct *data);
void			cast_one_ray(t_struct *data, t_ray *ray, double ray_angle);
void			check_hit_horizontal(t_struct *data, \
					t_ray *ray, double ray_angle);
void			find_first_inter_hor(t_struct *data, \
					t_ray *ray, double ray_angle);
void			check_hit_vertical(t_struct *data, \
					t_ray *ray, double ray_angle);
void			find_first_inter_ver(t_struct *data, \
					t_ray *ray, double ray_angle);
void			check_nearest_wall(t_struct *data, \
					t_ray *ray, double ray_angle);
void			find_smallest_dist(t_ray *ray);
void			print_rays(t_struct *data, t_ray *ray, double ray_angle);
void			render_3d_wall(t_struct *data);
void			print_wall(t_struct *data, int ray_id, int wall_strip_height);
void			set_texture(t_struct *data);
void			fill_tab_texture(t_struct *data, t_ray *ray);
void			get_info_texture(t_struct *data, t_texture *texture);
void			init_texture(t_struct *data);
void			free_struct_texture(t_struct *data, int j);
void			get_texture_off_set(t_struct *data, int ray_id);
void			find_wall_ends(t_struct *data, int wall_strip_height);
char			*strdup_square_map(t_struct *data, char *s1);
char			*strdup_cub(const char *s1);

#endif
