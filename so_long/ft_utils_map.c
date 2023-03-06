/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:56:30 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/02 12:56:33 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	horizontalwall(t_game *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (!(game->map[0][j] == '1'
			&& game->map[game->heightmap - 1][j] == '1'))
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	verticalwall(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
		{
			return (0);
		}
		height++;
	}
	return (1);
}
