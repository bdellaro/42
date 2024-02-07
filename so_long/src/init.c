#include "../include/so_long.h"

void	ft_init_map(t_solong *solong)
{	
	solong->map.y = 0;
	solong->map.x = 0;
	solong->window_height = solong->map.line_height * IMG_SIZE;
	solong->window_width  = (solong->map.line_width) * IMG_SIZE;  
//	ft_printf("%d et %d\n", solong->window_height, solong->window_width);
}

void	ft_init_player(t_solong *solong)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (solong->map.map[y])
	{
		while (solong->map.map[y][x])
		{
			if(solong->map.map[y][x] == solong->content.player)
			{
				solong->map.player_y = y;
				solong->map.player_x = x;
				 // Ajoutez cette ligne pour imprimer les valeurs de player_x et player_y
                		ft_printf("Position du joueur trouvée : x = %d, y = %d\n dans player_x : %d player_y %d", x, y,
				solong->map.player_x, solong->map.player_y);
			}
			x++;
		}
		x = 0;
		y++;	
	}
}


void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_set_to_zero(t_solong *solong)
{
	solong->content.wall = '1';
	solong->content.floor = '0';
	solong->content.player = 'P';
	solong->content.exit = 'E';
	solong->content.sl = '\n';
	solong->content.collect = 'C';
	solong->content.count_p = 0;
	solong->content.count_e = 0;
	solong->content.count_c = 0;	
}

void	ft_solong_init(char *map, t_solong *solong)
{
	ft_set_to_zero(solong);
	ft_read_map(map, solong);
	ft_check_content(solong);
	ft_printf("Map width  = %d\nMap height = %d\n\n", solong->width,
	solong->height);
	
	ft_map_to_2d(solong);
	ft_init_map(solong);
//------------------------
	solong->mlx = mlx_init(solong->window_width, solong->window_height, solong->name, true);
	if (solong->mlx == NULL)
		ft_error();
	solong->texture = mlx_load_png(GRASS);
	if (solong->texture == NULL)
		ft_error();
	solong->mlx_img = mlx_texture_to_image(solong->mlx, solong->texture);
	if (solong->mlx_img == NULL)
		ft_error();
	if (mlx_image_to_window(solong->mlx, solong->mlx_img, 0, 0) < 0)
		ft_error();
	mlx_loop(solong->mlx);
}
