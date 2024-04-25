/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:24:31 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/05 15:24:39 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_pipex
{
	int				fd_in;
	int				fd_out;
	int				*pipe;
	int				*pid;
	int				nb_cmd;
	int				child;
	int				heredoc;
	char			*cmd_option;
	char			*cmd_path;
	char			**argv;
	char			**envp;
}					t_pipex;

int		ft_free_array(char **array);
char	*ft_get_path(char *cmd, char **envp);
void	ft_exit(void);
void	ft_error(void);

#endif
