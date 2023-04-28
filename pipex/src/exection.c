/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exection.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:34:00 by enaam             #+#    #+#             */
/*   Updated: 2023/04/17 17:46:06 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_execute(t_pipex *pipx)
{
	pipx->i = -1;
	while (pipx->cmd[++pipx->i])
	{
		pipe(pipx->fd);
		pipx->proces = fork();
		if (pipx->proces == 0)
		{
			if ((pipx->i == 0) && !pipx->is_doc)
				ft_dup2(pipx->fd_inp, 0);
			// else if ((pipx->i == 0) && pipx->is_doc)
			// 	ft_dup2(pipx->fd_doc, 0);
			if (pipx->i == (pipx->ac - 5) && pipx->is_doc)
				ft_dup2(pipx->fd_out, 1);
			else if (pipx->i == (pipx->ac - 4))
				ft_dup2(pipx->fd_out, 1);
			else
				ft_dup2(pipx->fd[1], 1);
			parsing(pipx);
		}
		if (pipx->is_doc)
			ft_dup2(pipx->fd_doc, 0);
		else
			ft_dup2(pipx->fd[0], 0);
		ft_close(pipx->fd[1]);
		ft_close(pipx->fd[0]);
	}
	while (wait(NULL) != -1)
		;
}

void	ft_cmd(t_pipex *pipx)
{
	int i;

	i = 0;
	if (!pipx->fd_doc)
	{
		pipx->cmd = ft_malloc((pipx->ac - 2) * sizeof(char *));
		while (i < pipx->ac - 3)
		{
			pipx->cmd[i] = ft_strdup(pipx->av[i + 2]);
			i++;
		}
		pipx->cmd[i] = NULL;
	}
	else if (pipx->fd_doc)
	{
		pipx->cmd = ft_malloc((pipx->ac - 3) * sizeof(char *));
		while (i < pipx->ac - 4)
		{
			pipx->cmd[i] = ft_strdup(pipx->av[i + 3]);
			i++;
		}
		pipx->cmd[i] = NULL;
	}
}