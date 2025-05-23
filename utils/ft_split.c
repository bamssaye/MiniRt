/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:14:20 by bamssaye          #+#    #+#             */
/*   Updated: 2025/02/07 02:14:33 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_freespace(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(str[i++]);
	free(str);
	return (NULL);
}

static char	*ft_setword(char *stri, char const *s, int j, int wordlen)
{
	int	i;

	i = 0;
	while (wordlen > 0)
	{
		stri[i] = s[j - wordlen];
		i++;
		wordlen--;
	}
	stri[i] = '\0';
	return (stri);
}

static char	**ft_splitall(char **str, char const *s, char c, int countword)
{
	int	i;
	int	j;
	int	wordlen;

	i = 0;
	j = 0;
	while (s[i] && j < countword)
	{
		wordlen = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			wordlen++;
		}
		str[j] = malloc((wordlen + 1) * sizeof(char));
		if (!str[j])
			return (ft_freespace(str, countword));
		ft_setword(str[j], s, i, wordlen);
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		countword;
	char	**str;

	if (!s)
		return (NULL);
	countword = ft_wordcount(s, c);
	str = malloc((countword + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	ft_splitall(str, s, c, countword);
	return (str);
}
