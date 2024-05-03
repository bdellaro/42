/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:11:35 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/03 12:56:23 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_exit(void)
{
	ft_putstr_fd("4 arguments needed :\n", 2);
	ft_putstr_fd("    ./pipex \033[1;35minfile\033[0m ", 2);
	ft_putstr_fd("\033[1;37mcmd1\033[0m \033[1;37mcmd2\033[0m ", 2);
	ft_putstr_fd("\033[1;35moutfile\033[0m\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error.", 2);
	if (str)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	return (0);
}

char	*ft_get_envp(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	*s_envp;

	i = -1;
	while (envp[++i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		s_envp = ft_substr(envp[i], 0, j);
		if (ft_strncmp(s_envp, cmd, ft_strlen(cmd)) == 0)
		{
			free(s_envp);
			return (envp[i] + j + 1);
		}
		free(s_envp);
	}
	return (0);
}

char	*ft_get_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**all_path;
	char	*part_path;

	i = -1;
	all_path = ft_split(ft_get_envp("PATH", envp), ':');
	while (all_path[++i])
	{
		part_path = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free_array(all_path);
	return (0);
}
