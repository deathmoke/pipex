/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:23:59 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:23:59 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_son(char **argv, char **env, pid_t *pipes)
{
	char	*str;
	char	**strs;
	char	**cmd;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		puterror("fd");
	cmd = ft_split(argv[2], ' ');
	dup2(fd, 0);
	dup2(pipes[1], 1);
	close(pipes[0]);
	strs = find_path(env);
	str = try_path(strs, cmd[0]);
	free_tab(strs);
	if (execve(str, cmd, env) == -1)
	{
		close(pipes[1]);
		close(fd);
		clear_before_err("execve", str, cmd);
	}
	return (0);
}

int	execute_father(char **argv, char **env, int *pipes)
{
	char	*str;
	char	**strs;
	char	**cmd;
	int		fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		puterror("fd");
	cmd = ft_split(argv[3], ' ');
	dup2(fd, 1);
	dup2(pipes[0], 0);
	close(pipes[1]);
	strs = find_path(env);
	str = try_path(strs, cmd[0]);
	free_tab(strs);
	if (execve(str, cmd, env) == -1)
	{
		close(pipes[0]);
		close(fd);
		clear_before_err("execve", str, cmd);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	p;
	int		pipes[2];

	if (argc == 5)
	{
		if (pipe(pipes) < 0)
			puterror("pipe");
		p = fork();
		if (p < 0)
			puterror("fork");
		if (p == 0)
			execute_son(argv, env, pipes);
		else
			execute_father(argv, env, pipes);
	}
	return (0);
}
