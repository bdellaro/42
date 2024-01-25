#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/mlx42.h"
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

typedef struct s_instance
{
	int	x;
	int	y;
}			t_instance;

/*typedef struct	s_image
{
	int	width;
	int	height;
	int		pixels;
	instance_t	*instance;
	int	count
	bool	enabled;
	void	*context;
}			t_image;*/

typedef struct	s_solong
{
	mlx_t		*mlx;
	mlx_texture_t	*texture;
	char		*key_pressed;
	char		*name;
	char		*arg;
	int			color;
	mlx_image_t	*img;
}			t_solong;

int		ft_put_key(int keysym, t_solong *solong);
int		ft_string_on_window(t_solong *solong);
int		ft_handle_input(int keysym, t_solong *solong);
void	ft_arguments_check(int argc, char **argv);
void	ft_solong_init(t_solong *solong);
void	ft_mlx_exit(t_solong *solong);

#endif
