/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:25:08 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/13 16:38:56 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (res == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_print_hexa(int nb, int count)
{
	unsigned int			n;
	char					*base_to;

	base_to = ft_strdup("0123456789abcdef");
	if (!base_to)
		return (0);
	n = (unsigned int)nb;
	if (n < 16)
	{
		write(1, &base_to[n], 1);
		count++;
	}
	else
	{
		count = ft_print_hexa(n / 16, count);
		count = ft_print_hexa(n % 16, count);
	}
	free(base_to);
	return (count);
}

int	ft_print_unsig(unsigned long nb, int count)
{
	char					*base_to;

	base_to = ft_strdup("0123456789abcdef");
	if (!base_to)
		return (0);
	if (nb >= 16)
		count = ft_print_unsig(nb / 16, count);
	write(1, &base_to[nb % 16], 1);
	free(base_to);
	return (count + 1);
}

int	ft_print_hexmaj(int nb, int count)
{	
	char			*base_to;
	unsigned int	n;

	base_to = ft_strdup("0123456789ABCDEF");
	if (!base_to)
		return (0);
	n = (unsigned int)nb;
	if (n < 16)
	{
		write(1, &base_to[n], 1);
		count++;
	}
	else
	{
		count = ft_print_hexmaj(n / 16, count);
		count = ft_print_hexmaj(n % 16, count);
	}
	free(base_to);
	return (count);
}

int	ft_print_pointer(void *nb, int count)
{
	unsigned long			n;

	n = (unsigned long)nb;
	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	count = ft_print_unsig(n, count);
	return (count);
}
