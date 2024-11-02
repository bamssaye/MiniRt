#include "get_next_line.h"

static void	fri(char **str)
{
	free(*str);
	*str = 0;
}

static char	*line(char **a)
{
	char	*stre;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*a)[i] && (*a)[i] != '\n')
		i++;
	if ((*a)[i] == '\n')
	{
		stre = ft_substr(*a, 0, i + 1);
		tmp = *a;
		*a = ft_strjoin(&(*a)[i + 1], "");
		fri(&tmp);
	}
	else
	{
		stre = ft_strjoin(*a, "");
		fri(a);
	}
	if (*stre == '\0')
		fri(&stre);
	return (stre);
}

static char	*rea_fd_bu(int fd, char **a, char **b)
{
	char	*si;
	ssize_t	r;

	r = 1;
	while (r && !ft_strchr(*a, '\n'))
	{
		r = read(fd, *b, BUFFER_SIZE);
		(*b)[r] = 0;
		si = *a;
		*a = ft_strjoin(*a, *b);
		fri(&si);
	}
	fri(b);
	return (line(a));
}

char	*get_next_line(int fd)
{
	static char	*a = NULL;
	char		*b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = (char *)malloc(BUFFER_SIZE + 1);
	if (!b)
		return (NULL);
	if (read(fd, b, 0) < 0)
	{
		fri(&b);
		fri(&a);
		return (NULL);
	}
	if (!a)
		a = ft_strjoin("", "");
	return (rea_fd_bu(fd, &a, &b));
}