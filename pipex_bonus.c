/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:23:07 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:23:07 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execute_firstmiddle(char **env, char **argv, t_pipx *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->size - 1)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (pipe(pipex->pipes[i]) < 0)
			clear_tabint("pipe", pipex->pipes, i);
		pipex->p = fork();
		if (pipex->p < 0)
			clear_tabint("fork", pipex->pipes, i);
		if (pipex->p == 0)
		{
			if (i == 0)
				first(argv, env, pipex->pipes[0]);
			else
				middle(argv, env, pipex, i);
		}
	}
	pipex->pipes[i] = malloc(sizeof(int) * 2);
	if (pipe(pipex->pipes[pipex->size - 1]) < 0)
		clear_tabint("pipe", pipex->pipes, i);
	return (0);
}

int	first(char **argv, char **env, int *pipes)
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
		close(fd);
		close(pipes[1]);
		clear_before_err("execve", str, cmd);
	}
	return (0);
}

int	middle(char **argv, char **env, t_pipx *pipes, int current)
{
	char	*str;
	char	**strs;
	char	**cmd;

	dup2(pipes->pipes[current - 1][0], 0);
	dup2(pipes->pipes[current][1], 1);
	close_pipes(pipes, current);
	cmd = ft_split(argv[current + 2], ' ');
	close(pipes->pipes[current - 1][1]);
	close(pipes->pipes[current][0]);
	strs = find_path(env);
	str = try_path(strs, cmd[0]);
	free_tab(strs);
	if (execve(str, cmd, env) == -1)
	{
		free(str);
		free_tab(cmd);
		puterror("execve");
	}
	return (0);
}

int	last(char **argv, int ac, char **env, t_pipx *pipes)
{
	char	*str;
	char	**strs;
	char	**cmd;
	int		fd;

	if (ac <= 5)
		return (0);
	fd = open(argv[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		puterror("fd");
	cmd = ft_split(argv[ac - 2], ' ');
	dup2(fd, 1);
	dup2(pipes->pipes[pipes->size - 2][0], 0);
	close_pipes_end(pipes);
	close(pipes->pipes[pipes->size - 2][1]);
	strs = find_path(env);
	str = try_path(strs, cmd[0]);
	free_tab(strs);
	if (execve(str, cmd, env) == -1)
	{
		close(fd);
		close(pipes->pipes[pipes->size - 1][0]);
		clear_before_err("execve", str, cmd);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipx	pipex;
	int		i;

	if (argc <= 4)
		return (1);
	pipex.size = argc - 3;
	pipex.pipes = malloc(sizeof(int *) * pipex.size);
	if (pipex.pipes == NULL)
		return (1);
	execute_firstmiddle(env, argv, &pipex);
	last(argv, argc, env, &pipex);
	i = -1;
	while (++i < pipex.size)
		free(pipex.pipes[i]);
	free(pipex.pipes);
	return (0);
}
