/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:59:40 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/12/23 23:42:00 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			initialize_game(t_game *game)
{
	game->map = NULL;
	game->map_x = 0;
	game->map_y = 0;
	game->figure_y = 0;
	game->figure_x = 0;
	game->figure = NULL;
	game->player = 0;
	game->coord_x = -1;
	game->coord_y = -1;
	game->init = 0;
	game->edge = 0;
}

void			free_game(t_game *game)
{
	free_str_arr(game->figure, game->figure_x);
	free_str_arr(game->map, game->map_x);
	game->coord_x = -1;
	game->coord_y = -1;
	game->figure_y = 0;
	game->figure_x = 0;
}

int				main(void)
{
	t_game		game;

	initialize_game(&game);
	while (1)
	{
		read_info(&game);
		read_map(&game);
		read_figure(&game);
		make_move(&game);
		if (game.coord_x == -1 && game.coord_y == -1)
		{
			system("leaks -q dsemeryc.filler > test");
			ft_printf("%d %d\n", 0, 0);
			return (1);
		}
		ft_printf("%d %d\n", game.coord_x, game.coord_y);
		free_game(&game);
	}
	return (0);
}
