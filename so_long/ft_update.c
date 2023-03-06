/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:28:47 by jtabilas          #+#    #+#             */
/*   Updated: 2023/03/01 13:28:49 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	lenght(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = lenght(nb, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--len] = digits[nb % 10];
		else
			str[--len] = digits[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}

static void	ft_collec_anim(t_game *game)
{
	static int	counter;

	if (counter == 30)
		game->collectable = game->scollectable;
	else if (counter >= 60)
	{
		game->collectable = game->acollectable;
		counter = 0;
	}
	ft_add_graphics(game);
	counter += 1;
}

int	ft_update(t_game *game)
{
	char	*mo;

	mo = ft_itoa(game->counter);
	ft_collec_anim(game);
	mlx_string_put(game->mlxpointer, game->winpointer,
		10, 10, 0xFFFFFF, "MOVES: ");
	mlx_string_put(game->mlxpointer, game->winpointer, 60, 10, 0xFFFFFF, mo);
	free(mo);
	return (1);
}
