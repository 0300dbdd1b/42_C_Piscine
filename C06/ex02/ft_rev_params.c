/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:13:02 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/10 13:14:44 by noaddino         ###   ########.fr       */
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
	while (argc > 1)
	{
		write(1, argv[argc - 1], ft_strlen(argv[argc - 1]));
		if (argc > 1)
			write(1, "\n", 1);
		argc--;
	}
	return (0);
}
