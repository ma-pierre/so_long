/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:03:04 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/20 18:18:14 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, t_data *data)
{
	int	i;
	int	r;

	r = 64;
	i = data->count_move;
	if (key == 65307)
		mlx_loop_end(data->mlx->mlx);
	if (key == 119 && data->map[data->p_row -1][data->p_col] != '1')
		move_up(data);
	if (key == 115 && data->map[data->p_row +1][data->p_col] != '1')
		move_down(data);
	if (key == 97 && data->map[data->p_row][data->p_col -1] != '1')
		move_left(data);
	if (key == 100 && data->map[data->p_row][data->p_col +1] != '1')
		move_right(data);
	if (data->to_collect == data->collected && data->p_row == data->e_row
		&& data->p_col == data->e_col)
		mlx_loop_end(data->mlx->mlx);
	if (i != data->count_move)
		ft_printf("%d\n", data->count_move);
	return (0);
}

void	move_up(t_data *data)
{
	if (data->map[data->p_row -1][data->p_col] == 'C')
	{
		data->collected += 1;
		data->map[data->p_row -1][data->p_col] = '0';
	}
	if (data->p_col == data->e_col && data->p_row == data->e_row)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['E'], data->p_col * 64, data->p_row * 64);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['0'], data->p_col * 64, data->p_row * 64);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img['P'], data->p_col * 64, (data->p_row - 1) * 64);
	data->p_row -= 1;
	data->count_move += 1;
}

void	move_down(t_data *data)
{
	if (data->map[data->p_row +1][data->p_col] == 'C')
	{
		data->collected += 1;
		data->map[data->p_row +1][data->p_col] = '0';
	}
	if (data->p_col == data->e_col && data->p_row == data->e_row)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['E'], data->p_col * 64, data->p_row * 64);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['0'], data->p_col * 64, data->p_row * 64);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img['P'], data->p_col * 64, (data->p_row + 1) * 64);
	data->p_row += 1;
	data->count_move += 1;
}

void	move_left(t_data *data)
{
	if (data->map[data->p_row][data->p_col -1] == 'C')
	{
		data->collected += 1;
		data->map[data->p_row][data->p_col - 1] = '0';
	}
	if (data->p_col == data->e_col && data->p_row == data->e_row)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['E'], data->p_col * 64, data->p_row * 64);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['0'], data->p_col * 64, data->p_row * 64);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img['P'], (data->p_col -1) * 64, data->p_row * 64);
	data->p_col -= 1;
	data->count_move += 1;
}

void	move_right(t_data *data)
{
	if (data->map[data->p_row][data->p_col +1] == 'C')
	{
		data->collected += 1;
		data->map[data->p_row][data->p_col + 1] = '0';
	}
	if (data->p_col == data->e_col && data->p_row == data->e_row)
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['E'], data->p_col * 64, data->p_row * 64);
	else
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			data->mlx->img['0'], data->p_col * 64, data->p_row * 64);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img['P'], (data->p_col +1) * 64, data->p_row * 64);
	data->p_col += 1;
	data->count_move += 1;
}
