/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:48:55 by kezekiel          #+#    #+#             */
/*   Updated: 2022/10/14 16:48:57 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, DEF_W, DEF_H, "cub3d");
	draw_game(game);
}
