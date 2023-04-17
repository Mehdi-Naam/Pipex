/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:50:37 by enaam             #+#    #+#             */
/*   Updated: 2023/04/16 16:43:04 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	protection(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr("Only two Args Required..\n", RED, 2);
		exit(EXIT_FAILURE);
	}
	if (!av[1][0] || !av[2][0] || !av[3][0] || !av[4][0])
	{
		ft_putstr(NULL, RED, 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex *pipx;

	protection(ac, av);
	pipx = malloc(sizeof(t_pipex));
	pipx->ac = ac;
	pipx->av = av;
	pipx->env = env;
	pipx->fd_inp = ft_open(av[1], O_RDONLY);
	pipx->fd_out = ft_open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC);
	ft_cmd(pipx);
	ft_execute(pipx);
	ft_free(pipx->cmd);
	free(pipx);
}