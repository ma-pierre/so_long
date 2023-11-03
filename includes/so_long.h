/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:37:21 by mapierre          #+#    #+#             */
/*   Updated: 2023/07/20 17:49:30 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"

# define ACERROR "Wrong number of arguments !\n"
# define EXTERROR "Wrong extension !\n"
# define MALLOCERROR "Malloc error !\n"
# define FILEERROR "Wrong file !\n"
# define RECTERROR "The map is not a rectangle"
# define WALLERROR "Missing walls"
# define ITEMERROR "Invalid items / Missing items"
# define COLLECERROR "Player can't collect all items"
# define IMGERROR "Error, image initialisation"

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
	void	*img[256];

}			t_mlx;

typedef struct t_data
{
	char	**map;
	int		col_size;
	int		row_size;
	int		p_col;
	int		p_row;
	int		e_col;
	int		e_row;
	int		collected;
	int		to_collect;
	char	**visited;
	int		exit;
	int		count_move;

	t_mlx	*mlx;
}			t_data;

int			parsing(t_data *data, char *av_map);
int			checkber(char *av_map);
int			read_map(char *av_map, t_data *data);
int			map_is_rec(t_data *data);
int			map_have_wall(char **tab, t_data *data);
int			free_print_error(char **tab, char *to_print);
int			map_has_items(t_data *data);
int			count_items(t_data *data, char c);
void		find_player_pos(char **tab, t_data *data);
char		**dup_empty_map(int i, int j);
int			valid_way(char **tab, char **visited, int v_row, int v_col);
int			can_collect_all_items(char **tab, char **visited);
int			move(int key, t_data *data);
void		set_image_to_map(t_mlx *mlx, char **tab);
void		count_collectible(t_data *data);
void		find_exit_pos(t_data *data);
void		move_down(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		move_up(t_data *data);
void		ft_freetab(char **tab);
void		destroy(t_data *data);
int			free_error_init(t_mlx *mlx, t_data *data, int i);
int			init_images(t_mlx *mlx, t_data *data);
#endif