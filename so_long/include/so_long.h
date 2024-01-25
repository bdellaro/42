#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1200
# define HEIGHT 800

# define MLX_ERROR -1

# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

# define MAGENTA_BURST   0xFF00FF  
# define LIME_SHOCK      0xCCFF00  
# define NEON_ORANGE     0xFF6600  
# define PSYCHEDELIC_PURPLE 0x660066  
# define AQUA_DREAM      0x33CCCC  
# define HOT_PINK        0xFF66B2 
# define ELECTRIC_BLUE   0x0066FF 
# define LAVA_RED        0xFF3300 

typedef struct	s_data
{
	void	*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}			t_data;

typedef struct	s_solong
{
	void	*mlx_ptr;
	void	*win_ptr;
	char		*key_pressed;
	char		*name;
	char		*arg;
	int			color;
	t_data	img;
}			t_solong;

int		ft_put_key(int keysym, t_solong *solong);
int		ft_string_on_window(t_solong *solong);
int		ft_handle_input(int keysym, t_solong *solong);
void	ft_arguments_check(int argc, char **argv);
void	ft_solong_init(t_solong *solong);
void	ft_mlx_exit(t_solong *solong);
void	my_pixel_put(t_data *img, int x, int y, int color);

#endif
