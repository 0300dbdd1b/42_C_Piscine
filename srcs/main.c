/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:58:51 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 19:58:52 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	handle_stdin(void)
{
	t_map	*map;

	map = create_map();
	take_input_from_stdin(map);
	if (!map || !map->is_valid)
	{
		ft_putstr_fd("map error\n", STDERR_FILENO);
		free_map(map);
	}
	else
		ft_bsq(map);
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	if (argc == 1)
		handle_stdin();
	else
	{
		while (i < argc)
		{
			map = get_map(argv[i]);
			if (!map || !map->is_valid)
			{
				ft_putstr_fd("map error\n", STDERR_FILENO);
				free_map(map);
			}
			else
				ft_bsq(map);
			i++;
		}
	}
}
