/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:03:58 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/10 17:07:07 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_tab(char **tab, int count)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	while (x < count)
	{
		y = 0;
		while (y < count - 1)
		{
			if (ft_strcmp(tab[y], tab[y + 1]) > 0)
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	argv++;
	argc--;
	ft_sort_tab(argv, argc);
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}
