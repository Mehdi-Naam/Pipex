#include "../pipex.h"

void	ft_close(int fd)
{
	if (close(fd))
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}

int	ft_open(char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags, 0644);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_dup2(int i, int fd)
{
	if (dup2(i, fd) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void	*ft_malloc(int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
