/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:51:10 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/20 17:45:03 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_image_to_map(t_mlx *m, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			mlx_put_image_to_window(m->mlx, m->win,
				m->img[(int)tab[i][j]], j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	find_exit_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->e_col = j;
				data->e_row = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_collectible(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->to_collect = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->to_collect += 1;
			j++;
		}
		i++;
	}
}

int	free_print_error(char **tab, char *to_print)
{
	ft_freetab(tab);
	ft_printf("Error\n%s\n", to_print);
	return (0);
}
