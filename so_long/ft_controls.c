/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:50:42 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/02 12:50:44 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_keyboard_s(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 1)
	{
		j++;
		if (game->map[j][i] == '1')
			return (0);
		k = ft_right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	ft_printf("Move: %i\n", game->counter);
	ft_printf("Coin Left: %i\n", game->collectables);
	return (1);
}

static int	ft_keyboard_w(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 13)
	{
		j--;
		if (game->map[j][i] == '1')
			return (0);
		k = ft_right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	ft_printf("Move: %i\n", game->counter);
	ft_printf("Coin Left: %i\n", game->collectables);
	return (1);
}

static int	ft_keyboard_d(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 2)
	{
		i++;
		if (game->map[j][i] == '1')
			return (0);
		k = ft_right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	ft_printf("Move: %i\n", game->counter);
	ft_printf("Coin Left: %i\n", game->collectables);
	return (1);
}

static int	ft_keyboard_a(t_game *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 0)
	{
		i--;
		if (game->map[j][i] == '1')
			return (0);
		k = ft_right_move(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	ft_printf("Move: %i\n", game->counter);
	ft_printf("Coin Left: %i\n", game->collectables);
	return (1);
}

int	ft_controls(int command, t_game *game)
{
	int	works;

	if (command == 53)
		exit_game(game);
	if (command == 13)
		works = ft_keyboard_w(game, command);
	if (command == 1)
		works = ft_keyboard_s(game, command);
	if (command == 0)
		works = ft_keyboard_a(game, command);
	if (command == 2)
		works = ft_keyboard_d(game, command);
	if (works)
	{
		ft_add_graphics(game);
	}
	return (1);
}
