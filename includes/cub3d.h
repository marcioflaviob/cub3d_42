/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:25:40 by mbrandao          #+#    #+#             */
/*   Updated: 2024/07/16 18:32:14 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <sys/time.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1280
# define HEIGHT 720
# define PLAYER_SIZE 5
# define ENEMY_SPEED 0.01
# define TILE_SIZE 64
# define WALL_SIZE 80000
# define MINIMAP_SIZE 10

# define L_CONTROL_KEY 65507 //Replace

# define YELLOW 0xFFFF00
# define ORANGE 0xFFA500
# define DARK_GREEN 0x013220

typedef struct s_vert
{
	double	dist;
	double	factor;
	double	x_o;
	double	y_o;
	double	x;
	double	y;
	int		*txt_addr;
	int		length;
	int		ray_i;
	int		color;
	int		tex_y;
	int		t_pix;
	int		b_pix;
}	t_vert;

typedef struct s_sprite
{
	double	sprite_x;
	double	sprite_y;
	double	plane_length;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	double	aspect_ratio;
	int		sprite_screen_x;
	int		scaled_z_position;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		y;
	int		d;
	int		tex_y;
	int		color;
}	t_sprite;

typedef struct s_mparse
{
	int	y;
	int	x;
	int	i;
	int	j;
	int	w;
	int	d;
}	t_mparse;

typedef struct s_draw
{
	int		alpha;
	int		i;
	int		j;
	int		x;
	int		y;
}	t_draw;

typedef struct s_txt
{
	char	*type;
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		tmp_delay;
	int		delay;
	int		current_frame;
	int		frame_max;
	int		x;
	int		y;
	int		launched;
}	t_txt;

typedef struct s_rotation_ray
{
	double	ray_x[50];
	double	ray_y[50];
	double	angle_rad;
	double	pdx;
	double	pdy;
}	t_rr;

typedef struct s_door
{
	int		is_open;
	int		is_closing;
	double	x;
	double	y;
	t_txt	*txt;
	int		frame;
}	t_door;

typedef struct s_raycast
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	int		is_door;
	t_door	*door;
	t_txt	*txt;
	double	vdx;
	double	vdy;
	double	dx;
	double	dy;
	double	hdx;
	double	hdy;
	double	vd_dist;
	double	hd_dist;
	double	d_dist;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	hx;
	double	hy;
	double	h_dist;
	double	vx;
	double	vy;
	double	v_dist;
	double	dist;
	char	flag;
	char	door_flag;
}	t_raycast;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	int		hp;
	int		weapon;
	int		arrows;
	int		atk;
	int		atk_item_amount;
	int		speed_item_amount;
	int		hit;
	int		last_atk;
	double	speed;
}	t_player;

typedef struct sf
{
	int		i;
	int		j;
	int		x;
	char	**tmp;
}	t_sf;

typedef struct s_enemy
{
	t_txt		txt;
	double		x;
	double		y;
	double		dist;
	long int	last_attack;
	char		type;
	int			hp;
	int			hurt;
	int			attacking_bool;
	int			draw_start;
	int			draw_end;
	int			dead;
	double		scale;
	int			z_index;
	int			atk_max_frame;
	int			death_max_frame;
	int			hurt_max_frame;
	int			idle_max_frame;
	int			run_max_frame;
	int			attack_range;
}	t_enemy;

typedef struct s_item
{
	t_txt		*txt;
	double		x;
	double		y;
	double		dist;
	char		type;
	int			display;
	int			msg;
	long int	last_text;
}	t_item;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		e;
	int		left;
	int		right;
	int		mouse_l;
}	t_key;

typedef struct s_cube
{
	t_map			map;
	t_map			map2;
	t_map			map3;
	t_txt			*txt;
	t_txt			*sword_ani;
	t_txt			*crossbow;
	t_txt			*dragon;
	t_txt			*explosion;
	t_txt			*nums;
	t_txt			*hp_frame;
	t_txt			*abc;
	t_txt			*title_screen;
	t_txt			*main_menu_bg;
	t_txt			*main_menu_assets;
	t_txt			*main_menu_start;
	t_txt			*game_over;
	t_txt			*keyboard;
	t_txt			**nightborne;
	t_txt			**skeleton;
	t_txt			**warrior;
	t_txt			**skullwolf;
	t_txt			**s_warrior;
	t_txt			**plague_doctor;
	t_txt			**player_animations;
	t_txt			**cute_wolf;
	t_txt			*crown;
	t_txt			*door;
	t_txt			*rat;
	t_txt			*victory_ani;
	t_player		player;
	t_key			key;
	t_rr			rr;
	t_raycast		*rays;
	t_enemy			*all_enemies;
	t_item			*weapons;
	t_item			*items;
	t_item			*dropped_items;
	t_door			*doors;
	char			*path;
	int				endian;
	int				crown_index;
	int				player_run_value;
	int				dropped_index;
	int				level;
	int				victory;
	int				next_lvl_start;
	int				next_lvl_end;
	int				idle_delay;
	int				minimap_bool;
	int				bits_per_pixel;
	int				*crown_frame;
	void			*con;
	void			*win;
	char			*addr;
	void			*img;
	int				retry;
	int				enemies_nb;
	int				title_bool;
	int				bg_bool;
	int				fov;
	int				line_length;
	int				f_rgb;
	int				c_rgb;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	int				start;
	int				mouse_x;
	int				mouse_y;
	int				option_bool;
	int				door_open_msg;
	int				door_close_msg;
	int				weapon_counter;
	int				enemy_counter;
	int				items_counter;
	int				door_counter;
	int				sensi;
	int				speed;
	int				weapons_in_slot[4];
	int				tuto;
	double			fade_factor;
	double			p_rotation;
	unsigned char	fade_r;
	unsigned char	fade_g;
	unsigned char	fade_b;
}	t_cube;

char		**ft_split(char const *s, char const c);
char		**read_file(char *path);
void		save_file(t_cube *cub, char **file);
void		freetab(char **tab);
void		free_stuff2(t_cube *cub);
int			tablen(char **tab);
int			get_fd(char *file);
int			ft_equalstr(char const *str, char const *str2);
void		variables_checker(t_cube *cub);
int			first_and_last_checker(char **map);
int			char_checker(char *line);
int			space_checker_horizontal(char **map);
int			space_checker_vertical(char **map);
void		exit_free(t_cube *cub);
void		check_door(t_cube *cub);
void		free_stuff(t_cube *cub);
void		map_filler(t_map *map);
int			check_cub(char *file);
void		window_init(t_cube *cub);
void		fill_player(t_cube *cub);
long int	get_current_time(void);
void		player_checker(t_cube *cub);
void		load_textures(t_cube *cub, t_txt *txt, int num);
void		init_rays(t_cube *cub);
void		player_rotation_init(t_cube *cub);
void		rotate_player(t_cube *cub, double dir);
void		player_rotation_keys(int key, t_cube *cub);
void		cast_ray(t_cube *cub, int index);
void		map_parsing(t_cube *cub);
void		render_3d(t_cube *cub, t_raycast *ray);
int			rgb_to_hex(int r, int g, int b);
void		draw_player_to_image(t_cube *cub);
void		draw_map_to_image(t_cube *cub);
int			search_txt(t_cube *cub, char c);
double		dist(double ax, double ay, double bx, double by);
t_door		*search_door(t_cube *cub, int x, int y);
void		save_doors(t_cube *cub);

void		draw_xpm_animation(int alpha, int x, int y, t_txt *txt);
void		draw_xpm_hp(int alpha, int x, int y, t_cube *cub);
void		draw_xpm_texture(int alpha, int x, int y, t_cube *cub);
void		draw_xpm_number(int alpha, int x, int y, t_cube *cub);
void		draw_xpm_alpha(int alpha, int x, int y, t_cube *cub);

int			update_animation(t_cube *cub);
void		animate_health_bar(t_cube *cub, int limite);
char		*to_str(int n);
void		increment_numbers(char **str, int index);
void		increment_numbers_2(char *str, int index);
void		increment_alphabet(char *str, int index);
void		hp_handler(t_cube *cub);
void		init_w_slots(t_cube *cub);
void		weapon_slot_handler(t_cube *cub);
void		sword_handler(t_cube *cub);
void		update_animation_crossbow(t_cube *cub);
void		crossbow_handler(t_cube *cub);
void		shield_handler(t_cube *cub);
void		dragon_handler(t_cube *cub);
void		update_animation_dragon(t_cube *cub);
void		explosion_handler(t_cube *cub);
void		update_animation_explosion(t_cube *cub);
void		title_handler(t_cube *cub);
void		bg_handler(t_cube *cub);
void		start_handler(t_cube *cub);
void		died_handler(t_cube *cub);
void		update_dist(t_cube *cub);

void		speed_option(t_cube *cub);
void		sensi_option(t_cube *cub);
void		fov_option(t_cube *cub);
void		draw_options(t_cube *cub);
void		fade_to_black(t_cube *cub, double fade_factor, int bits_per_pixel);
t_cube		*call_cub(void);

void		draw_square_to_image(t_cube *cub, int x, int y, int color);
void		render_game(t_cube *cub);
void		draw_weapon(t_cube *cub, int index);
void		draw_item(t_cube *cub, t_item item);
void		display_messages(t_cube *cub);
void		draw_enemy(t_cube *cub, t_enemy *enemy);
void		check_pick_up(t_cube *cub);
void		update_animation_txt(t_txt *txt, t_door *door);
t_txt		*txt_handler(t_cube *cub, t_txt *txt, int max_frame, t_raycast ray);
void		update_animation_txt_r(t_txt *txt, t_door *door);
t_txt		*txt_handler_r(t_cube *cub, t_txt *txt, t_raycast ray);
int			can_walk(t_cube *cub, int y, int x);
t_txt		enemy_animation_handler(t_txt *txt, int max_frame);
t_txt		enemy_animation_atk(t_cube *cub, t_txt *txt,
				t_enemy *enemy, int dist);
t_txt		enemy_animation_death(t_cube *cub, t_txt *txt,
				t_enemy *enemy, int max_frame);
void		draw_sprite(t_cube *cub, t_txt *txt, double scale, int z_index);
void		explosion_sprite(t_cube *cub);
t_txt		enemy_animation_hurt(t_cube *cub, t_txt *txt,
				t_enemy *enemy, int max_frame);
t_txt		*crown_handler(t_txt *txt);
void		animation_handler(t_txt *txt, t_cube *cub, int x, int y);
void		start_keys(t_cube *cub);
void		init_enemies(t_cube *cub);
void		random_item(t_cube *cub, t_item *item);
void		equip_item(t_cube *cub, char type);
void		add_weapon_to_slot(t_cube *cub, int index);
void		minimap_option(t_cube *cub);
void		change_print(int *print);
void		display_dropped_msg(t_cube *cub, int *print);
void		update_animation_atk(t_txt *txt);
void		update_animation_start(t_cube *cub);
void		map_parsing6(t_cube *cub, t_mparse *mp);
void		map_parsing11(t_cube *cub, t_mparse *mp);
void		color_background(t_cube *cub, int length, int ray_i);
void		draw_vertical_line(t_cube *cub, t_raycast *ray);
void		check_vertical(t_cube *cub, t_raycast *ray);
void		check_horizontal(t_cube *cub, t_raycast *ray);
void		enemy_handler(t_cube *cub, t_enemy *enemy, t_txt **txt);
int			close_x(t_cube *cub);
void		mouse_rotate(t_cube *cub);
int			mouse_events(int key);
int			handle_key_press(int key, t_cube *cub);
int			handle_key_release(int key, t_cube *cub);
void		tutorial(t_cube *cub, int bits_per_pixel);
int			is_corner(t_cube *cub, int x, int y);
int			remove_corners(t_cube *cub, int x, int y);
void		n_attack(t_cube *cub, int *i);
void		n_run(t_cube *cub, int *i);
void		save_txt(t_cube *cub, int i, int y, char *num);
void		init_nightborne(t_cube *cub);
void		init_cute_wolf(t_cube *cub);
void		init_plague_doctor(t_cube *cub);
void		init_s_warrior(t_cube *cub);
void		init_skullwolf(t_cube *cub);
void		init_warrior(t_cube *cub);
void		init_skeleton(t_cube *cub);
void		init_player_animations(t_cube *cub);
void		init_keyboard(t_cube *cub);
void		init_game_over(t_cube *cub);
void		init_main_menu_start(t_cube *cub);
void		init_main_menu_bg(t_cube *cub);
void		init_title(t_cube *cub);
void		init_explosion(t_cube *cub);
void		init_dragon(t_cube *cub);
void		init_crossbow(t_cube *cub);
void		init_hp(t_cube *cub);
void		init_sword(t_cube *cub);
void		init_numbers(t_cube *cub);
void		init_door(t_cube *cub);
void		init_crown(t_cube *cub);
void		init_main_menu_a(t_cube *cub);
void		init_textures(t_cube *cub);
void		init_alphabet(t_cube *cub);
void		next_map(t_cube *cub);
void		player_movement_w2(t_cube *cub);
void		player_movement_w3(t_cube *cub);
void		player_movement_w4(t_cube *cub);
void		player_movement_w(t_cube *cub);
void		player_movement_s2(t_cube *cub);
void		player_movement_s3(t_cube *cub);
void		player_movement_s4(t_cube *cub);
void		player_movement_s5(t_cube *cub);
void		player_movement_s(t_cube *cub);
void		player_movement_a2(t_cube *cub);
void		player_movement_a3(t_cube *cub);
void		player_movement_a4(t_cube *cub);
void		player_movement_a5(t_cube *cub);
void		player_movement_a(t_cube *cub);
void		player_movement_d2(t_cube *cub);
void		player_movement_d3(t_cube *cub);
void		player_movement_d4(t_cube *cub);
void		player_movement_d5(t_cube *cub);
void		player_movement_d(t_cube *cub);
void		player_movement(t_cube *cub);
void		dying_handler(t_cube *cub);
void		hud_options_handler(t_cube *cub);
void		bg_true(t_cube *cub);
void		put_enemies(t_cube *cub);
void		free_txt(t_cube *cub);
void		free_imgs(t_cube *cub, t_txt *txts, int max);
void		free_animations(t_cube *cub, t_txt **txts, int max);
void		init_victory_ani(t_cube *cub);
void		init_rat(t_cube *cub);
void		color_filler(t_cube *cub, char **tab, char **file);
void		save_file(t_cube *cub, char **file);
void		cv_helper(t_raycast *ray, double px, double py);
void		cv_helper2(t_cube *cub, t_raycast *ray, double px, double py);
char		*rm_xpm(char *str);
char		*str_add_end(char *str, char c);
char		*rm_last_c(char *str);
int			loop_hook(t_cube *cub);
void		loop_hook_helper(t_cube *cub);

#endif