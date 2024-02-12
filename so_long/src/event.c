#include "../include/so_long.h"

int	ft_check_key(mlx_key_data_t keydata)
{
	return (keydata.key == W || keydata.key == KEY_ESCAPE || keydata.key == A || keydata.key == S || keydata.key == D || keydata.key == KEY_UP || keydata.key == KEY_DOWN || keydata.key == KEY_LEFT || keydata.key == KEY_RIGHT);
}
void	ft_print_key(mlx_key_data_t keydata, void *solong_ptr)
{
	t_solong	*solong;

	solong = (t_solong *)solong_ptr;
	if (keydata.action == 1)
	{
		if (keydata.key == W || keydata.key == KEY_UP)
		{
			ft_printf("Step -> \033[1;37mUP   \033[0m");
			ft_r();
		}
		if (keydata.key == S || keydata.key == KEY_DOWN)
		{
			ft_printf("Step -> \033[1;37mDOWN \033[0m");
			ft_r();
		}
		if (keydata.key == A || keydata.key == KEY_LEFT)
		{
			ft_printf("Step -> \033[1;37mLEFT \033[0m");
			ft_r();
		}
		if (keydata.key == D || keydata.key == KEY_RIGHT)
		{
			ft_printf("Step -> \033[1;37mRIGHT\033[0m");
			ft_r();
		}
		if (keydata.key == KEY_ESCAPE)
		{
			ft_printf("\n\n\033[1;35mECHAP key pressed !\033[0m\n");
			ft_delete_mlx(solong);
		}
		if (!(ft_check_key(keydata)))
		{	
			ft_printf("Wrong key pressed. Use W, A, S, D to move\n");
		}
		if (ft_check_key(keydata))
		{
			solong->content.count_key++;
			ft_printf("		\033[1;35m[ %d ]\033[0m", solong->content.count_key);
			ft_r();
		}
	}
}

void	ft_hook(t_solong *solong)
{
	char	*how_to;
	char	*to_quit;

	how_to = "Use W, A, S, D to move !";
	to_quit = "Press ECHAP to quit game";

	mlx_put_string(solong->mlx, how_to, solong->window_width / 2 - (ft_strlen(how_to) * 5),
	solong->window_height / 2 - 10);
	mlx_put_string(solong->mlx, to_quit, solong->window_width / 2 - (ft_strlen(to_quit) * 5),
	solong->window_height / 2 + 10);
	mlx_key_hook(solong->mlx, &ft_print_key, solong);
	mlx_loop(solong->mlx);
//	ft_movement(&keydata, solong);
}

void	ft_movement(mlx_key_data_t keydata, void *solong_ptr)
{
	t_solong	*solong;
	solong = (t_solong *)solong_ptr;
	if (mlx_is_key_down(solong->mlx, MLX_KEY_S))
		ft_printf("Key pressed : %d\n", keydata.key);
}
