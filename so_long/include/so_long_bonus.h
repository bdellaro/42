/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:19:31 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/29 18:19:37 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1

# define IMG_SIZE 64

# define A 65
# define D 68
# define S 83
# define W 87
# define KEY_ESCAPE 256
# define KEY_UP 265
# define KEY_DOWN 264
# define KEY_RIGHT 262
# define KEY_LEFT 263

# define SMALL	"./maps/small.ber"
# define MEDIUM	"./maps/medium.ber"
# define BIG	"./maps/big.ber"

# define SMALL_B	"./maps/bonus/bonus_small.ber"
# define MEDIUM_B	"./maps/bonus/bonus_medium.ber"
# define BIG_B 		"./maps/bonus/bonus_big.ber"

# define GRASS		"./sprites/grass64.png"
# define WALL		"./sprites/wall64.png"
# define STAR		"./sprites/star64.png"
# define STAR_B 	"./sprites/star64_b.png"
# define EXIT		"./sprites/exit64.png"
# define PERSO_A	"./sprites/perso64_a.png"
# define PERSO		"./sprites/perso64.png"
# define STONE		"./sprites/stone64.png"
# define ENEMY		"./sprites/enemy64.png"
# define ENEMY_B	"./sprites/enemy64_b.png"
# define PERSO_W	"./sprites/perso64_w.png"
# define PERSO_S	"./sprites/perso64_s.png"

typedef struct s_set
{
	char	stone;
	char	enemy;
	char	exit;
	char	player;
	char	wall;
	char	floor;
	char	range;
	char	sl;
	char	collect;
	int		collected;
	int		exit_win;
	int		count_p;
	int		count_e;
	int		count_c;
	int		count_key;
}					t_set;

typedef struct s_texture
{
	void	*tex_stone;
	void	*tex_floor;
	void	*tex_wall;
	void	*tex_collect;
	void	*tex_exit;
	void	*tex_player;
	void	*tex_player_a;
	void	*tex_enemy;
	void	*tex_enemy_b;
	void	*tex_collect_b;
	void	*tex_player_w;
	void	*tex_player_s;
}					t_texture;

typedef struct s_img
{
	void	*img_stone;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_collect_b;
	void	*img_player;
	void	*img_player_a;
	void	*img_enemy;
	void	*img_enemy_b;
	void	*img_exit;
	void	*img_player_w;
	void	*img_player_s;
}					t_img;

typedef struct s_map
{
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		count;
	int		line_height;
	int		line_width;
	char	**map;
}					t_map;

typedef struct s_solong
{
	int				**visited;
	int				line_length;
	int				width;
	int				height;
	int				path_found;
	int				window_width;
	int				window_height;
	int				visited_items;
	int				total_length;
	int				arg;
	char			movement;
	char			*data_map;
	char			*name;
	char			*addr;
	t_texture		tex;
	t_map			map;
	t_img			img;
	t_set			content;
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
	mlx_texture_t	*texture;
	mlx_key_data_t	*keydata;
}					t_solong;

int		ft_collapse_img(t_solong *solong);
int		ft_pull_next_card(t_solong *solong, char movement, char card);
int		ft_is_movable(t_solong *solong, char movement);
int		ft_dispatch_cards(t_solong *solong);
int		ft_is_content(t_solong *solong, int i);
int		ft_check_content(t_solong *solong);
int		ft_loose_game(t_solong *solong, char movement);

char	*get_next_line(int fd);

void	ft_animation(void *solong_ptr);
void	ft_bonus_image(t_solong *solong);
void	ft_bonus_texture(t_solong *solong);
void	ft_valid_path(t_solong *solong);
void	ft_free_2d(char **map);
void	ft_is_winable(t_solong *solong);
void	ft_free_array(mlx_image_t **arr, t_solong *solong);
void	ft_map_to_2d(t_solong *solong);
void	ft_read_map(char *map, t_solong *solong);
void	ft_print_map_error(t_solong *solong, int fd);
void	ft_free_solong(t_solong *solong);
void	ft_hook(t_solong *solong);
void	ft_solong_init(char *map, t_solong *solong, int arg);
void	ft_delete_mlx(t_solong *solong);
void	ft_init_map(t_solong *solong);
void	ft_map_to_screen(t_solong *solong);
void	ft_r(void);
void	ft_delete_mlx(t_solong *solong);
void	ft_error(void);
void	ft_error_image(char *texture);
void	ft_free_solong(t_solong *solong);
void	ft_card_path(t_solong *solong, char movement);
void	ft_write(t_solong *solong);
void	ft_set_clean(t_solong *solong);
void	ft_collect_pot(t_solong *solongi, char movement);
void	ft_init_image(t_solong *solong);
void	ft_content_error(t_solong *solong);
void	ft_bonus_collapse(t_solong *solong);
void	ft_string_screen(t_solong *solong);
void	ft_enemy_1(t_solong *solong);
void	ft_enemy_2(t_solong *solong);
void	ft_print_key(mlx_key_data_t keydata, void *solong_ptr);
void	ft_wall(t_solong *solong);
void	ft_star_b(t_solong *solong);
void	ft_player_a(t_solong *solong);
void	ft_star(t_solong *solong);
void	ft_stone(t_solong *solong);
void	ft_key_a(t_solong *solong);
void	ft_key_d(t_solong *solong);
void	ft_player_w(t_solong *solong);
void	ft_player_s(t_solong *solong);
void	ft_key_w(t_solong *solong);
void	ft_key_s(t_solong *solong);
void	ft_player(t_solong *solong);

#endif
