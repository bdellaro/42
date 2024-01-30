#include "../include/so_long.h"

void	ft_init_map(t_solong *solong)
{
	solong->i = 0;
	solong->j = 0;
	solong->map.count_p = 0;
	solong->map.count_e = 0;
	solong->map.count_c = 0;
	solong->map.collected = 0;
	solong->map.can_exit = 0;
	solong->count_step = 0;
	solong->win_height = solong->map.count_line * IMG_SIZE;
	solong->win_width = (ft_strlen(solong->map.map[0]) - 1) * IMG_SIZE;
	solong->image.height = IMG_SIZE;
	solong->image.width = IMG_SIZE;
}
