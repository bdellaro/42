#include "randomizer.h"

void	ft_regul_print(t_string *string)
{
    int	i = string->count;
    printf("   E ");
    while (--i >= 0)
	printf("-");
    i = string->count;
    printf("\n   B ");
    while (--i >= 0)
	printf("-");
    i = string->count;
    printf("\n   G ");
    while (--i >= 0)
	printf("-");
}

void	ft_print_menu(t_string *string)
{
    int	c;
    printf("Choose your tuning, then press ENTER :\n\n\tPress 'D' for dropped tuning  : DADGBE\n\n\tPress 'E' for standard tuning : EADGBE\n");
    while (1)
    {
	c = getchar();
	while (getchar() != '\n') continue ;
	if (c == 'D' || c == 'd')
	{
	    string->tuner = 'D';
	    break ;
	}
	else if (c == 'E' || c == 'e')
	{
	    string->tuner = 'E';
	    break ;
	}
	else
	    printf("\rInvalid letter. Please press 'D' or 'E'");
    }
}

int	ft_verif(unsigned int nb)
{
    if (nb <= 13)
	return 0;
    return 1;
}

int	ft_create(t_string *string)
{
    int	i = -1;
    while (++i <= 7)
	string->chord[5][i] = ft_random_number();
    i = -1;
    while (++i <= 7)
    {
	if (ft_verif(string->chord[5][i]))
	    return 0;
	else
	   break ;  
    }
    i = -1;
    string->count = 13;
    while (++i <= 3)
    {
	if (string->chord[5][i] > 9)
	    string->count++;
    }
	return 1;
}

int	ft_print(t_string *string)
{
    char c;

    ft_regul_print(string);
    
    printf("\n   D -%u--%u--%u--%u--\n", string->chord[5][0], \
    string->chord[5][1],
    string->chord[5][2], string->chord[5][3]);
    printf("   A -%u--%u--%u--%u--\n", string->chord[5][0], \
    string->chord[5][1], \
    string->chord[5][2], string->chord[5][3]);
    printf("   D -%u--%u--%u--%u--\n", string->chord[5][0], \
    string->chord[5][1], \
    string->chord[5][2], string->chord[5][3]);
    
    printf("\nPress ENTER to generate new line, press 'Q' to quit\n");
    while (1)
    {
	c = getchar();
//	while (getchar() != '\n') continue ;
	if (c == 'q' || c == 'Q')
	{
	    ft_free_array(string->chord);
	    printf("\nProgram exited\n");
	    exit (EXIT_SUCCESS);
	}
	if (c == '\n')
	{
	    if (ft_create(string))
		ft_print(string);
	}
    }
}

int	main(void)
{
    int	i = 0;
    t_string set;
    ft_print_menu(&set);
    
    set.chord = malloc(sizeof(unsigned int *) * 6);
    if (!set.chord)
    {
	printf("Error while allocating chord array");
    }
    while (i < 6)
    {
	set.chord[i] =  malloc(sizeof(unsigned int) * 8);
	if (!set.chord[i])
	{
	    ft_free_array(set.chord);
	    printf("Error while allocating chord array");
	}
	i++;
    }
    srand(time(NULL));
    if (ft_create(&set))
	ft_print(&set);
    return 0;
}
