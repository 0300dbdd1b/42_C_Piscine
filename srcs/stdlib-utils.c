/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaddino <noaddino@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:54:39 by noaddino          #+#    #+#             */
/*   Updated: 2025/02/26 18:57:36 by noaddino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlen_till_charset(char *str, char *charset)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !is_in_charset(str[i], charset))
		i++;
	return (i);
}

int	ft_atoin(const char *str, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] >= '0' && str[i] <= '9') && (i < size))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
