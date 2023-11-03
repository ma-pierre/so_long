/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:11:30 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/20 16:35:10 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *av_map, t_data *data)
{
	int		var;
	int		map_fd;
	char	*str;
	char	*tmp;

	map_fd = open(av_map, O_RDONLY);
	if (map_fd == -1)
		return (ft_printf(FILEERROR), 0);
	tmp = NULL;
	var = 0;
	while (1)
	{
		str = get_next_line(map_fd);
		if (!str)
			break ;
		if (str[0] == '\n')
			var = 1;
		tmp = ft_realloc(tmp, str);
		free(str);
	}
	close(map_fd);
	if (var || tmp == NULL || tmp[0] == '\0')
		return (free(tmp), 0);
	data->map = ft_split(tmp, '\n');
	return (free(tmp), 1);
}

int	checkber(char *av_map)
{
	char	*str;

	str = ft_strnstr(av_map, ".ber", ft_strlen(av_map));
	if (ft_strlen(str) != 4 || ft_strlen(av_map) < 5)
		return (ft_printf(EXTERROR), 0);
	return (1);
}

int	parsing(t_data *data, char *av_map)
{
	if (!checkber(av_map))
		return (0);
	read_map(av_map, data);
	if (!data->map)
		return (0);
	data->to_collect = 0;
	if (!map_is_rec(data))
		return (free_print_error(data->map, RECTERROR));
	if (!map_have_wall(data->map, data))
		return (free_print_error(data->map, WALLERROR));
	if (!map_has_items(data))
		return (free_print_error(data->map, ITEMERROR));
	find_player_pos(data->map, data);
	data->visited = dup_empty_map(data->row_size, data->col_size);
	if (!data->visited)
		return (free_print_error(data->map, MALLOCERROR));
	valid_way(data->map, data->visited, data->p_row, data->p_col);
	if (!can_collect_all_items(data->map, data->visited))
		return (ft_freetab(data->visited), free_print_error(data->map,
				COLLECERROR));
	find_exit_pos(data);
	count_collectible(data);
	return (1);
}
