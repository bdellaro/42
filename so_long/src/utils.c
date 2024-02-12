#include "../include/so_long.h"

void	ft_r(void)
{
	int	 write_error;
		
	write_error = write(1, "\r", 1);
	(void)write_error;
}

void	ft_delete_mlx(t_solong *solong)
{
	/*mlx_delete_image(solong->mlx, solong->img.img_wall);
	mlx_delete_image(solong->mlx, solong->img.img_stone);
	mlx_delete_image(solong->mlx, solong->img.img_exit);
	mlx_delete_image(solong->mlx, solong->img.img_player);
	mlx_delete_image(solong->mlx, solong->img.img_floor);
	mlx_delete_image(solong->mlx, solong->img.img_collect);
	mlx_delete_texture(solong->tex.tex_wall);
	mlx_delete_texture(solong->tex.tex_stone);
	mlx_delete_texture(solong->tex.tex_exit);
	mlx_delete_texture(solong->tex.tex_player);
	mlx_delete_texture(solong->tex.tex_floor);
	mlx_delete_texture(solong->tex.tex_collect);*/
	mlx_terminate(solong->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_error_image(char *texture)
{
	ft_printf("Error\nUnable to load texture --> %s\n", texture);
	exit(EXIT_FAILURE);
}

void	ft_free_solong(t_solong *solong)
{
	if (solong->data_map != NULL)
	{
		free(solong->data_map);
		solong->data_map = NULL;
	}
}
