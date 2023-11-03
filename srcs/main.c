/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:30:16 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/20 17:04:02 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_error_init(t_mlx *mlx, t_data *data, int i)
{	
	int	j;

	j = 0;
	while (j < i)
		mlx_destroy_image(mlx->mlx, mlx->img[(int)"0CPE1"[j++]]);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	ft_freetab(data->map);
	free(mlx->mlx);
	return (0);
}

int	init_images(t_mlx *mlx, t_data *data)
{
	int			i;
	int			r;
	static char	*tab[6] = {"img/sol2.xpm", "img/coin.xpm", "img/perso22.xpm",
		"img/door.xpm", "img/mur.xpm", NULL};

	i = 0;
	while (i < 5)
	{
		mlx->img[(int)"0CPE1"[i]]
			= mlx_xpm_file_to_image(mlx->mlx, tab[i], &r, &r);
		if (!mlx->img[(int)"0CPE1"[i]])
			return (free_error_init(mlx, data, i));
		i++;
	}
	return (1);
}

int	closegame(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	return (0);
}

void	destroy(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(data->mlx->mlx, data->mlx->img[(int)"0CPE1"[i++]]);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	ft_freetab(data->map);
	free(data->mlx->mlx);
}

int	main(int ac, char **av)
{
	static t_data	data = {0};
	static t_mlx	mlx = {0};

	data.mlx = & mlx;
	if (ac != 2)
		return (ft_printf(ACERROR), 0);
	if (!parsing(&data, av[1]))
		return (0);
	find_exit_pos(&data);
	count_collectible(&data);
	data.collected = 0;
	data.count_move = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, data.col_size * 64,
			data.row_size * 64, "Marine's game");
	if (!init_images(&mlx, &data))
		return (ft_printf(IMGERROR), 0);
	mlx_key_hook(mlx.win, move, &data);
	mlx_hook(mlx.win, 17, 0, closegame, &mlx);
	set_image_to_map(&mlx, data.map);
	mlx_loop(mlx.mlx);
	destroy(&data);
	return (0);
}
