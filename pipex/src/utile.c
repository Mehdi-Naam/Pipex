/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaam <enaam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:53:42 by enaam             #+#    #+#             */
/*   Updated: 2023/04/15 17:38:41 by enaam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = ft_malloc((len1 + 1) + (len2 + 1));
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i] = s2[j++];
		i++;
	}
	dst[i] = '\0';
	free(s1);
	return (dst);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s2)
		return (0);
	while (n > i && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = ft_strlen(src);
	dst = ft_malloc(len + 1);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_putstr(char *s, char *color, int fd)
{
	int	i;

	i = 0;
	if (!color)
	{
		while (s && s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
	{
		ft_putstr(color, NULL, fd);
		ft_putstr(s, NULL, fd);
		ft_putstr(WHITE, NULL, fd);
	}
}
