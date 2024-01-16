#include "fractol.h"

int	ft_mlx_error(t_mlx_data *mlx_data)
{
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->win_ptr);
	free(mlx_data->mlx_ptr);
	ft_printf("Error : no window created\n");
	return (MLX_ERROR);
}

void	ft_mlx_free(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
}
