/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemeryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:07:18 by dsemeryc          #+#    #+#             */
/*   Updated: 2018/12/24 05:29:57 by dsemeryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					count_stars(t_game *game)
{
	int				row;
	int				col;
	int				count;

	row = 0;
	count = 0;
	while (row < game->figure_x)
	{
		col = 0;
		while (col < game->figure_y)
		{
			game->figure[row][col] == '*' ? count++ : count;
			col++;
		}
		row++;
	}
	return (count);
}

void				assign_coords(t_coord *chosen, t_game *game)
{
	game->coord_x = chosen->x;
	game->coord_y = chosen->y;
}
