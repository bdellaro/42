#ifndef RANDOMIZER_H
# define RANDOMIZER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>

typedef struct s_string
{
    unsigned int	**chord;
    char	tuner;
    int			count;
}			t_string;

unsigned int    ft_random_number(void);

#endif
