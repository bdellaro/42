/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:10:18 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/24 11:16:18 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	ft_wait_close(int *pipe_fd, int *pid)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (pid)
	{
		waitpid(pid[0], NULL, 0);
		waitpid(pid[1], NULL, 0);
	}
}

int	ft_execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		ft_error_free(NULL, cmd);
	if (cmd[0][0] == '/')
		path = cmd[0];
	else
		path = ft_get_path(cmd[0], envp);
	if (!path)
	{
		ft_putstr_fd("Error. Command not found : ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		ft_free_array(cmd);
		exit (EXIT_FAILURE);
	}
	if (execve(path, cmd, envp) == -1)
		ft_error_free("Cannot launch command", cmd);
	ft_free_array(cmd);
	return (0);
}

int	ft_command_two(char **argv, char **envp, int *pipe_fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		ft_wait_close(pipe_fd, NULL);
		ft_error("Cannot open outfile");
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	ft_wait_close(pipe_fd, NULL);
	ft_execute_cmd(argv[3], envp);
	exit (0);
}

int	ft_command_one(char **argv, char **envp, int *pipe_fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		ft_wait_close(pipe_fd, NULL);
		ft_error("Cannot open infile");
	}
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(infile);
	ft_wait_close(pipe_fd, NULL);
	ft_execute_cmd(argv[2], envp);
	exit (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	pid[2];

	if (argc == 5)
	{
		if (argv[2][0] == 0 || argv[3][0] == 0)
			ft_putstr_fd("Invalid command\n", 2);
		if (pipe(pipe_fd) == -1)
			ft_error("Cannot open file descriptor");
		pid[0] = fork();
		if (pid[0] == -1)
			ft_error("Unable to fork the first command");
		if (pid[0] == 0)
			ft_command_one(argv, envp, pipe_fd);
		pid[1] = fork();
		if (pid[1] == -1)
			ft_error("Unable to fork the second command");
		if (pid[1] == 0)
			ft_command_two(argv, envp, pipe_fd);
		ft_wait_close(pipe_fd, pid);
	}
	else
		ft_exit();
	return (0);
}
