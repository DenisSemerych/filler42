/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:00:42 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/12/24 05:14:15 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord				*choose_point(t_coord *player, t_coord *opponent, int edge)
{
	t_coord			*chosen;
	t_coord			*crawler;
	int				min;
	int				new_value;

	min = 1000;
	chosen = NULL;
	while (player)
	{
		crawler = opponent;
		while (crawler)
		{
			if ((new_value = ABC(crawler->x - player->x)
						+ ABC(crawler->y - player->y)) < min)
			{
				min = new_value;
				chosen = player;
			}
			crawler = crawler->next;
		}
		player = player->next;
	}
	if (edge)
		free_lst(&opponent);
	return (chosen);
}

int					place_figure(t_game *game, int row, int col, int placed)
{
	int				f_row;
	int				f_col;
	int				contact;

	f_row = -1;
	contact = 0;
	while (++f_row < game->figure_x && f_row + row < game->map_x)
	{
		f_col = -1;
		while (++f_col < game->figure_y && f_col + col < game->map_y)
		{
			if (row + f_row < 0 || col + f_col < 0)
				;
			else if (game->map[row + f_row][col + f_col]
					== OPP_PLAYER(game->player)
					&& game->figure[f_row][f_col] == '*')
				return (0);
			else if (game->map[row + f_row][col + f_col] == game->player
					&& game->figure[f_row][f_col] == '*')
				contact++;
			else if (game->figure[f_row][f_col] == '*')
				placed++;
		}
	}
	return (contact == 1 && placed == (game->figure_size - 1));
}

int					close_to_edge(t_game *game)
{
	int				col;
	int				row;
	int				edge_col;

	if (game->edge)
	{
		col = game->map_y - 5;
		edge_col = game->map_y;
	}
	else
	{
		col = 0;
		edge_col = 5;
	}
	while (col < edge_col)
	{
		row = -1;
		while (++row < game->map_x)
			if (game->map[row][col] == game->player)
				return (1);
		col++;
	}
	return (0);
}

t_coord				*move_to_edge(t_coord *coord, t_game *game)
{
	t_coord			*edge;

	if (close_to_edge(game))
		return (NULL);
	edge = (t_coord *)malloc(sizeof(t_coord *));
	if (game->edge == 0)
		edge->y = 0;
	else
		edge->y = game->map_y - 1;
	if (game->map_x > 30)
		(edge->x = game->map_x / 2 - 10);
	else if (game->map_x > 17)
		edge->x = 18;
	else
		edge->x = 6;
	edge->next = NULL;
	return (choose_point(coord, edge, 1));
}

void				make_move(t_game *game)
{
	int				col;
	int				row;
	t_coord			*coord;
	t_coord			*opponent;
	t_coord			*chosen;

	row = -1 - game->figure_x;
	opponent = NULL;
	coord = NULL;
	while (++row < game->map_x)
	{
		col = -1 - game->figure_y;
		while (++col < game->map_y)
		{
			if (place_figure(game, row, col, 0))
				add_new(&coord, initialize_coord(row, col));
			if (row > -1 && col > -1 && game->map[row][col]
					== OPP_PLAYER(game->player))
				add_new(&opponent, initialize_coord(row, col));
		}
	}
	if ((chosen = move_to_edge(coord, game)) ||
			(chosen = choose_point(coord, opponent, 0)))
		assign_coords(chosen, game);
	free_lists(&opponent, &coord);
}
