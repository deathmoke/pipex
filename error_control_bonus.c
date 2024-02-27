/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:22:33 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:22:33 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_tab2(int **tab, int size)
{
	int	i;

	i = -1;
	while (i < size)
		free(tab[i]);
	free(tab);
}

void	puterror(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	clear_before_err(char *msg, char *str, char **strs)
{
	free(str);
	free_tab(strs);
	puterror(msg);
}

void	clear_tabint(char *msg, int **tab, int size)
{
	free_tab2(tab, size);
	puterror(msg);
}
