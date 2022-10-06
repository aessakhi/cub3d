/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:48:33 by aessakhi          #+#    #+#             */
/*   Updated: 2022/10/04 20:07:44 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	words(char const *s, char *sep)
{
	int	i;
	int	word;
	int	word_count;

	i = 0;
	word = 0;
	word_count = 0;
	while (s[i])
	{
		if (isins(sep, s[i]))
			word = 0;
		if (word == 0 && !isins(sep, s[i]))
		{
			word = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static int	length(char const *s, char *sep, int i)
{
	int	size;

	size = 0;
	while (s[i])
	{
		if (!isins(sep, s[i]))
			size++;
		i++;
	}
	return (size);
}

static char	**free_arrays(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**spl(char const *s, char *sep, char **tab, int x)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (s[++i])
	{
		if (!isins(sep, s[i]))
		{
			if (y == 0)
			{
				tab[x] = malloc(sizeof(char) * length(s, sep, i) + 1);
				if (!(tab[x]))
					free_arrays(tab);
			}
			tab[x][y] = s[i];
			tab[x][++y] = '\0';
		}
		if (isins(sep, s[i]) && y > 0)
		{
			x++;
			y = 0;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char *sep)
{
	char	**tab;
	int		x;

	x = 0;
	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * ((words(s, sep) + 1)));
	if (!tab)
		return (NULL);
	tab = spl(s, sep, tab, x);
	tab[(words(s, sep))] = 0;
	return (tab);
}
