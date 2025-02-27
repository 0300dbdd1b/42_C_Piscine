/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:54 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 16:07:33 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

int	ft_bsq(t_map *map)
{
	t_solution	solution;

	solution = ft_find_solution(map);
	fill_square(map, solution);
	map->solved_map = ft_strjoin(map->height, map->map, "\n");
	ft_putstr_fd(map->solved_map, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	free_map(map);
	return (0);
}
