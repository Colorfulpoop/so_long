/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtabilas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:14:55 by jtabilas          #+#    #+#             */
/*   Updated: 2023/02/21 14:14:57 by jtabilas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./lib/get_next_line/get_next_line.h"
# include "./lib/ft_printf/ft_printf.h"
# include "./minilibx/mlx.h"

typedef struct s_game
{
	int		heightmap;
	int		widthmap;
	int		fd;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		collectables;
	int		counter;

	char	**map;
	void	*mlxpointer;
	void	*winpointer;
	void	*player;
	void	*enemy;
	void	*floor;
	void	*barrier;
	void	*exit;
	void	*collectable;
	void	*acollectable;
	void	*scollectable;
}	t_game;

int			ft_read_map(t_game *game, char **argv);
int			ft_controls(int command, t_game *game);
int			exit_game(t_game *game);
int			ft_update(t_game *game);
int			ft_right_move(t_game *game, int i, int j);
int			horizontalwall(t_game *game);
int			verticalwall(t_game *game);
void		ft_check_map(t_game *game);
void		ft_add_graphics(t_game *game);
void		ft_add_img(t_game *game);

#endif
