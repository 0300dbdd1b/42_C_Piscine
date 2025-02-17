/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:17:54 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/04 22:18:27 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	x;
	int	y;
	int	tmp;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - 1)
		{
			if (tab[y] > tab[y + 1])
			{
				tmp = tab[y];
				tab[y] = tab[y + 1];
				tab[y + 1] = tmp;
			}
			y++;
		}
		x++;
	}
}
