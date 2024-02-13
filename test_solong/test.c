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

int	ft_is_movable(t_solong *solong, char movement)
{
	return (ft_pull_next_card(solong, movement, solong->content.wall) == SUCCESS
		|| ft_pull_next_card(solong, movement, solong->content.stone) == SUCCESS
			|| (solong->content.exit_win == 0
				&& ft_pull_next_card(solong, movement, solong->content.exit) == SUCCESS));
}

int	ft_collapse_img(t_solong *solong)
{
	ft_free_solong(solong);
	if (NULL != solong->img.img_wall)
		mlx_delete_image(solong->mlx, solong->img.img_wall);
	if (NULL != solong->img.img_floor)
		mlx_delete_image(solong->mlx, solong->img.img_floor);
	if (NULL != solong->img.img_player)
		mlx_delete_image(solong->mlx, solong->img.img_player);
	if (NULL != solong->img.img_collect)
		mlx_delete_image(solong->mlx, solong->img.img_collect);
	if (NULL != solong->img.img_exit)
		mlx_delete_image(solong->mlx, solong->img.img_exit);
	if (solong->img.img_stone != NULL)
		mlx_delete_image(solong->mlx, solong->img.img_stone);
	ft_delete_mlx(solong);
	return (0);
}

void	ft_collect_pot(t_solong *solong, char movement)
{
	if (((movement =='w')
		&& solong->map.map[solong->map.player_y \
	 - 1][solong->map.player_x] == solong->content.collect)
	 	|| ((movement == 's')
			&& solong->map.map[solong->map.player_y +
	1][solong->map.player_x] == solong->content.collect)
		|| ((movement == 'd')
			&& solong->map.map[solong->map.player_y][solong->map.player_x + 1] == solong->content.collect)
		|| ((movement == 'a')
			&& solong->map.map[solong->map.player_y][solong->map.player_x - 1] == solong->content.collect))
	 {
	 	solong->content.count_c--;
		solong->content.collected++;
	 }
}

void	ft_write(t_solong *solong)
{
	if (solong->content.count_c >= 0)
	{
		ft_printf("Dimensions   : \033[1;37m%d * %d\033[0m\n" \
		, solong->width, solong->height);
		ft_printf("Collectables : \033[1;37m%d\033[0m\n\n" \
		, solong->content.count_c);
	}
}

void	ft_r(void)
{
	int	write_error;

	write_error = write(1, "\r", 1);
	(void)write_error;
}

