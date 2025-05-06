#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_itoa(int n, char *base, int count);
int	ft_putnbr(long long d, int count);
int	ft_itoavoid(void *n, char *base, int count);

int	ft_putstr(char *s, int count)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	count += i;
	return (count);
}

int	ft_putchar(int c, int count)
{
	write(1, &c, 1);
	return(count + 1);
}

typedef struct ft_type
{
	long	d;
	unsigned long long l;
	char *str;
	char c;
	void *v;
} s_point;

int	is_format(char c)
{
	char *format;
	int		i;

	i = 0;
	format = "cspdiuxX";
	while (format[i])
	{
		if (c == format[i])
			return (1);
		i++;
	}
	return (0);
}

int	print_format(va_list ar, int count, char signe)
{
	if ((signe == 's'))
		count = ft_putstr(va_arg(ar, char *), count);
	else if (signe == 'c')
		count = ft_putchar(va_arg(ar, int), count);
	else if (signe == 'd' || signe == 'i' || signe == 'u')
		count = ft_putnbr(va_arg(ar, int), count);
	else if (signe == 'x')
		count = ft_print_hexa(va_arg(ar, unsigned int), count);
	else if (signe == 'X')
		count = ft_print_HEXA(va_arg(ar, unsigned int int), count);
	else if (signe == 'p')
	{
		write(1, "0x", 2);
		count = ft_print_hexa(va_arg(ar, void *), count) + 2;
	}
	else if (signe == '%')
		count = ft_putchar(signe, count);
	else if (signe == '%' && is_format(signe))
		;
	return (count);
}

int	ft_printf(const char	*s, ...)
{
	int			i;
	int			count;
	va_list		ar;

	i = 0;
	count = 0;
	va_start(ar, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			count = printf_format(ar, count, s[i + 1]);
		else if (s[i - 2] == '%' && s[i - 1] == '%' && is_format(s[i]))
			count = ft_putchar(s[i], count);
		else
			count = ft_putchar(s[i], count);
		i++;
	}
	return (count);
}
int	main()
{
	char	*ko;
	char c = 'd';
	unsigned int		n = 0xff;
	char *s;
	int d = -48;

	s = "bonjour";
	ko = "oul";
	ft_printf("%s", s);
}
