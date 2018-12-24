/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:59:35 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/12/24 04:28:46 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# define OPP_PLAYER(c) (c == 'X' ? 'O' : 'X')
# define ABC(c) (c < 0 ? c * -1 : c)
# include <stdlib.h>
# include <unistd.h>
# include "printf.h"
# include "get_next_line.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_game
{
	char			**map;
	char			**figure;
	char			player;
	int				map_x;
	int				map_y;
	int				figure_x;
	int				figure_y;
	int				coord_x;
	int				coord_y;
	int				init;
	int				edge;
	int				figure_size;
}					t_game;
void				add_new(t_coord **coord, t_coord *elem);
t_coord				*initialize_coord(int x, int y);
void				make_move(t_game *game);
void				read_map(t_game *game);
void				read_figure(t_game *game);
t_game				*read_info(t_game *game);
void				initialize_game(t_game *game);
void				free_str_arr(char **arr, int size);
void				free_game(t_game *game);
void				free_lists(t_coord **lst1, t_coord **lst2);
void				find_edge(t_game *game);
void				free_lst(t_coord **coord);
int					count_stars(t_game *game);
void				assign_coords(t_coord *chosen, t_game *game);
#endif
