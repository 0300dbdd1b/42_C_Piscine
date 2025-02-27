/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print-utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:32 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/25 15:53:38 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_printable(char c)
{
	if (!c)
		return (0);
	if (!(c <= 127 && c >= 32))
		return (0);
	return (1);
}

void	ft_putstr_fd(char *str, int fd)
{
	unsigned int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long long int	nb_cpy;
	char			c;

	nb_cpy = nb;
	if (nb_cpy < 0)
	{
		write(1, "-", 1);
		nb_cpy = nb_cpy * (-1);
	}
	if (nb_cpy >= 10)
	{
		ft_putnbr_fd(nb_cpy / 10, fd);
		ft_putnbr_fd(nb_cpy % 10, fd);
	}
	else
	{
		c = nb_cpy + '0';
		write(1, &c, 1);
	}
}

void	print_map_params(t_map *map)
{
	ft_putstr_fd("(empty character) = ", 1);
	write(1, &map->empty_char, 1);
	ft_putstr_fd("\n(obstacle character) = ", 1);
	write(1, &map->obstacle_char, 1);
	ft_putstr_fd("\n(full character) = ", 1);
	write(1, &map->full_char, 1);
	ft_putstr_fd("\n(map height) = ", 1);
	ft_putnbr_fd(map->height, 1);
	ft_putstr_fd("\n(map width) = ", 1);
	ft_putnbr_fd(map->width, 1);
	write(1, "\n", 1);
}
