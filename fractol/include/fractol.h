/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:24:33 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/18 17:13:08 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1200
# define HEIGHT 800
# define SIDE_LEN 800

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

typedef struct	s_img
{
	void	*img_ptr;
	char		*img_pixel_ptr;
	int			bit_per_pixel;
	int			endian;
	int			line_len;
}			t_img;

typedef struct	s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	char		*key_pressed;
	char		*name;
	int			color;
	t_img	img;
}			t_fractal;

int		ft_put_key(int keysym, t_fractal *fractal);
int		ft_string_on_window(t_fractal *fractal);
int		ft_handle_input(int keysym, t_fractal *fractal);
void	ft_arguments_check(int argc, char **argv);
void	ft_fractal_init(t_fractal *fractal);

#endif