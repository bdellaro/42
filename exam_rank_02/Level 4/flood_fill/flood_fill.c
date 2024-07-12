typedef struct	s_point
{
    int		x;
    int		y;
}	t_point;

void	fill(char **tab, t_point size, t_point cur, char check)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y || tab[cur.y][cur.x] != check)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x + 1, cur.y}, check);
	fill(tab, size, (t_point){cur.x - 1, cur.y}, check);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, check);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, check);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}