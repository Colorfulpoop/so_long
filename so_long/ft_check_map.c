/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:15:07 by jtabilas          #+#    #+#             */
/*   Updated: 2023/02/23 11:15:11 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_check_wall(t_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		ft_printf("\nThis map is missing the walls\n");
		exit_game(game);
	}
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != 'F' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError Here! -> %c\n", game->map[height][width]);
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
			game->columncount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	ft_character_valid(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount > 1
			&& game->exitcount == 1))
	{
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("Player, collectable or exit don't exist\n");
		exit_game(game);
	}
}

void	ft_check_map(t_game *game)
{
	ft_check_wall(game);
	ft_character_valid(game);
}
