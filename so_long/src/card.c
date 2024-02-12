#include "../include/so_long.h"

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

int	ft_win_card_game(t_solong *solong)
{
	if (solong->content.exit_win == 1)
	{

		ft_printf("\x1b[32;5;1m"); // 32 pour vert, 5 pour effet clignotant, 1 pour intensité maximale
		ft_printf("\n  YOU WIN !\n");
		ft_printf("\x1b[0m"); // 0 pour réinitialiser tout
		ft_collapse_img(solong);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

void	ft_collect_pot(t_solong *solong, char movement)
{
	if (((movement =='w') && solong->map.map[solong->map.player_y -
	1][solong->map.player_x] == solong->content.collect) ||
	((movement == 's') && solong->map.map[solong->map.player_y +
	1][solong->map.player_x] == solong->content.collect) ||
	((movement == 'd') &&
	solong->map.map[solong->map.player_y][solong->map.player_x + 1]
	== solong->content.collect) || ((movement == 'a') &&
	solong->map.map[solong->map.player_y][solong->map.player_x - 1]
	== solong->content.collect))
	 {
	 	solong->content.count_c--;
		solong->content.collected++;
	 }
}

int	ft_pull_next_card(t_solong *solong, char movement, char card)
{
	if ((movement == 'w' && solong->map.map[solong->map.player_y - 1][solong->map.player_x] == card) || (movement == 's' && solong->map.map[solong->map.player_y + 1][solong->map.player_x] == card) || (movement == 'd' && solong->map.map[solong->map.player_y][solong->map.player_x + 1] == card) || (movement == 'a' && solong->map.map[solong->map.player_y][solong->map.player_x - 1] == card))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	ft_card_path(t_solong *solong, char movement)
{
	if (ft_pull_next_card(solong, movement, solong->content.wall) == SUCCESS ||
        ft_pull_next_card(solong, movement, solong->content.stone) == SUCCESS ||
        (solong->content.exit_win == 0 &&
        ft_pull_next_card(solong, movement, solong->content.exit) == SUCCESS))
        return ;
	solong->map.count++;
	ft_collect_pot(solong, movement);
	if (solong->content.collected == solong->content.count_c)
		solong->content.exit_win = 1;
	solong->map.map[solong->map.player_y][solong->map.player_x] = solong->content.floor;
	if (movement == 'w')
		solong->map.player_y--;
	else if (movement == 's')
		solong->map.player_y++;
	else if (movement == 'd')
		solong->map.player_x++;
	else if (movement =='a')
		solong->map.player_x--;
	if (solong->content.exit_win == 1 && solong->map.map[solong->map.player_y][solong->map.player_x] == solong->content.exit)
		ft_win_card_game(solong);
	solong->map.map[solong->map.player_y][solong->map.player_x] = solong->content.player;
	ft_dispatch_cards(solong);
}

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
