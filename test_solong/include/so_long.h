#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>

# define IMG_SIZE 64

# define A 97
# define D 100
# define S 115
# define W 119
# define KEY_ESCAPE 65307
# define MLX_ESCAPE 256
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"

# define SMALL	"./maps/small.ber"
# define MEDIUM	"./maps/medium.ber"
# define BIG	"./maps/big.ber"

# define GRASS	"./sprites/grass64.png"
# define WALL	"./sprites/wall264.png"
# define STONE	"./sprites/stone64.png"
# define STAR	"./sprites/star64.png"
# define EXIT	"./sprites/exit264.png"
# define PERSO	"./sprites/perso64.png"

# define MLX_ERROR -1

typedef struct s_set
{
	char	stone;
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
}		t_set;

typedef struct	s_texture
{
	void	*tex_stone;
	void	*tex_floor;
	void	*tex_wall;
	void	*tex_collect;
	void	*tex_player;
	void	*tex_exit;

}		t_texture;

typedef struct	s_img
{
	void	*img_stone;
	void	*img_floor;
	void	*img_wall;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	int			 width;
	int			 height;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
	char	*stone;
	char	*range;

}		t_img;

typedef struct	s_map
{
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			width;
	int			height;
	int			count;
	int			line_height;
	int			line_width;
	char	**map;

}		t_map;

typedef struct	s_solong
{
	char	*data_map;
	char	*name;
	char	*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			window_width;
	int			window_height;
	int			total_length;

	t_texture	tex;
	t_map		map;
	t_img		img;
	t_set		content;
	mlx_t		*mlx;
	mlx_texture_t	*texture;
	mlx_image_t	*mlx_img;
	mlx_key_data_t	*keydata;

}		t_solong;

int	ft_dispatch_cards(t_solong *solong);
int	ft_size_of_map(char**map);
int	ft_check_content(t_solong *solong);
int	ft_check_error_map(char *data_map, t_set *content, t_solong *solong);
char	*get_next_line(int fd);
void	ft_map_to_2d(t_solong *solong);
void	ft_read_map(char *map, t_solong *solong);
void	process_back_image(t_solong *solong);
void	draw_image_at_index(t_solong *solong, void *img, int i);
void	set_content(t_set *content);
void	struct_image(t_solong *solong);
void	ft_first_init(char *path, char *upper, char **argv);
void	ft_check_map_line(t_solong *solong);
void	ft_free_solong(t_solong *solong);
void	ft_hook(t_solong *solong);
void	ft_check_vertical_borders(t_solong *solong);
void	ft_solong_init(char *map, t_solong *solong);
void	ft_init_player(t_solong *solong);
void	ft_delete_mlx(t_solong *solong);
void	ft_init_map(t_solong *solong);
void	ft_map_to_screen(t_solong *solong);

#endif
