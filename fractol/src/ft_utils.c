#include "fractol.h"

int	ft_mlx_error(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_display(mlx_ptr);
	free(win_ptr);
	free(mlx_ptr);
	ft_printf("Error : no window created\n");
	return (MLX_ERROR);
}

void	ft_mlx_free(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
