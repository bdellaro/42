/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:40 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/28 14:14:20 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_is_else(t_solong *solong)
{
	solong->content.count_key++;
	if (solong->content.count_c < 10)
		ft_printf("		 Left -> \033[1;37m[%d] \
		\033[0m", solong->content.count_c);
	else
		ft_printf("		 Left -> \033[1;37m[%d] \
		\033[0m", solong->content.count_c);
	ft_r();
}

void	ft_is_key(mlx_key_data_t keydata, t_solong *solong)
{
	if (keydata.key == W || keydata.key == KEY_UP)
	{
		ft_printf("Step -> \033[1;37mUP   \033[0m");
		ft_r();
		ft_card_path(solong, 'w');
	}
	if (keydata.key == S || keydata.key == KEY_DOWN)
	{
		ft_printf("Step -> \033[1;37mDOWN \033[0m");
		ft_r();
		ft_card_path(solong, 's');
	}
	if (keydata.key == A || keydata.key == KEY_LEFT)
	{
		ft_printf("Step -> \033[1;37mLEFT \033[0m");
		ft_r();
		ft_card_path(solong, 'a');
	}
	if (keydata.key == D || keydata.key == KEY_RIGHT)
	{
		ft_printf("Step -> \033[1;37mRIGHT\033[0m");
		ft_r();
		ft_card_path(solong, 'd');
	}
}

int	ft_check_key(mlx_key_data_t keydata)
{
	return (keydata.key == W || keydata.key == \
		KEY_ESCAPE || keydata.key == A || \
		keydata.key == S || keydata.key == D || \
		keydata.key == KEY_UP || keydata.key == \
		KEY_DOWN || keydata.key == KEY_LEFT || \
		keydata.key == KEY_RIGHT);
}

void	ft_print_key(mlx_key_data_t keydata, void *solong_ptr)
{
	t_solong	*solong;

	solong = (t_solong *)solong_ptr;
	ft_string_screen(solong);
	if (keydata.action == 1)
	{
		ft_is_key(keydata, solong);
		if (keydata.key == KEY_ESCAPE)
		{
			ft_printf("\n\n\033[1;35m[ECHAP PRESSED]\033[0m\n");
			ft_free_solong(solong);
			ft_delete_mlx(solong);
		}
		if (!(ft_check_key(keydata)))
		{
			ft_printf("Wrong key pressed. Use W, A, S, D ");
			ft_printf("to move               \n");
		}
		if (ft_check_key(keydata))
			ft_is_else(solong);
	}
}

void	ft_hook(t_solong *solong)
{
	char	*how_to;
	char	*beware;

	beware = "Beware of aliens !";
	how_to = "Use W, A, S, D to move, press ESC to quit";
	mlx_put_string(solong->mlx, beware, solong->window_width \
	/ 2 - (ft_strlen(beware) * 5), 25);
	mlx_put_string(solong->mlx, how_to, solong->window_width \
	/ 2 - (ft_strlen(how_to) * 5), solong->window_height - 42);
}
