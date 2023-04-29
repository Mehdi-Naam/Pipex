/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:56:15 by enaam             #+#    #+#             */
/*   Updated: 2023/04/29 06:49:19 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_path(t_pipex *pipx)
{
	int	i;

	i = 0;
	while (pipx->sp[i])
	{
		pipx->sp[i] = ft_strjoin(pipx->sp[i], "/");
		i++;
	}
}

static char	*tr_path(t_pipex *pipx, char *arg)
{
	int		i;
	char	*tmp;

	i = -1;
	while (pipx->env[++i])
	{
		if (ft_strncmp("PATH=", pipx->env[i], 5))
		{
			pipx->sp = ft_split(pipx->env[i] + 5, ':');
			break ;
		}
	}
	ft_path(pipx);
	i = 0;
	tmp = ft_strjoin(pipx->sp[i], arg);
	while (tmp)
	{
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
		tmp = ft_strjoin(pipx->sp[i], arg);
	}
	return (NULL);
}

void	parsing(t_pipex *pipx)
{
	pipx->arg = ft_split(pipx->cmd[pipx->i], ' ');
	if (!pipx->arg)
		exit(EXIT_FAILURE);
	if (ft_strchr(pipx->arg[0], '/') != 0)
		pipx->true_path = pipx->arg[0];
	else
		pipx->true_path = tr_path(pipx, pipx->arg[0]);
	if (!pipx->true_path)
		exit(0);
	ft_close(pipx->fd[0]);
	ft_close(pipx->fd[1]);
	execve(pipx->true_path, pipx->arg, pipx->env);
	ft_putstr("command not found\n", RED, 2);
	exit(EXIT_FAILURE);
}
