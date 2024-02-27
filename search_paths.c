/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:08 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:24:08 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*join_path(char *path, char *file)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(path, "/");
	str2 = ft_strjoin(str, file);
	free(str);
	return (str2);
}

char	**find_path(char **env)
{
	char	**strs;
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			strs = ft_split(env[i], ':');
		i++;
	}
	tmp = malloc(ft_strlen(strs[0]) - 4);
	i = 4;
	while (strs[0][++i])
		tmp[i - 5] = strs[0][i];
	tmp[i - 5] = '\0';
	free(strs[0]);
	strs[0] = tmp;
	return (strs);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*try_path(char **strs, char *str)
{
	int		i;
	char	*path;

	i = 0;
	while (strs[i])
	{
		path = join_path(strs[i], str);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	puterror("path");
	return (NULL);
}
