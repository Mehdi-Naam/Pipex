/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 03:13:43 by enaam             #+#    #+#             */
/*   Updated: 2023/04/17 00:21:22 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	ft_str(char *s1, char *s2)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	while ((s1[i] && s1[i] != '\n') || s2[i])
	{
		if (s1[i] == s2[i])
			flg = 1;
		else
			return (0);
		i++;
	}
	return (flg);
}

void	ft_heredoc(t_pipex *pipx, char *lim)
{
	char	*str;

	pipx->fd_out = ft_open(pipx->av[4], O_RDWR | O_CREAT | O_APPEND);
	pipx->fd_doc = ft_open("tmp", O_RDWR | O_CREAT);
	while (1)
	{
		str = get_next_line(0);
		if (!str || ft_str(str, lim) == 1)
			break ;
		ft_putstr(str, NULL, pipx->fd_doc);
		free(str);
	}
	unlink("tmp");
	pipx->is_doc = 1;
}

int	main(int ac, char **av, char **env)
{
	t_pipex *pipx;

	pipx = ft_malloc(sizeof(t_pipex));
	pipx->ac = ac;
	pipx->av = av;
	pipx->env = env;
	pipx->is_doc = 0;
	if (ft_str(av[1], "heredoc"))
		ft_heredoc(pipx, av[2]);
	else if (!pipx->is_doc)
	{
		pipx->fd_inp = ft_open(av[1], O_RDONLY);
		pipx->fd_out = ft_open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC);
	}
	ft_cmd(pipx);
	ft_execute(pipx);
	ft_free(pipx->cmd);
	free(pipx);
}