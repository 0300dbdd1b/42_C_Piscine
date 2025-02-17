/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:08:31 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/12 14:49:05 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!to_find || !to_find[0])
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && str[i + j])
			j++ ;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++ ;
		j = 0;
	}
	return (NULL);
}
