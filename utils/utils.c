/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:39:45 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:20:19 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s2);
	j = 0;
	if (s1[j] == '\0')
		return (0);
	while (s1[j] && j < i)
	{
		if (s1[j] != s2[j])
			return (0);
		j++;
	}
	return (1);
}

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	len;
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (ft_isset(s1[i], set))
		i++;
	if (i == len)
	{
		free(s1);
		return (ft_strdup(""));
	}
	j = ft_strlen(s1) - 1;
	while (ft_isset(s1[j], set))
		j--;
	result = ft_substr(s1, i, j - i + 1);
	free(s1);
	return (result);
}

void	print_int_array(int	*array)
{
	int	i;
	char	*RGB;

	i = 0;
	RGB = "RGB";
	while (RGB[i])
	{
		printf("%c: ", RGB[i]);
		printf("%d\n", array[i]);
		i++;
	}
}
