/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:37 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:53 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	malloc_error(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

void	ft_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_len + x *
	(img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_color_screen(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_pixel_put(&solong->img, j, i, solong->color);
			j++;
		}
		i++;
	}
}

void	ft_solong_init(t_solong *solong)
{
	char	*image = "../images/test.xpm";
	int	img_width;
	int	img_height;

	solong->mlx_ptr = mlx_init();
	if (solong->mlx_ptr == NULL)
		malloc_error();
	solong->win_ptr = mlx_new_window(solong->mlx_ptr,
			WIDTH, HEIGHT, solong->name);
	if (solong->win_ptr == NULL)
	{
		mlx_destroy_display(solong->mlx_ptr);
		free(solong->mlx_ptr);
		malloc_error();
	}
//	mlx_loop_hook(solong->mlx_ptr, ft_string_on_window, solong);
//	mlx_loop_hook(solong->mlx_ptr, , solong);
	solong->img.img_ptr = mlx_new_image(solong->mlx_ptr, WIDTH, HEIGHT);
	solong->img.address = mlx_get_data_addr(solong->img.img_ptr,
                                            &solong->img.bits_per_pixel,
                                            &solong->img.line_len,
                                            &solong->img.endian);
	ft_color_screen(solong);
	mlx_put_image_to_window(solong->mlx_ptr, solong->win_ptr,
	solong->img.img_ptr, 0, 0);
	mlx_new_image(solong->mlx_ptr, WIDTH, HEIGHT);

/*	solong->img.img_ptr = mlx_xpm_file_to_image(solong->mlx_ptr,
	image, &img_width, &img_height);
	if (solong->img.img_ptr == NULL)
		ft_printf("ERREUUUUUUR IMG\n");*/
	mlx_key_hook(solong->win_ptr, ft_handle_input, solong);
	ft_printf("Press ESC to quit.\n");
	mlx_loop(solong->mlx_ptr);
}
