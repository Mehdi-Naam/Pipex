/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:56:49 by enaam             #+#    #+#             */
/*   Updated: 2023/04/16 23:21:22 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "src/bonus/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define COMMAND_NOT_FOUND 127

# define RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

typedef struct s_pipex
{
	int		fd[2];
	int		fd_inp;
	int		fd_out;
	int		fd_doc;
	int		ac;
	int		i;
	int		proces;
	char	**cmd;
	char	**sp;
	char	**arg;
	char	**av;
	char	**env;
	char	*true_path;
	int		is_doc;
}			t_pipex;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *s, char c);
void		parsing(t_pipex *pipx);
char		*tr_path(t_pipex *pipx, char *arg);
void		ft_path(t_pipex *pipx);
void		ft_putstr(char *s, char *color, int fd);
char		*ft_strdup(char *src);
void		ft_free(char **s);
void		ft_cmd(t_pipex *pipx);
void		ft_execute(t_pipex *pipx);
int			ft_open(char *filename, int flags);
int			ft_strchr(char *s, char c);
void		ft_dup2(int i, int fd);
void		*ft_malloc(int size);
void		ft_close(int fd);

#endif