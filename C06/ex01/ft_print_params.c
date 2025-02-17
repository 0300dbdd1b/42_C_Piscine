/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:07:09 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/10 13:11:43 by noaddino         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		write(1, argv[i + 1], ft_strlen(argv[i + 1]));
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
