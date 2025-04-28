/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydembele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:25:08 by ydembele          #+#    #+#             */
/*   Updated: 2025/03/09 18:16:02 by ydembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int	ft_putchar(char c, int nb);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_check_base(char *base)
{
	unsigned int			i;
	unsigned int			count;
	unsigned int			l;

	i = 0;
	while (base[i])
	{
		count = 0;
		l = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[l])
		{
			if (base[i] == base[l])
				count++;
			if (count > 1)
				return (0);
			l++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_itoa(long long nb, char *base_to, int count)
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
