#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include<stdio.h>

int	ft_putchar(int c, int count);

int	ft_putnbr(long long n, int count)
{
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		count += 20;
		return (count);
	}
	if (n < 0)
	{
		count = ft_putchar('-', count);
		n = n * -1;
	}
	if (n < 10)
		count = ft_putchar(n + 48, count);
	else
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	return (count);
}

// int	main(int ac, char **av)
// {
// 	int	fd;
// 	int	n;

// 	n = atoi(av[1]);	
// 	ft_putnbr(n, fd);
// }
