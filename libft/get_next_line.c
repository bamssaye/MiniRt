/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:10:43 by bamssaye          #+#    #+#             */
/*   Updated: 2024/12/28 01:10:00 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getline(char *getline, char *buffer);
static char	*ft_free(char *getline, char **buffer);

static char	*ft_strjoi(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd, char **buffer)
{
	char		*getline;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	getline = ft_calloc(1, sizeof(char));
	if (!getline)
		return (NULL);
	if (!*buffer)
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		getline = ft_strjoi(getline, *buffer);
		if (ft_getline(getline, *buffer))
			return (getline);
		bytes = read(fd, *buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_free(getline, buffer));
		*(buffer+bytes) = 0;
	}
	return (NULL);
}

static int	ft_getline(char *getline, char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (getline[i] && getline[i] != '\n')
		i++;
	if (getline[i] == '\n')
		i++;
	else
		return (0);
	while (getline[i])
		buffer[j++] = getline[i++];
	buffer[j] = '\0';
	getline[i - j] = '\0';
	return (1);
}

static char	*ft_free(char *getline, char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	if (*getline)
		return (getline);
	free(getline);
	return (NULL);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	static char	*buffer;

// 	fd = open("../utils/test.rt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file\n");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd, &buffer);
// 		if (!line)
// 			break;
// 		printf ("Line: %s",line);
// 		free (line);
// 		break;
// 	}
// 	free(buffer);
// 	// free(line);
// 	close (fd);
// 	return (0);
// }