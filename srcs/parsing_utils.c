/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:37:54 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/19 20:40:19 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_is_rec(t_data *data)
{
	unsigned long	i;

	i = 1;
	if (ft_str_tab_len(data->map) < 2)
		return (0);
	while (data->map[i] != NULL)
	{
		if (ft_strlen(data->map[0]) != ft_strlen(data->map[i++]))
			return (0);
	}
	if (i >= ft_strlen(data->map[0]))
		return (0);
	return (1);
}

int	map_have_wall(char **tab, t_data *data)
{
	int	i;

	i = 0;
	data->row_size = ft_str_tab_len(data->map);
	data->col_size = ft_strlen(tab[0]);
	while (tab[0][i])
		if (tab[0][i++] != '1')
			return (0);
	i = 0;
	while (tab[data->row_size - 1][i])
		if (tab[data->row_size - 1][i++] != '1')
			return (0);
	i = -1;
	while (tab[++i])
		if (tab[i][0] != '1' || tab[i][data->col_size - 1] != '1')
			return (0);
	return (1);
}

int	count_items(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == c)
				count++;
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'E' && data->map[i][j] != '1'
				&& data->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (count);
}

int	map_has_items(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while ("PEC"[i])
	{
		count = count_items(data, "PEC"[i]);
		if (count == 0 || (i == 0 && count > 1) || (i == 1 && count > 1))
			return (0);
		i++;
	}
	return (1);
}
