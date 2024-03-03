/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:09:22 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/03 19:08:04 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_string_screen(t_solong *solong)
{
	char	*c;
	char	*str;

	str = "STEPS DONE";
	c = ft_itoa(solong->map.count);
	mlx_put_string(solong->mlx, c, \
	solong->window_width / 2 + (ft_strlen(str) * 5), \
	solong->window_height - 20);
	mlx_put_string(solong->mlx, str, \
	solong->window_width / 2 - (ft_strlen(str) * 6), \
	solong->window_height - 20);
//	free(str);
}

void	ft_animation_enemy(void *solong_ptr)
{
	static int				b = 1;
	static struct timeval	last_change = {0, 0};
	struct timeval			current_time;
	long					time_difference;
	t_solong				*solong;

	solong = (t_solong *)solong_ptr;
	gettimeofday(&current_time, NULL);
	time_difference = (current_time.tv_sec - last_change.tv_sec) * \
	1000000L + (current_time.tv_usec - last_change.tv_usec);
	if (time_difference > 200000)
	{
		if (b == 0)
		{
			ft_enemy_1(solong);
			b = 1;
		}
		else
		{
			ft_enemy_2(solong);
			b = 0;
		}
		last_change = current_time;
	}
	return ;
}

void	ft_animation(void *solong_ptr)
{
	static int				b = 1;
	static struct timeval	last_change = {0, 0};
	struct timeval			current_time;
	long					time_difference;
	t_solong				*solong;

	solong = (t_solong *)solong_ptr;
	ft_animation_enemy(solong_ptr);
	gettimeofday(&current_time, NULL);
	time_difference = (current_time.tv_sec - last_change.tv_sec) * \
	1000000L + (current_time.tv_usec - last_change.tv_usec);
	if (time_difference > 300000)
	{
		if (b == 0)
		{
			ft_star_b(solong);
			b = 1;
		}
		else
		{
			ft_star(solong);
			b = 0;
		}
		last_change = current_time;
	}
}
