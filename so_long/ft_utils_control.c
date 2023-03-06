/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:32:29 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/06 10:32:31 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_utils_right(t_game *game)
{
	ft_printf("\nYou lose!\n");
	exit_game(game);
}

int	ft_right_move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou Have Won!!! \n");
		exit_game(game);
	}
	if (game->map[j][i] == 'F')
		ft_utils_right(game);
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}
