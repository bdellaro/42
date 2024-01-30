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

typedef struct	s_img
{
	int		width;
	int		height;
	int		line_length;
	
	

}			t_img;

typedef struct	s_map
{
	int		fd;
	int		count_line;
	int		count_p;
	int		count_e;
	int		count_c;
	int		can_exit;
	int		collected;
	char	*path;
	char	**map;
	size_t		line_len;

}			t_map;

typedef struct	s_solong
{
	char	*name;
	int		p_i;
	int		p_y;
	int		i;
	int		j;
	int		win_width;
	int		win_height;
	int		count_step;
	mlx_t		*mlx;
	mlx_texture_t	*texture;
	mlx_image_t	*img;
	t_map	map;
	t_img	image;

}			t_solong;

int		ft_put_key(int keysym, t_solong *solong);
int		ft_string_on_window(t_solong *solong);
int		ft_handle_input(int keysym, t_solong *solong);
void	ft_arguments_check(int argc, char **argv);
void	ft_solong_init(t_solong *solong);
void	ft_mlx_exit(t_solong *solong);

#endif
