#include "../include/so_long.h"

/*void	ft_map_to_screen(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= solong->window_width && j < solong->window_height)
	{
		if (i == solong->window_width)
		{
			j += IMG_SIZE;
			i = 0;
		}
		if (j == solong->window_height)
			break ;
		mlx_image_to_window(solong->mlx, solong->img.img_floor, i, j);
		i += IMG_SIZE;
	}
	mlx_loop(solong->mlx);
}

int win_card_game(t_data *data)
{
	if (solong->content.exit_win == 1)
	{

	    printf("\x1b[32;5;1m"); // 32 pour vert, 5 pour effet clignotant, 1 pour intensité maximale
	    printf("YOU WIN !!\n");
	    printf("\x1b[0m"); // 0 pour réinitialiser tout
		collapse_img(data);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void collect_pot (t_data *data, char cardinal)
{
	if ((cardinal == KEY_UP || cardinal =='w')
		 && solong->map.map[solong->map.player_y - 1][solong->map.player_x] == solong->content.collect
		|| (cardinal == KEY_DOWN  || cardinal == 's')
		 && solong->map.map[solong->map.player_y + 1][solong->map.player_x] == solong->content.collect
		|| (cardinal == KEY_RIGHT || cardinal == 'd')
		 && solong->map.map[solong->map.player_y][solong->map.player_x + 1] == solong->content.collect
	 	|| (cardinal == KEY_LEFT  || cardinal == 'a')
	 	 && solong->map.map[solong->map.player_y][solong->map.player_x - 1] == solong->content.collect)
	 {
	 	solong->content.collected++;
	 	printf("valeur collect --%d-- valeur compte de collect -%d---\n", solong->content.collected, solong->content.count_e);
	 }
}

void card_path (t_data *data, char cardinal)
{
	if (pull_next_card(data, cardinal, solong->content.wall) == SUCCESS
		|| (solong->content.exit_win == 0
		&& pull_next_card(data, cardinal, solong->content.exit) == SUCCESS))
		return ;
	solong->map.count++;;
	collect_pot(data, cardinal);
	if (solong->content.collected == solong->content.count_c)
		solong->content.exit_win = 1;
	solong->map.map[solong->map.player_y][solong->map.player_x] = solong->content.floor;
	if (cardinal == KEY_UP || cardinal == 'w')
		solong->map.player_y--;
	else if (cardinal == KEY_DOWN || cardinal == 's')
		solong->map.player_y++;
	else if (cardinal == KEY_RIGHT || cardinal == 'd')
		solong->map.player_x++;
	else if (cardinal == KEY_LEFT || cardinal =='a')
		solong->map.player_x--;

	if (solong->content.exit_win == 1 && solong->map.map[solong->map.player_y][solong->map.player_x] == solong->content.exit)
		win_card_game(data);
	solong->map.map[solong->map.player_y][solong->map.player_x] = solong->content.player;
}

int pull_next_card(t_data *data, char cardinal, char card)
{
	if (((cardinal == KEY_UP || cardinal == 'w') && solong->map.map[solong->map.player_y - 1][solong->map.player_x] == card) ||
		((cardinal == KEY_DOWN || cardinal == 's') && solong->map.map[solong->map.player_y + 1][solong->map.player_x] == card) ||
		((cardinal == KEY_RIGHT || cardinal == 'd') && solong->map.map[solong->map.player_y][solong->map.player_x + 1] == card) ||
		((cardinal == KEY_LEFT || cardinal == 'a') && solong->map.map[solong->map.player_y][solong->map.player_x - 1] == card))
	{
		return SUCCESS;
	} else
	{
		return FAILURE;
	}
}*/

void	ft_fill_cards(t_solong *solong, int width, int y, int x)
{
	if (solong->map.map[y][x] == solong->content.wall)
		mlx_image_to_window(solong->mlx, solong->img.img_wall, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.floor)
		mlx_image_to_window(solong->mlx, solong->img.img_floor, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.collect)
		mlx_image_to_window(solong->mlx, solong->img.img_collect, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.player)
		mlx_image_to_window(solong->mlx, solong->img.img_player, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.exit)
		mlx_image_to_window(solong->mlx, solong->img.img_exit, width, y * IMG_SIZE);
	else if (solong->map.map[y][x] == solong->content.stone)
		mlx_image_to_window(solong->mlx, solong->img.img_stone, width, y * IMG_SIZE);
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
	 ft_printf("");
	 return (0);
}
/*int is_ther_ny(t_data *data)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (solong->map.map[i]) // Parcours des lignes
    {
        j = 0; // Initialisation de j pour chaque nouvelle ligne
        while(solong->map.map[i][j]) // Parcours des colonnes de la ligne i
        {
            if(solong->map.map[i][j] == solong->content.collect)
                count++;
            j++; // Incrémentation de j pour passer à l'élément suivant dans la ligne
        }
        i++; // Passage à la ligne suivante après avoir terminé la ligne courante
    }
    return (count);
}*/