void	ft_print_map_error(t_solong *solong, int fd)
{
	ft_printf("\n");
	if (solong->height == 0 || solong->total_length == 0)
	{
		ft_printf("Error\nEmpty map\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (solong->height == solong->width)
	{
		ft_printf("Error\nMap is not rectangular");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
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

void	ft_set_clean(t_solong *solong)
{
	solong->height = 0;
	solong->width = 0;
	solong->total_length = 0;
	solong->map.count = 0;
	solong->content.count_key = 0;
	solong->content.collected = 0;
	solong->content.exit_win = 0;
	solong->content.wall = '1';
	solong->content.floor = '0';
	solong->content.player = 'P';
	solong->content.exit = 'E';
	solong->content.stone = 'S';
	solong->content.sl = '\n';
	solong->content.collect = 'C';
	solong->content.count_p = 0;
	solong->content.count_e = 0;
	solong->content.count_c = 0;
	solong = NULL;
}

void	ft_delete_mlx(t_solong *solong)
{
	mlx_delete_texture(solong->tex.tex_wall);
	mlx_delete_texture(solong->tex.tex_stone);
	mlx_delete_texture(solong->tex.tex_exit);
	mlx_delete_texture(solong->tex.tex_player);
	mlx_delete_texture(solong->tex.tex_floor);
	mlx_delete_texture(solong->tex.tex_collect);
	mlx_terminate(solong->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_free_solong(t_solong *solong)
{
	if (solong->data_map != NULL)
	{
		free(solong->data_map);
		solong->data_map = NULL;
	}
}

int	ft_is_content(t_solong *solong, int i)
{
	return (solong->data_map[i] != solong->content.player \
		&& solong->data_map[i] != solong->content.exit \
		&& solong->data_map[i] != solong->content.collect \
		&& solong->data_map[i] != solong->content.wall \
		&& solong->data_map[i] != solong->content.floor \
		&& solong->data_map[i] != solong->content.sl \
		&& solong->data_map[i] != solong->content.stone);
}

void	ft_content_error(t_solong *solong)
{
	if (solong->content.count_p != 1 || \
		solong->content.count_e != 1 \
		|| solong->content.count_c == 0)
	{
		ft_printf("Error\n");
		if (solong->content.count_p != 1)
			ft_printf("Problem with player initialization : \
			%d P\n", solong->content.count_p);
		if (solong->content.count_e != 1)
			ft_printf("Problem with exit initialization : \
			%d E\n", solong->content.count_e);
		if (solong->content.count_c == 0)
			ft_printf("Missing something to collect\n");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
}

void	ft_is_else(t_solong *solong)
{
	solong->content.count_key++;
	ft_printf("		Count -> \033[1;37m[%d]\033[0m" \
	, solong->map.count);
	if (solong->content.count_c < 10)
		ft_printf("	 Left -> \033[1;37m[%d] \
		\033[0m", solong->content.count_c);
	else
		ft_printf("	 Left -> \033[1;37m[%d] \
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
	char	*to_quit;

	how_to = "Use W, A, S, D to move !";
	to_quit = "Press ECHAP to quit game";
	mlx_put_string(solong->mlx, how_to, solong->window_width \
	/ 2 - (ft_strlen(how_to) * 5), solong->window_height / 2 - 10);
	mlx_put_string(solong->mlx, to_quit, solong->window_width \
	/ 2 - (ft_strlen(to_quit) * 5), solong->window_height / 2 + 10);
	mlx_key_hook(solong->mlx, &ft_print_key, solong);
	mlx_loop(solong->mlx);
}


int	ft_win_card_game(t_solong *solong)
{
	if (solong->content.exit_win == 1)
	{
		ft_printf("\033[32;5;1m");
		ft_printf("\n  YOU WIN !\n");
		ft_printf("\033[0m");
		ft_collapse_img(solong);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

int	ft_pull_next_card(t_solong *solong, char movement, char card)
{
	if ((movement == 'w' && \
		solong->map.map[solong->map.player_y - \
	1][solong->map.player_x] == card) || \
	(movement == 's' && \
	solong->map.map[solong->map.player_y +
	1][solong->map.player_x] \
	== card) || (movement == 'd' && \
	solong->map.map[solong->map.player_y][solong->map.player_x + 1] \
	== card) || (movement == 'a' && \
	solong->map.map[solong->map.player_y][solong->map.player_x - 1] \
	== card))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	ft_card_path(t_solong *solong, char movement)
{
	if (ft_is_movable(solong, movement))
		return ;
	solong->map.count++;
	ft_collect_pot(solong, movement);
	if (solong->content.count_c == 0 \
	|| solong->content.collected == solong->content.count_c)
		solong->content.exit_win = 1;
	solong->map.map[solong->map.player_y] \
	[solong->map.player_x] = solong->content.floor;
	if (movement == 'w')
		solong->map.player_y--;
	else if (movement == 's')
		solong->map.player_y++;
	else if (movement == 'd')
		solong->map.player_x++;
	else if (movement == 'a')
		solong->map.player_x--;
	if (solong->content.exit_win == 1
		&& solong->map.map[solong->map.player_y] \
		[solong->map.player_x] == solong->content.exit)
		ft_win_card_game(solong);
	solong->map.map[solong->map.player_y] \
	[solong->map.player_x] = solong->content.player;
	ft_dispatch_cards(solong);
}

void	ft_fill_cards(t_solong *solong, int width, int y, int x)
{
	if (solong->map.map[y][x] == solong->content.wall)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_wall, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.floor)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_floor, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.collect)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_collect, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.player)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_player, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.exit)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_exit, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.stone)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_stone, width, y * IMG_SIZE);
}

int	ft_dispatch_cards(t_solong *solong)
{
	int	width;
	int	y;
	int	x;

	y = 0;
	x = 0;
	width = 0;
	while (solong->map.map[y])
	{
		while (solong->map.map[y][x] && solong->map.map[y][x] != '\0')
		{
			ft_fill_cards(solong, width, y, x);
			width += IMG_SIZE;
			x++;
		}
		x = 0;
		width = 0;
		y++;
	}
	return (0);
}

void	ft_check_vertical_borders(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	j = solong->width - 1;
	while (i < solong->total_length)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nLeft map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
		if (solong->data_map[j] != '1')
		{
			ft_printf("Error\nRight map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		j++;
		i += solong->width;
		j += solong->width;
	}
}

void	ft_check_map_line(t_solong *solong)
{
	int	i;

	i = 0;
	while (i < solong->width)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nSuperior map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = solong->total_length - solong->width;
	while (i < solong->total_length - 1)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nInferior map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_vertical_borders(solong);
}

int	ft_check_error_map(char *data_map, t_set *content, t_solong *solong)
{
	int	i;

	i = 0;
	while (data_map[i] != 0)
	{
		if (content->count_p > 1 || content->count_e > 1)
		{
			ft_printf("Error\nTo much player or to much exit into map\n");
			free(data_map);
			exit(EXIT_FAILURE);
		}
		if (ft_is_content(solong, i))
		{
			ft_printf("Error\nInvalid map\n");
			free(data_map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_map_line(solong);
	return (0);
}

int	ft_check_content(t_solong *solong)
{
	int	i;
	int	map_check;

	i = 0;
	while (solong->data_map[i] != 0)
	{
		if (solong->data_map[i] == solong->content.player)
			solong->content.count_p++;
		if (solong->data_map[i] == solong->content.exit)
			solong->content.count_e++;
		if (solong->data_map[i] == solong->content.collect)
			solong->content.count_c++;
		i++;
	}
	ft_content_error(solong);
	map_check = ft_check_error_map(solong->data_map, \
		&solong->content, solong);
	if (map_check == 0)
		ft_printf("  \033[1;35m[MAP OK]\033[0m\n\n");
	return (0);
}


void	ft_handle_error(t_solong *solong, int fd)
{
	ft_printf("Error\nMap not found");
	ft_free_solong(solong);
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_initialize_solong(t_solong *solong)
{
	solong->height = 0;
	solong->width = 0;
	solong->total_length = 0;
	solong->data_map = malloc(1);
	if (solong->data_map == NULL)
	{
		ft_printf("Error\nMemory allocation failed");
		exit(EXIT_FAILURE);
	}
	solong->data_map[0] = 0;
}

void	ft_read_map_data(int fd, t_solong *solong)
{
	char	*line;
	int		line_length;
	char	*temp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		solong->total_length += line_length;
		if (solong->height == 0)
			solong->width = (line_length - 1);
		temp = solong->data_map;
		solong->data_map = ft_strjoin(solong->data_map, line);
		ft_printf("   %s", line);
		free(temp);
		free(line);
		line = get_next_line(fd);
		solong->height++;
	}
	ft_print_map_error(solong, fd);
}

void	ft_read_map(char *map, t_solong *solong)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_handle_error(solong, fd);
		return ;
	}
	ft_initialize_solong(solong);
	ft_read_map_data(fd, solong);
	close(fd);
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

int	ft_size_of_map(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

void	ft_map_to_2d(t_solong *solong)
{
	int	y;

	y = 0;
	solong->map.map = ft_split(solong->data_map, '\n');
	if (solong->map.map == NULL)
	{
		ft_printf("Error\nProblem while converting map to 2D array");
		exit(EXIT_FAILURE);
	}
	while (solong->map.map[y] != NULL)
	{
		y++;
	}
	solong->map.line_height = ft_size_of_map(solong->map.map);
	solong->map.line_width = (ft_strlen(solong->map.map[0]));
}

void	ft_first_init(char *path, char *upper, char **argv)
{
	t_solong	solong;

	solong.name = upper;
	ft_printf("Map chosen : \033[1;35m%s\033[0m\n\n", upper);
	if (ft_strncmp(argv[1], "./maps/", 8) == 0)
	{
		solong.name = argv[1];
		ft_solong_init(path, &solong);
	}
	else
		ft_solong_init(path, &solong);
	exit(EXIT_SUCCESS);
}

void	ft_error_print(char **argv)
{
	ft_printf("Invalid map name.\n");
	ft_printf("Please enter :\n====>   \033[1;35m%s", argv[0]);
	ft_printf("\033[0m and \033[1;35m./maps/*.ber\033[0m\n");
	ft_printf("Or chose between :\n", argv[0]);
	ft_printf("====>	\033[1;35m%s\033[0m and -> ", argv[0]);
	ft_printf("\033[1;35mSmall\033[0m", argv[0]);
	ft_printf("\n                      -> \033[1;35mBig\033[0m");
	ft_printf("\n                      -> \033[1;35mMedium\033[0m\n");
	exit (EXIT_FAILURE);
}

char	*ft_upper(char *argv)
{
	char	*upper;
	int		i;

	upper = (char *)malloc((ft_strlen(argv) + 1) * sizeof(char));
	if (!upper)
	{
		ft_printf("Error\nMemory allocation failed");
		free(upper);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[i])
	{
		upper[i] = ft_toupper(argv[i]);
		i++;
	}
	upper[i] = 0;
	return (upper);
}

void	ft_map_check(char **argv)
{
	char	*upper;

	if (ft_strnstr(argv[1], "./maps/", 8)
		&& ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_first_init(argv[1], "USER MAP", argv);
	upper = ft_upper(argv[1]);
	if ((!ft_strncmp(upper, "SMALL", 5))
		&& (!ft_strncmp(upper, "SMALL", 6)) != 0)
		ft_printf("Ok argv");
//		ft_first_init(SMALL, upper, argv);
	if ((!ft_strncmp(upper, "MEDIUM", 6))
		&& (!ft_strncmp(upper, "MEDIUM", 7)) != 0)
		ft_first_init(MEDIUM, upper, argv);
	if ((!ft_strncmp(upper, "BIG", 3))
		&& (!ft_strncmp(upper, "BIG", 4)) != 0)
		ft_first_init(BIG, upper, argv);
	else
		ft_error_print(argv);
	free(upper);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv);
	else
		ft_error_print(argv);
	return (0);
}
