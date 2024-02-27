/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:24:04 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 11:24:04 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	**find_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	clear_before_err(char *msg, char *str, char **strs);
int		execute_son(char **argv, char **env, pid_t *pipes);
int		execute_father(char **argv, char **env, pid_t *pipes);
char	*try_path(char **strs, char *str);
void	puterror(char *message);
void	free_tab(char **tab);
void	clear_tabint(char *msg, int **tab, int size);
void	free_tab2(int **tab, int size);

#endif
