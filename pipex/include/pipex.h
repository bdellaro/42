/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:24:31 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 12:36:39 by bdellaro         ###   ########.fr       */
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

int		ft_free_array(char **array);
char	*ft_get_path(char *cmd, char **envp);
void	ft_exit(void);
void	ft_error(char *str);
void	ft_error_free(char *str, char **array);

#endif
