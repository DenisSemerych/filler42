/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:00:48 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/12/24 03:26:04 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			init_size(t_game *game, char *line, int mode)
{
	while (line && *line != ' ')
		line++;
	mode == 1 ? (game->map_x = ft_atoi(line)) :
		(game->figure_x = ft_atoi(line));
	line++;
	while (line && *line != ' ')
		line++;
	mode == 1 ? (game->map_y = ft_atoi(line)) :
			(game->figure_y = ft_atoi(line));
}

void			read_figure(t_game *game)
{
	char		*line;
	int			ind;

	ind = -1;
	line = NULL;
	game->figure = (char **)malloc(sizeof(char *) * game->figure_x);
	while (++ind < game->figure_x)
	{
		get_next_line(0, &line);
		game->figure[ind] = ft_strdup(line);
		ft_strdel(&line);
	}
	game->figure_size = count_stars(game);
}

void			find_edge(t_game *game)
{
	int			col;
	int			row;
	int			chk;

	row = -1;
	if (game->init)
		return ;
	chk = 0;
	while (++row < game->map_x)
	{
		col = 0;
		while (col < game->map_y)
		{
			if (game->map[row][col] == OPP_PLAYER(game->player) && (chk = 1))
				break ;
			col++;
		}
		if (chk == 1)
			break ;
	}
	if (col > game->map_y / 2)
		game->edge = 1;
	else
		game->edge = 0;
	game->init = 1;
}

void			read_map(t_game *game)
{
	char		*line;
	int			ind;

	ind = -1;
	while (get_next_line(0, &line) > 0 && ft_strncmp(line, "Plateau", 7))
		ft_strdel(&line);
	if (!ft_strncmp(line, "Plateau", 7))
	{
		init_size(game, line, 1);
		game->map = (char **)malloc(sizeof(char *) * game->map_x);
		ft_strdel(&line);
		if (get_next_line(0, &line) > -1)
			ft_strdel(&line);
	}
	while (get_next_line(0, &line) != -1 && ++ind < game->map_x)
	{
		game->map[ind] = ft_strdup(line + 4);
		ft_strdel(&line);
	}
	if (!ft_strncmp(line, "Piece", 5))
		init_size(game, line, 2);
	find_edge(game);
	ft_strdel(&line);
}

t_game			*read_info(t_game *game)
{
	char		*player_line;

	player_line = NULL;
	while (!game->init && get_next_line(0, &player_line)
			> 0 && (ft_strncmp(player_line, "$$$", 3)))
	{
		if (!ft_strncmp(player_line, "Plateau", 7))
			break ;
		ft_strdel(&player_line);
	}
	if (game->player == 0)
		game->player = (player_line[10] == '1' ? 'O' : 'X');
	ft_strdel(&player_line);
	return (game);
}
