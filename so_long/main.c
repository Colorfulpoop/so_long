/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:58:08 by jtabilas          #+#    #+#             */
/*   Updated: 2023/02/23 10:58:12 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	*ft_memmset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_game(t_game *game)
{
	int	line;

	line = 0;
	if (game->mlxpointer)
	{
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	}
	free(game->mlxpointer);
	while (line < game->heightmap - 1)
	{
		free(game->map[line++]);
	}
	free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
	{
		ft_printf("Error! \n");
		return (0);
	}
	ft_memmset(&game, 0, sizeof(t_game));
	ft_read_map(&game, argv);
	ft_check_map(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 64),
			(game.heightmap * 64), "The Escapists42");
	ft_add_img(&game);
	ft_add_graphics(&game);
	mlx_key_hook(game.winpointer, ft_controls, &game);
	mlx_loop_hook(game.mlxpointer, ft_update, (char *) &game);
	mlx_hook(game.winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxpointer);
	return (0);
}
