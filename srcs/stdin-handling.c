/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin-handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:49:58 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/26 18:58:06 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_getline(t_stand_input *input)
{
	char	c;
	size_t	i;

	i = 0;
	c = '\0';
	while (c != '\n')
	{
		if (input->used == input->allocated - 1)
			input_realloc(input);
		if (read(0, &c, 1) <= 0)
			break ;
		input->str[input->used] = c;
		input->used++;
	}
	input->str[input->used] = '\0';
}

t_stand_input	*input_init(t_stand_input *input)
{
	input->allocated = BUFFER_SIZE;
	input->used = 0;
	input->str = malloc(BUFFER_SIZE);
	if (!input->str)
		return (NULL);
	return (input);
}

t_stand_input	*input_realloc(t_stand_input *input)
{
	t_stand_input	*p;

	p = input;
	input->str = ft_realloc(p->str, p->allocated, p->allocated + BUFFER_SIZE);
	input->allocated += BUFFER_SIZE;
	return (input);
}

void	take_input_from_stdin(t_map *map)
{
	t_stand_input	input;
	unsigned int	i;

	i = 0;
	input_init(&input);
	ft_getline(&input);
	map->first_line_length = ft_strlen_till_charset(input.str, "\n");
	map->height = ft_atoin(input.str, map->first_line_length - 3);
	if (!map->height)
	{
		map->raw_map_ptr = input.str;
		map->is_valid = 0;
		return ;
	}
	while (i < map->height)
	{
		ft_getline(&input);
		i++;
	}
	input.str[input.used] = '\0';
	map->raw_map = input.str;
	map->raw_map_ptr = map->raw_map;
	get_map_params_from_first_line(map);
	map->map = ft_split(map->raw_map, "\n");
	check_map(map);
}
