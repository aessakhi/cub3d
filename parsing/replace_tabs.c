/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:46:58 by aessakhi          #+#    #+#             */
/*   Updated: 2022/09/15 17:47:17 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	replace_tab_by_spaces_loop(char *str, char *result, t_tab_check *tab)
{
	if (str[tab->i] != '\t')
	{
		result[tab->j] = str[tab->i];
		tab->i++;
		tab->j++;
	}
	else
	{
		tab->x = tab->j + 4;
		while (tab->j < tab->x)
		{
			result[tab->j] = ' ';
			tab->j++;
		}
		tab->i++;
	}
}

char	*replace_tab_by_spaces(char	*str)
{
	char	*result;
	t_tab_check	tab;
	int		n_of_tabs;

	tab.i = 0;
	tab.j = 0;
	tab.x = 0;
	if (!isins(str, '\t'))
		return (str);
	n_of_tabs = count_n_of_tabs(str);
	result = malloc(sizeof(char) * (ft_strlen(str) - n_of_tabs + (n_of_tabs * 4) + 1));
	while (str[tab.i])
		replace_tab_by_spaces_loop(str, result, &tab);
	result[tab.j] = '\0';
	free(str);
	return (result);
}

int	count_n_of_tabs(char	*str)
{
	int	i;
	int	n_of_tabs;

	i = 0;
	n_of_tabs = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			n_of_tabs++;
		i++;
	}
	return (n_of_tabs);
}
