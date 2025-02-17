/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:49:01 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/12 10:50:21 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
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
		ft_putnbr(nb_cpy / 10);
		ft_putnbr(nb_cpy % 10);
	}
	else
	{
		c = nb_cpy + '0';
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
