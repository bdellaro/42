#include "../include/so_long.h"

void	ft_init_image(t_solong *solong)
{
	solong->img.img_exit = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_exit);
	solong->img.img_player = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_player);
	solong->img.img_wall = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_wall);
	solong->img.img_collect = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_collect);
	solong->img.img_stone = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_stone);
	solong->img.img_floor = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_floor);
	if (!solong->img.img_floor)
		ft_error_image(GRASS);
	if (!solong->img.img_stone)
		ft_error_image(STONE);
	if (!solong->img.img_exit)
		ft_error_image(EXIT);
	if (!solong->img.img_player)
		ft_error_image(PERSO);
	if (!solong->img.img_wall)
		ft_error_image(WALL);
	if (!solong->img.img_collect)
		ft_error_image(STAR);
}

void	ft_init_map(t_solong *solong)
{
	solong->map.y = 0;
	solong->map.x = 0;
	solong->window_height = solong->map.line_height * IMG_SIZE;
	solong->window_width = solong->map.line_width * IMG_SIZE;
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
			if (solong->map.map[y][x] == solong->content.player)
			{
				solong->content.exit_win = 0;
				solong->map.player_y = y;
				solong->map.player_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_struct_image(t_solong *solong)
{
	solong->tex.tex_floor = mlx_load_png(GRASS);
	solong->tex.tex_stone = mlx_load_png(STONE);
	solong->tex.tex_wall = mlx_load_png(WALL);
	solong->tex.tex_exit = mlx_load_png(EXIT);
	solong->tex.tex_collect = mlx_load_png(STAR);
	solong->tex.tex_player = mlx_load_png(PERSO);
	if (!solong->tex.tex_floor)
		ft_error_image(GRASS);
	if (!solong->tex.tex_stone)
		ft_error_image(STONE);
	if (!solong->tex.tex_exit)
		ft_error_image(EXIT);
	if (!solong->tex.tex_player)
		ft_error_image(PERSO);
	if (!solong->tex.tex_wall)
		ft_error_image(WALL);
	if (!solong->tex.tex_collect)
		ft_error_image(STAR);
}

void	ft_solong_init(char *map, t_solong *solong)
{
	ft_set_clean(solong);
	ft_read_map(map, solong);
	ft_check_content(solong);
	ft_map_to_2d(solong);
	ft_struct_image(solong);
	ft_init_player(solong);
	ft_init_map(solong);
	solong->mlx = mlx_init(solong->window_width, \
	solong->window_height, solong->name, true);
	if (solong->mlx == NULL)
		ft_error();
	ft_init_image(solong);
	ft_write(solong);
	ft_dispatch_cards(solong);
	ft_hook(solong);
	ft_delete_mlx(solong);
}
