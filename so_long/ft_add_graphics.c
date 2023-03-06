/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:22:50 by jtabilas          #+#    #+#             */
/*   Updated: 2023/02/28 10:22:53 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 64, height * 64);
	game->y_axis = height;
	game->x_axis = width;
}

void	ft_place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 64, height * 64);
	game->collectables++;
}

void	ft_add_img(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"img/ground.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"img/barrier.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"img/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"img/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"img/coin.xpm", &i, &j);
	game->acollectable = mlx_xpm_file_to_image(game->mlxpointer,
			"img/coin1.xpm", &i, &j);
	game->scollectable = mlx_xpm_file_to_image(game->mlxpointer,
			"img/coin.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlxpointer,
			"img/enemy.xpm", &i, &j);
}

void	ft_checked(t_game *game, int height, int width)
{
	while (game->map[height][width])
	{
		if (game->map[height][width] == '1')
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->barrier, width * 64, height * 64);
		if (game->map[height][width] == 'C')
			ft_place_collectable(game, height, width);
		if (game->map[height][width] == 'P')
			ft_place_player(game, height, width);
		if (game->map[height][width] == 'E')
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->exit, width * 64, height * 64);
		if (game->map[height][width] == '0')
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->floor, width * 64, height * 64);
		if (game->map[height][width] == 'F')
			mlx_put_image_to_window(game->mlxpointer,
				game->winpointer, game->enemy, width * 64, height * 64);
		width++;
	}
}

void	ft_add_graphics(t_game *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		ft_checked(game, height, width);
		height++;
	}
}
