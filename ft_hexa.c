/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <ydembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:25:08 by ydembele          #+#    #+#             */
/*   Updated: 2025/05/06 15:37:58 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int	ft_putchar(char c, int nb);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}



int	ft_itoa(long long nb, char *, int count)
{
	long long	n;
	int			bl;

	
	n = nb;
	bl = ft_strlen(base_to);
	if (n < 0)
	{
		ft_putchar('-', 0);
		n = (n * -1);
	}
	if (n < bl)
	{
		write(1, &base_to[n], 1);
		count++;
	}
	else
	{
		count = ft_itoa(n / bl, base_to, count);
		count = ft_itoa(n % bl, base_to, count);
	}
	return (count);
}

int	ft_itoavoid(void *nb, char *base_to, int count)
{
	long int	n;
	int			bl;

	n = (long int)nb;
	bl = ft_strlen(base_to);
	if (n < 0)
	{
		ft_putchar('-', 0);
		n = (n * -1);
	}
	if (n < bl)
	{
		write(1, &base_to[n], 1);
		count++;
	}
	else
	{
		count = ft_itoa(n / bl, base_to, count);
		count = ft_itoa(n % bl, base_to, count);
	}
	return (count);
}
