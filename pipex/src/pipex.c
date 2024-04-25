/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:10:18 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/05 16:45:52 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int	ft_execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = ft_get_path(cmd[0], envp);
	if (!path)
	{
		ft_free_array(cmd);
		ft_error();
	}
	if (execve(path, cmd, envp) == -1)
		ft_error();
	return (0);
}

int	ft_parent_process(char **argv, char **envp, int *pipe_fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_error();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	ft_execute_cmd(argv[3], envp);
	return (0);
}

int	ft_child_process(char **argv, char **envp, int *pipe_fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_error();
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(pipe_fd[0]);
	ft_execute_cmd(argv[2], envp);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			ft_error();
		pid = fork();
		if (pid == -1)
			ft_error();
		if (pid == 0)
			ft_child_process(argv, envp, pipe_fd);
		waitpid(pid, NULL, 0);
		ft_parent_process(argv, envp, pipe_fd);
	}
	else
		ft_exit();
	return (0);
}
