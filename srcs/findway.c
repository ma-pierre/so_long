/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findway.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:34:12 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/19 23:23:24 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_pos(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				data->p_col = j;
				data->p_row = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**dup_empty_map(int i, int j)
{
	char	**dup;
	int		c;
	int		f;
	int		m;

	c = 0;
	f = 0;
	dup = ft_calloc((i + 1), sizeof(char *));
	if (!dup)
		return (NULL);
	while (c < i)
	{
		m = 0;
		dup[c] = malloc((j + 1) * sizeof(char));
		if (!dup[c])
			return (ft_freetab(dup), NULL);
		while (m < j)
			dup[c][m++] = '0';
		dup[c++][m] = '\0';
	}
	return (dup);
}

int	valid_way(char **tab, char **visited, int v_row, int v_col)
{
	if (v_row <= 0 || v_row >= (int)ft_str_tab_len(tab) - 1 || v_col <= 0
		|| v_col >= (int)ft_strlen(tab[0]) - 1)
		return (0);
	if (tab[v_row][v_col] == '1' || visited[v_row][v_col] == 'V')
		return (0);
	visited[v_row][v_col] = 'V';
	valid_way(tab, visited, v_row - 1, v_col);
	valid_way(tab, visited, v_row + 1, v_col);
	valid_way(tab, visited, v_row, v_col + 1);
	valid_way(tab, visited, v_row, v_col - 1);
	return (0);
}

int	can_collect_all_items(char **tab, char **visited)
{
	int		i;
	int		j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == 'C' || tab[i][j] == 'E') && visited[i][j] != 'V')
				return (0);
			j++;
		}
		i++;
	}
	ft_freetab(visited);
	return (1);
}
