/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kezekiel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:49:23 by kezekiel          #+#    #+#             */
/*   Updated: 2022/10/14 16:49:25 by kezekiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	parse_all(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		throw_error("Error\nCant open a file\n");
	graph_info(fd, &game->graph_info, game->mlx);
	map_info(&game->mapinfo, fd);
	valid_map(&game->mapinfo);
	parse_state(&game->state, &game->mapinfo);
}
