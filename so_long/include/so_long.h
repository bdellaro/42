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

# define IMG_SIZE 32

# define A 97
# define D 100
# define S 115
# define W 119

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

# define GRASS	"./sprites/grass.png"
# define WALL	"./sprites/wall.png"
# define STONE	"./sprites/stone.png"
# define STAR	"./sprites/star.png"
# define EXIT	"./sprites/exit.png"
# define PERSO	"./sprites/perso.png"

# define MLX_ERROR -1

typedef struct s_set
{
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

typedef struct s_img
{
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

	t_map		map;
	t_img		img;
	t_set		content;
	mlx_t		*mlx;
	mlx_texture_t	*texture;
	mlx_image_t	*mlx_img;

}		t_solong;

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
void	ft_check_vertical_borders(t_solong *solong);
void	ft_solong_init(char *map, t_solong *solong);
void	ft_init_player(t_solong *solong);
void	ft_init_map(t_solong *solong);

#endif
