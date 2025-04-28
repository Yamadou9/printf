#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

int	ft_putnbr(long long n, int count)
{
	char	d;

	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775808", 20);
		count += 20;
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = n * -1;
	}
	if (n < 10)
	{
		d = n + 48;
		write(1, &d, 1);
		count++;
	}
	else
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	return (count);
}

/*int	main(int ac, char **av)
{
	int	fd;
	int	n;

	fd = open(av[2], O_WRONLY);
	printf("%d", fd);
	n = atoi(av[1]);	
	ft_putnbr_fd(n, fd);
}*/
