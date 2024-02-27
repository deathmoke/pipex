/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utilis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:23:26 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:23:26 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if ((!s1 && !s2) || (s1 == NULL && s2 == NULL))
	{
		str = NULL;
		return (str);
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[j + i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	close_pipes_end(t_pipx *pipes)
{
	int	i;

	i = -1;
	while (++i < pipes->size - 2)
	{
		close(pipes->pipes[i][0]);
		close(pipes->pipes[i][1]);
	}
	return (0);
}

int	close_pipes(t_pipx *pipes, int current)
{
	int	i;

	i = -1;
	while (++i < current - 1)
	{
		close(pipes->pipes[i][0]);
		close(pipes->pipes[i][1]);
	}
	return (0);
}
