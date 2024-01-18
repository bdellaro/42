#include "../include/fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;

	c.x = ft_map(x, -2, +2, 0, WIDTH);
	c.y = ft_map(y, +2, -2, 0, HEIGHT);
	while (i < fractal->iteration_definition)
	{
	z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_value) 
		{
			color = ft_map(i, BLACK, WHITE, 0,
			fractal->iteration_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (y++ < HEIGHT)
	{
		while (x++ < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
	fractal->img.img_ptr, 0, 0);
}
