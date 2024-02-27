/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:23:16 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:23:16 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H

# define PIPEX_BONUS_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pipx
{
	int		**pipes;
	int		size;
	pid_t	p;
}				t_pipx;

char	*ft_strjoin(char const *s1, char const *s2);
char	**find_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		first(char **argv, char **env, pid_t *pipes);
int		last(char **argv, int ac, char **env, t_pipx *pipes);
char	*try_path(char **strs, char *str);
void	puterror(char *message);
void	clear_before_err(char *msg, char *str, char **strs);
void	free_tab(char **tab);
int		middle(char **argv, char **env, t_pipx *pipes, int current);
void	clear_tabint(char *msg, int **tab, int size);
void	free_tab2(int **tab, int size);
int		close_pipes_end(t_pipx *pipes);
int		close_pipes(t_pipx *pipes, int current);

#endif